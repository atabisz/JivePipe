import { phrases, words, fillers, ingExceptions, type Entry } from "./dictionary";

function escapeRegex(s: string): string {
  return s.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
}

// Preserve case pattern of the original match in the replacement string.
// Handles: lowercase, Title Case, ALL CAPS.
function applyCase(original: string, replacement: string): string {
  if (!original || !replacement) return replacement;

  const letters = original.replace(/[^a-zA-Z]/g, "");
  if (letters.length >= 2 && letters === letters.toUpperCase()) {
    return replacement.toUpperCase();
  }
  if (original[0] >= "A" && original[0] <= "Z") {
    return replacement[0].toUpperCase() + replacement.slice(1);
  }
  return replacement;
}

// Build a single combined regex (longest entries first) so substitutions
// happen in one pass — prevents "hello" → "hey there" → "yo there" cascade.
const allEntries: Entry[] = [...phrases, ...words].sort(
  (a, b) => b.from.length - a.from.length
);
const lookupMap = new Map<string, string>(
  allEntries.map((e) => [e.from.toLowerCase(), e.to])
);
const combinedPattern = new RegExp(
  `\\b(${allEntries.map((e) => escapeRegex(e.from)).join("|")})\\b`,
  "gi"
);

export function translateLine(line: string): string {
  let result = line;

  // Phase 1+2: single-pass phrase and word substitution (no cascade)
  result = result.replace(combinedPattern, (match) => {
    const replacement = lookupMap.get(match.toLowerCase());
    return replacement ? applyCase(match, replacement) : match;
  });

  // Phase 3: drop the 'g' from -ing endings (verbal forms only)
  result = result.replace(/\b(\w+?)ing\b/gi, (match, stem: string) => {
    if (ingExceptions.has(match.toLowerCase())) return match;
    if (stem.length < 2) return match;
    return applyCase(match, stem + "in'");
  });

  // Phase 4: inject filler phrase at end of non-empty lines
  const FILLER_PROBABILITY = 0.2;
  if (result.trim().length > 10 && Math.random() < FILLER_PROBABILITY) {
    const filler = fillers[Math.floor(Math.random() * fillers.length)];
    result = result.trimEnd().replace(/[.!?]+$/, "") + filler;
  }

  return result;
}
