# JivePipe

## What This Is

JivePipe (`jive`) is a C command-line tool that translates standard English text into authentic Harlem Jive slang (1928–1952). It reads from stdin or a file and writes translated text to stdout, making it trivially pipeable with any Unix command. The tool uses a four-phase pipeline: phrase substitution → word substitution → g-dropping (-ing → -in') → filler injection.

## Core Value

Any text piped through `jive` should produce output that a 1940s Harlem jazz musician would recognize as authentic — not parody, not Hollywood, not anachronistic AAVE.

## Current Milestone: v1.0 Authentic Jive Implementation

**Goal:** Bring jivepipe's dictionary into full alignment with JIVE.md — fix anachronistic entries, expand vocabulary from primary sources, and implement Tier 1 grammatical rules.

**Target features:**
- Fix 14 inauthentic/anachronistic dictionary entries
- Add 26+ authentic vocabulary entries from Gap Analysis
- Implement Tier 1 grammatical rules (existential "it", completive "done", contraction table)
- Fix filler list (remove modern AAVE, add era-authentic replacements)

## Requirements

### Validated

**Dictionary Corrections (Phase 1 — validated 2026-04-20):**
- [x] DICT-01: `buddy` maps to `ace` (not `homeboy`)
- [x] DICT-02: `, feel me?` filler removed; FILL-01/FILL-02 governs replacement
- [x] DICT-03: `always` maps to `from sun up to sun down`
- [x] DICT-04: `actually` maps to `no jive`
- [x] DICT-05: `basically` maps to `dig this`
- [x] DICT-06: `new` maps to `fresh out the box`
- [x] DICT-07: `wonderful` maps to `the most`
- [x] DICT-08: `heart` maps to `ticker`
- [x] DICT-09: `head` maps to `wig`
- [x] DICT-10: `store` maps to `the commissary`
- [x] DICT-11: `school` maps to `the knowledge mill`
- [x] DICT-12: `rules` maps to `the straight-up code`
- [x] DICT-13: `small` maps to `lightweight`
- [x] DICT-14: `ugly` maps to `a real drag`

**Filler Quality (Phase 1 — validated 2026-04-20):**
- [x] FILL-01: `, feel me?` removed from filler list
- [x] FILL-02: 3 era-authentic fillers added (`— you hip to that?`, `, Jack`, `— that's the lick`)

**Vocabulary Expansion (Phase 2 — validated 2026-04-20):**
- [x] VOC-01: Verb entries added (scoff, lamp, knock, collar, hip v., kill, truck, fall in, fall out)
- [x] VOC-02: Noun entries added (killer-diller, solid sender, sky piece, short, scratch, kicks, stud, a hummer)
- [x] VOC-03: Adjective entries added (icky, mellow, a hummer/exceptional)
- [x] VOC-04: Social stratification terms added (dicty, hincty — ofay/gray deferred per D-06)

### Active

**Grammatical Rules:**
- [ ] GRAM-01: Existential "it" substitutions implemented
- [ ] GRAM-02: Completive "done" phrase substitutions implemented
- [ ] GRAM-03: Contraction table phrase entries implemented

### Out of Scope

| Feature | Reason |
|---------|--------|
| Tier 2/3 grammatical rules (copula deletion, habitual be, negative inversion) | Requires POS tagging or parse tree — beyond jivepipe's string-substitution architecture |
| Prosodic/rhythmic filler placement | Would require sentence parser; current append-to-end is sufficient approximation |
| Command-line flags for dialect era or register | User asked for no-flags-needed; JIVE.md documents variation but tool targets Performed Jive register |
| Drug vocabulary sub-lexicon | General-audience tool; historically accurate but omitted by design |

## Context

- Language: C, compiled to a ~35KB binary
- Build: Makefile + GitHub Actions (produces .deb package)
- Architecture: 4-phase pipeline in `translator.c`, dictionary in `dictionary.h` (header-only)
- Language reference: `JIVE.md` in repo root (comprehensive, primary-source-backed)
- Primary sources: Calloway 1938/1944 [C], Burley 1944 [B], Mezzrow 1946 [M]
- All changes are to `src/dictionary.h` — no binary or build changes needed

## Constraints

- **Tech stack**: Pure C, no dependencies — dictionary changes are string arrays only
- **No new flags**: User explicitly wants `echo "text" | jive` to work without options
- **Era accuracy**: 1928–1952 only — no post-period vocabulary, per JIVE.md Authenticity Guidelines
- **Primary sources**: All new entries must be attested in [C], [B], [M], or [G] per JIVE.md

## Key Decisions

| Decision | Rationale | Outcome |
|----------|-----------|---------|
| Header-only dictionary | All translations are static string tables; no runtime loading needed | ✓ Good |
| Phrase-before-word ordering | Longest-match-wins prevents double substitution artifacts | ✓ Good |
| ~20% filler rate via rand() | Simple approximation; authentic density varies by speaker | — Pending |
| Tier 1 rules only this milestone | Parse-tree rules (copula deletion, habitual be) need more than string substitution | — Pending |

## Evolution

This document evolves at phase transitions and milestone boundaries.

**After each phase transition** (via `/gsd-transition`):
1. Requirements invalidated? → Move to Out of Scope with reason
2. Requirements validated? → Move to Validated with phase reference
3. New requirements emerged? → Add to Active
4. Decisions to log? → Add to Key Decisions
5. "What This Is" still accurate? → Update if drifted

**After each milestone** (via `/gsd-complete-milestone`):
1. Full review of all sections
2. Core Value check — still the right priority?
3. Audit Out of Scope — reasons still valid?
4. Update Context with current state

---
*Last updated: 2026-04-20 after Phase 2 completion (Vocabulary Expansion)*
