---
phase: 01-dictionary-corrections-filler-quality
reviewed: 2026-04-20T00:00:00Z
depth: standard
files_reviewed: 1
files_reviewed_list:
  - src/dictionary.h
findings:
  critical: 0
  warning: 1
  info: 2
  total: 3
status: issues_found
---

# Phase 1: Code Review Report

**Reviewed:** 2026-04-20
**Depth:** standard
**Files Reviewed:** 1
**Status:** issues_found

## Summary

Reviewed `src/dictionary.h` covering the 13 word-entry corrections in `words[]` and the 3 filler additions plus 1 filler removal in `fillers[]`. All 13 planned corrections are present and match the expected values from the phase plan. The filler array now contains exactly 13 entries with consistent em-dash UTF-8 encoding (`\xe2\x80\x94`) and correct comma-prefix formatting throughout.

One warning was found: five `to` values in `words[]` contain `-ing` words that are not listed in `ing_exceptions[]`, meaning Phase 3 of the translator (`translate_line`) will incorrectly contract them to `-in'`. Four of these five cases (`"cooking with gas"`, `"dragging"`, `"rolling in bread"`, `"hurting for bread"`) are pre-existing and were not introduced or worsened by Phase 1. The fifth — `"fresh out the box"` — is a net improvement because Phase 1 replaced `"brand-spanking"` (which also had a rogue `-ing` word, `"spanking"`) with `"fresh out the box"` (which has none). No `-ing` regressions were introduced.

Two info items are noted: a misplaced entry (`"knife"` in the `/* Time / rest */` section) and a to-value collision between `"buddy"` and `"friend"` both mapping to `"ace"` — the latter is editorially intentional but undocumented.

No critical issues. No security concerns (data-only header). No structural or syntax problems.

## Warnings

### WR-01: -ing Words in `to` Values Are Contracted by Phase 3

**File:** `src/dictionary.h:228,229,234,235,240`
**Issue:** Five `to` values in `words[]` end in `-ing` and are not covered by `ing_exceptions[]`. Phase 3 of `translate_line` scans its output buffer word-by-word and strips the trailing `g` from any word ending in `-ing` that is not in the exceptions list. This produces incorrect output:

| `from` key | `to` value | Contracted output |
|------------|------------|-------------------|
| `"fast"` (line 228) | `"cooking with gas"` | `"cookin' with gas"` |
| `"slow"` (line 229) | `"dragging"` | `"draggin'"` |
| `"rich"` (line 234) | `"rolling in bread"` | `"rollin' in bread"` |
| `"poor"` (line 235) | `"hurting for bread"` | `"hurtin' for bread"` |
| `"hot"` (line 240) | `"cooking"` | `"cookin'"` |

All five are pre-existing issues not introduced by Phase 1. Phase 1 in fact removed one such case (`"brand-spanking"` → `"spanking"` would have become `"spankin'"`). These are flagged here for tracking purposes.

**Fix:** Add the affected `-ing` words to `ing_exceptions[]` if the uncontracted form is desired, or accept the contractions as era-appropriate (all five contracted forms are plausible 1940s Harlem idiom). If the contractions are acceptable, this warning can be closed as won't-fix.

```c
/* If contractions are NOT desired, add to ing_exceptions[]: */
static const char *ing_exceptions[] = {
    "ring", "king", "sing", "wing", "ding", "ping", "ling", "ming", "ning",
    "bring", "swing", "sting", "cling", "sling", "fling", "bling",
    "spring", "string", "thing", "during",
    /* Add these to preserve uncontracted to-values: */
    "cooking", "dragging", "rolling", "hurting",
};
```

## Info

### IN-01: `"knife"` Entry Placed in `/* Time / rest */` Section

**File:** `src/dictionary.h:85`
**Issue:** The entry `{"knife", "shiv"}` appears inside the `/* Time / rest */` section (between `"bed"` and the `/* Money / possessions */` comment). This is a pre-existing misplacement — `"knife"` is a weapon, not a time/rest concept. It has no functional impact since the translator scans the full array regardless of comment groupings, but it makes the table harder to maintain.

**Fix:** Move the entry to a `/* Weapons / street */` group or to `/* Misc nouns */`:

```c
    /* Misc nouns */
    {"knife",        "shiv"},
    {"idea",         "scene"},
    /* ... */
```

### IN-02: `"buddy"` and `"friend"` Both Map to `"ace"` Without Comment

**File:** `src/dictionary.h:71,72`
**Issue:** After the Phase 1 correction, `{"friend", "ace"}`, `{"friends", "aces"}`, and `{"buddy", "ace"}` all share the same `to` value. This is semantically valid — both words denote a close associate — but the duplication is undocumented and could mislead a future editor into thinking it is an error to be corrected.

**Fix:** Add an inline comment to acknowledge the intentional overlap:

```c
    {"friend",       "ace"},
    {"friends",      "aces"},
    {"buddy",        "ace"},   /* buddy and friend are synonymous in this slang register */
```

---

_Reviewed: 2026-04-20_
_Reviewer: Claude (gsd-code-reviewer)_
_Depth: standard_
