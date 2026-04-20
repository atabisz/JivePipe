---
phase: 02-vocabulary-expansion
reviewed: 2026-04-20T03:30:48Z
depth: standard
files_reviewed: 1
files_reviewed_list:
  - src/dictionary.h
findings:
  critical: 0
  warning: 2
  info: 3
  total: 5
status: issues_found
---

# Phase 02: Code Review Report

**Reviewed:** 2026-04-20T03:30:48Z
**Depth:** standard
**Files Reviewed:** 1
**Status:** issues_found

## Summary

`src/dictionary.h` is a pure data file — three `static const` arrays of phrase/word substitutions and a fourth array of -ing exception words. It has no executable logic, no memory allocation, and no external dependencies.

The file is well-organized with comment-delimited semantic sections and consistent field formatting. Two warnings were found: a violated sort invariant in the `phrases` array (documented as longest-first but one entry is out of order), and a misplaced entry in the wrong comment section. Three informational items cover a missing common-noun -ing exception, a structural anti-pattern for header-only static arrays, and a semantic collision in the word table.

---

## Warnings

### WR-01: `phrases` array violates documented longest-first sort invariant

**File:** `src/dictionary.h:46`

**Issue:** The comment on line 6 states phrases are "sorted longest-first so longest match wins." The `try_match` function in `translator.c` iterates the array in declaration order and returns on first match, so this sort is the mechanism that ensures longer phrases take priority over shorter overlapping ones. Entry `{"fall out", ...}` on line 46 is 8 characters long but is placed after `{"hang on", ...}` (line 44) and `{"come on", ...}` (line 45), both 7 characters long. This breaks the invariant.

While "fall out" and "hang on"/"come on" do not share a prefix, so no current matching defect exists, the violated invariant is a latent trap: any future phrase added that shares a prefix with "fall out" and is shorter will silently shadow it.

**Fix:** Move `{"fall out", "blow your wig"}` and `{"fall in", "roll in"}` before `{"hang on", ...}` to restore the 8-char, 7-char ordering:

```c
/* ... 9-char entries ... */
    {"right on",              "right on, daddy-o"},
    {"you know",              "you dig"},
    {"for real",              "no jive"},
    {"let's go",              "let's split"},
    {"have fun",              "have a ball"},
    {"fall out",              "blow your wig"},   /* 8 chars — before 7-char group */
    {"hang on",               "cool it a sec"},
    {"come on",               "lay it on me"},
    {"fall in",               "roll in"},
```

---

### WR-02: `"knife"` entry is in the wrong semantic section

**File:** `src/dictionary.h:88`

**Issue:** `{"knife", "shiv"}` appears inside the `/* Time / rest */` comment block (lines 83–89, between `"bed"→"the rack"` and the money/possessions section). This is a categorization error; "knife" is a possession/tool, not a time-related word. This does not affect runtime behavior, but it is a maintenance hazard: someone adding words to the "time/rest" section will encounter a mismatch, and someone searching for "knife" in a logical section won't find it.

**Fix:** Move the `{"knife", "shiv"}` entry into the `/* Money / possessions */` section (after line 95):

```c
    /* Money / possessions */
    {"money",        "scratch"},
    {"cash",         "loot"},
    {"knife",        "shiv"},      /* moved from Time/rest */
    {"dollar",       "clam"},
    /* ... */
```

---

## Info

### IN-01: Common noun "ceiling" not in `ing_exceptions` list

**File:** `src/dictionary.h:336-340`

**Issue:** The `ing_exceptions` list guards nouns and non-verbal words ending in `-ing` from having their trailing `g` dropped. "ceiling" (7 chars, ends in `-ing`, is a noun/not a gerund) is absent. It will be transformed to "ceilin'" by Phase 3 of the translator. Whether "ceilin'" is acceptable is a dialect judgment call — it is not standard jive slang — but the existing pattern of exceptions (ring, king, sing, thing, during, etc.) suggests the intent is to protect non-verbal -ing words.

Other potentially missing entries: "feeling" (noun use), "building" (noun), "meaning" (noun). All of these produce plausible jive contractions, so their exclusion may be intentional.

**Fix (if non-verbal nouns should be protected):**

```c
static const char *ing_exceptions[] = {
    "ring", "king", "sing", "wing", "ding", "ping", "ling", "ming", "ning",
    "bring", "swing", "sting", "cling", "sling", "fling", "bling",
    "spring", "string", "thing", "during",
    "ceiling", "building", "meaning", "feeling",  /* non-verbal nouns */
};
```

---

### IN-02: `static const` arrays in a shared header is an anti-pattern

**File:** `src/dictionary.h:7-341`

**Issue:** Defining `static const` arrays in a `.h` file means each translation unit that includes the header gets its own copy of the data. Currently only `translator.c` includes `dictionary.h`, so there is no practical overhead. However, as the codebase grows, adding a second include site (e.g., a test file or a future stats module) will silently duplicate ~8 KB of static data per compilation unit with no linker warning.

**Fix:** Declare the arrays as `extern const` in the header and define them once in a `.c` file (e.g., `dictionary.c`), or add a comment warning against including this header from multiple translation units:

```c
/* dictionary.h — include from exactly ONE translation unit (translator.c).
 * Static arrays here are intentionally file-scoped. */
```

---

### IN-03: Semantic collision — multiple unrelated concepts map to "scene"

**File:** `src/dictionary.h:127-128, 148, 290, 299`

**Issue:** Five distinct source words all map to `"scene"`: `"city"`, `"town"`, `"situation"`, `"idea"`, and `"time"`. This creates a many-to-one mapping where, for example, "The time and the situation in the city" becomes "The scene and the scene in the scene." The result reads as repetitive and degrades translation quality for sentences with multiple of these words.

This is a content/design issue rather than a code defect, but it is the category of issue most likely to surface in phase 2 vocabulary expansion work.

**Fix:** Differentiate at least some of these mappings to reduce collision frequency:

```c
{"city",         "big scene"},     /* or "the big apple" */
{"town",         "scene"},
{"situation",    "the whole bag"}, /* or "the score" */
{"idea",         "notion"},        /* or keep "scene" */
{"time",         "scene"},
```

---

_Reviewed: 2026-04-20T03:30:48Z_
_Reviewer: Claude (gsd-code-reviewer)_
_Depth: standard_
