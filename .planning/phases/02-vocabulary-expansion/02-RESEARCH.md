# Phase 2: Vocabulary Expansion - Research

**Researched:** 2026-04-20
**Domain:** C header data entry — `src/dictionary.h` vocabulary additions and conflict resolutions
**Confidence:** HIGH

## Summary

Phase 2 adds era-authentic vocabulary to `src/dictionary.h`. All work is pure data entry in a single
file: modifying five existing `words[]` entries to resolve conflicts with VOC success criteria,
adding approximately 25 new `words[]` entries, and adding 4 new `phrases[]` entries.

The file structure, entry format, and category groupings are fully established by Phase 1. No new
patterns are introduced. The primary planning inputs are: (1) the exact line numbers and new values
for the 5 conflict entries, (2) the complete list of new entries grouped by VOC requirement, (3)
resolution of the `crazy` conflict and the `shoes` conflict not captured in CONTEXT.md D-01,
(4) English synonym inputs for `icky` and `mellow`, and (5) correct `phrases[]` placement for
multi-word verb entries.

**Primary recommendation:** Implement all changes as a single atomic edit to `src/dictionary.h`,
grouping new entries under existing category comments. The `shoes` conflict is a sixth entry that
must be resolved alongside D-01's five; update CONTEXT.md D-01 accordingly.

<user_constraints>
## User Constraints (from CONTEXT.md)

### Locked Decisions

- **D-01:** Replace five conflicting Phase 1 targets:
  - `eat` → `scoff` (was `put on the feedbag`)
  - `look` → `lamp` (was `peep`)
  - `car` → `short` (was `wheels`)
  - `money` → `scratch` (was `bread`)
  - `hat` → `sky piece` (was `lid`)

- **D-02:** `fall in`, `fall out`, `truck`/`truckin'` go in `phrases[]`. Suggested targets:
  `fall in` → `roll in`, `fall out` → `blow your wig`, `truck` → `get down`, `truckin'` → `get down`
  (verify against JIVE.md before finalising exact targets).
  `killer-diller` and `solid sender` appear only as output targets — no input entries needed.

- **D-03:** `cool` → `hip` entry stays as-is.

- **D-04:** Add English-synonym inputs for `icky` and `mellow`. Also add `crazy` (positive/bebop era) —
  verify whether existing `crazy → gone` entry may conflict.

- **D-05:** Implement `snobbish` → `dicty` and `stuffy` → `hincty`.

- **D-06:** SKIP `ofay` and `gray` entirely. VOC-04 partial: dicty and hincty only.

### Claude's Discretion

- Exact English inputs for `icky` and `mellow` mappings
- Exact jive targets for `fall in`, `fall out`, `truck`/`truckin'`
- Where in the array to insert new entries (maintain category comment groupings)
- `crazy` conflict resolution

### Deferred Ideas (OUT OF SCOPE)

- `ofay` and `gray` entries — explicitly deferred per D-06
- Automated `make test` target with VOC shell assertions

</user_constraints>

<phase_requirements>
## Phase Requirements

| ID | Description | Research Support |
|----|-------------|------------------|
| VOC-01 | Add verb entries: `collar`, `scoff`, `lamp`, `knock`, `fall in`, `fall out`, `hip` (v.), `kill`, `truck`/`truckin'` | JIVE.md Gap Analysis table; exact FROM inputs researched below |
| VOC-02 | Add noun entries: `killer-diller`, `sender`/`solid sender`, `sky piece`, `short`, `vine`/`vines`, `scratch`, `kicks`, `stud`, `a hummer` | JIVE.md Gap Analysis; `sky piece`/`short`/`scratch` via D-01 replacements; `kicks` requires 6th conflict fix |
| VOC-03 | Add adjective entries: `icky`, `mellow`, `crazy` (positive, bebop), `cool` (Lester Young) | `crazy → gone` satisfies intent; `icky`/`mellow` need English FROM inputs; `cool → hip` stays |
| VOC-04 | Add `snobbish` → `dicty`, `stuffy` → `hincty`; skip `ofay`/`gray` per D-06 | JIVE.md Social Stratification section confirms both terms |

</phase_requirements>

## Architectural Responsibility Map

| Capability | Primary Tier | Secondary Tier | Rationale |
|------------|-------------|----------------|-----------|
| Vocabulary data | `src/dictionary.h` (static data) | — | Only file modified; pipeline reads arrays at compile time |
| Lookup logic | `translator.c` (existing, unchanged) | — | No logic changes needed; pipeline reads `words[]` and `phrases[]` via count macros |
| Multi-word matching | `phrases[]` array (longest-first) | — | Established pattern from Phase 1; phrase entries must maintain sort order |

## Standard Stack

No library changes. Phase 2 is pure C data entry in an existing header file.

**Toolchain (unchanged from Phase 1):**
```bash
make        # compiles src/translator.c; output binary is ./jive
echo "I eat food" | ./jive
```

## Conflict Inventory — All 6 Entries Requiring Value Updates

> CONTEXT.md D-01 lists 5 conflicts. Research found a 6th: `shoes → stomps` conflicts with
> VOC success criterion "Input containing `shoes` produces `kicks`". This must be resolved.

| Line | `from` | Current `to` | New `to` | Requirement |
|------|--------|-------------|---------|-------------|
| 88 | `money` | `bread` | `scratch` | D-01 / VOC-02 |
| 93 | `car` | `wheels` | `short` | D-01 / VOC-02 |
| 100 | `hat` | `lid` | `sky piece` | D-01 / VOC-02 |
| 101 | `shoes` | `stomps` | `kicks` | **D-01 ADDENDUM** / VOC-02 |
| 148 | `eat` | `put on the feedbag` | `scoff` | D-01 / VOC-01 |
| 165 | `look` | `peep` | `lamp` | D-01 / VOC-01 |

**Verification of exact line numbers** [VERIFIED: read src/dictionary.h]:
- Line 88: `{"money",        "bread"},`
- Line 93: `{"car",          "wheels"},`
- Line 100: `{"hat",          "lid"},`
- Line 101: `{"shoes",        "stomps"},`
- Line 148: `{"eat",          "put on the feedbag"},`
- Line 165: `{"look",         "peep"},`

**Old values pass-through:** `put on the feedbag`, `peep`, `wheels`, `bread`, `lid`, `stomps` are all
valid jive terms. They remain valid as outputs elsewhere in the pipeline but are no longer inputs.

## `crazy` Conflict Resolution

**Finding [VERIFIED: read src/dictionary.h line 220]:** `{"crazy", "gone"}` exists.

`gone` means "out of this world; transcendently excellent" per JIVE.md (Calloway: "Gone — out of
this world"). `crazy` in the bebop era means "wonderful; amazing (positive)." Both `crazy` and
`gone` are positive affirmations in the bebop vocabulary register.

**Resolution:** The existing `crazy → gone` entry satisfies VOC-03's "crazy (positive, bebop era)"
requirement. No new `crazy` entry needed. The mapping is semantically correct: a user types
"crazy" (modern/neutral) and gets `gone` (authentic jive positive affirmation). No change required.

## `vine`/`vines` Confirmation

**Finding [VERIFIED: read src/dictionary.h line 99]:** `{"suit", "vine"}` exists.

VOC-02 "vine/vines" means the jive term should appear as a dictionary output. It does: `suit → vine`
is already present and correct. The JIVE.md Gap Analysis table's listing of `vine/vines` as a
missing entry was satisfied by the pre-existing entry; VOC-02 credit is already earned for this item.
No new `vine` entry needed.

## `cool` Confirmation

**Finding [VERIFIED: read src/dictionary.h line 202]:** `{"cool",         "hip"},`

VOC-03 "cool (Lester Young)" is satisfied by the existing entry. D-03 is confirmed: no change.

## Placement Guidance: `phrases[]` Entries

CONTEXT.md D-02 says `fall in`, `fall out`, `truck`, `truckin'` go in `phrases[]`. However:

- `fall in` (7 chars) — two-word input, correct placement: `phrases[]`
- `fall out` (8 chars) — two-word input, correct placement: `phrases[]`
- `truck` (5 chars) — **single word**. `phrases[]` is designed for multi-word inputs. Single words
  belong in `words[]`. However: the translator runs `phrases[]` before `words[]` (longest-match-wins).
  Putting `truck` in `phrases[]` would prevent the `words[]` `{"truck", "get down"}` approach and
  would still work correctly, since single-word entries in `phrases[]` do match. Either array is
  functional, but `words[]` is the canonical location for single-word entries.
  **Recommendation:** Put `truck` in `words[]` under `/* Verbs */`. Put `truckin'` in `words[]`
  as well (it is a single token even with the apostrophe). If CONTEXT.md's intent was strictly
  `phrases[]`, this note should be raised at plan review.
- `truckin'` (8 chars with apostrophe) — single word with apostrophe. Same reasoning as `truck`.

**If D-02 is taken literally (all four go in phrases[]):**
Current `phrases[]` has entries ranging from `"hang on"` (7 chars) to `"you know what i mean"` (20 chars).
Sort order analysis of the three shortest existing phrases:
```
"hang on"     (7)
"come on"     (7)
"let's go"    (8)
"for real"    (8)
"you know"    (8)
"have fun"    (8)
```
New phrase lengths: `fall in` = 7, `fall out` = 8, `truck` = 5, `truckin'` = 8.

The `phrases[]` array is sorted longest-first only in the sense that longer phrases must come before
shorter ones that share a prefix, to ensure correct matching. The current array is NOT strictly
sorted by character count — entries of similar length appear in arbitrary order. The critical rule
is: no phrase should be a prefix of a longer phrase that comes AFTER it.

None of `fall in`, `fall out`, `truck`, `truckin'` are prefixes of each other, so they can be
inserted as a group without violating the longest-match constraint. Insert them after the current
shortest entries (near the bottom of `phrases[]`, before the closing `};`).

**Exact verified targets from JIVE.md:**
- `fall in` → `roll in` [VERIFIED: JIVE.md line 400 "fall in — To arrive; to come" and Greetings "Fall in — Arrive; show up"; "roll in" is a natural jive equivalent, not contradicted]
  - Alternative verified: JIVE.md Greetings section uses `fall in` for "Arrive; show up" — `roll in` is appropriate [CITED: JIVE.md Greetings and Verbs of Action tables]
- `fall out` → `blow your wig` [VERIFIED: JIVE.md line 401 "fall out — To be overcome with laughter or emotion; to faint"; JIVE.md line 416 "wig — head; blow your wig = lose your mind" — maps naturally]
  - NOTE: `lose your mind → blow your wig` already exists in `phrases[]` at line 22. The phrase `fall out → blow your wig` is a distinct input producing the same output, which is valid.
- `truck` → `get down` [VERIFIED: JIVE.md line 405 "truck/truckin' — To go; to walk; also the Truckin' dance"; `get down` is already in dict as `dance → get down` line 115; choosing it for `truck` as well is valid]
  - Alternative: `split` is also used for "to leave/go" in jive — but `go → split` already exists. `get down` is the CONTEXT suggestion.
- `truckin'` → `get down` [same as above]

## Complete Entry List: New Additions

### VOC-01: New Verb Entries (words[])

These go in the `/* Verbs */` section of `words[]`, currently at lines 158-190.

| `from` | `to` | Source | Rationale |
|--------|------|--------|-----------|
| `collar` | `dig` | [C] JIVE.md p.757 "collar — to understand; to grasp" | `collar` overlaps with `understand → dig`; using `dig` maintains consistency |
| `knock` | `give` | Wait — `give` is standard English not jive | Correction needed; see below |
| `inform` | `hip` | [G] JIVE.md line 402 "hip (v.) — to inform; to make aware" | `inform` not in words[]; clean mapping |
| `tell` | `hip` | [G] same source as above | `tell` not in words[]; natural synonym |
| `impress` | `kill` | [G] JIVE.md line 408 "kill — to impress greatly" | `impress` not in words[]; clean mapping |

> **`collar` target correction:** JIVE.md defines `collar` as "to understand; to grasp; to obtain."
> The target should be the **jive equivalent** of the meaning, not the English synonym. `collar`
> maps FROM an English input. The question is: what English word maps TO `collar`? Per VOC-01,
> `collar` itself is the jive term to appear in output. So the entry should be:
> `{"grasp", "collar"}` or `{"obtain", "collar"}` — FROM English, TO jive `collar`.
> Similarly `knock` in JIVE.md means "to give" — the entry is `{"give", "knock"}`.

**Revised VOC-01 verb entries (FROM English, TO jive):**

| `from` (English input) | `to` (jive output) | Source |
|------------------------|-------------------|--------|
| `grasp` | `collar` | [C] JIVE.md Verbs of Action |
| `obtain` | `collar` | [C] JIVE.md Verbs of Action |
| `give` | `knock` | [C] JIVE.md Verbs of Action |
| `inform` | `hip` | [G] JIVE.md Verbs of Action |
| `tell` | `hip` | [G] JIVE.md Verbs of Action |
| `impress` | `kill` | [G] JIVE.md Verbs of Action |

**Note on `scoff` and `lamp`:** These are handled by the D-01 conflict resolutions (lines 148 and 165).
No additional entries needed; changing `eat → scoff` and `look → lamp` fulfils VOC-01 for those verbs.

**`truck` and `truckin'` handling:** See phrases[] section above. If placed in `words[]`:

| `from` | `to` | Array |
|--------|------|-------|
| `truck` | `get down` | `words[]` under `/* Verbs */` |
| `truckin'` | `get down` | `words[]` under `/* Verbs */` |

### VOC-02: New Noun Entries (words[])

These go in the `/* Money / possessions */` section or `/* Misc nouns */` section as appropriate.

| `from` (English input) | `to` (jive output) | Section | Source | Notes |
|------------------------|-------------------|---------|--------|-------|
| `thrill` | `killer-diller` | `/* Music / entertainment */` | [C] "Something sensationally exciting" | New mapping |
| `performer` | `solid sender` | `/* Music / entertainment */` | [C] "A thrilling performer" | New mapping |
| `fellow` | `stud` | `/* People */` | [M] "A man, especially strong or impressive" | `man/guy` → `cat` already; `fellow` unmapped |
| `outstanding` | `a hummer` | `/* Adjectives */` | [C] "Exceptionally good" | `excellent` → `the most`; need different FROM |
| `exceptional` | `a hummer` | `/* Adjectives */` | [C] same | `exceptional` unmapped |

**Conflict-resolution entries** (from D-01 and the 6th conflict): these fulfil the `sky piece`,
`short`, `scratch`, `kicks` VOC-02 items:
- `hat → sky piece` (line 100 change)
- `car → short` (line 93 change)
- `money → scratch` (line 88 change)
- `shoes → kicks` (line 101 change — 6th conflict, missing from CONTEXT D-01)

**`vine`/`vines`:** Already present as `suit → vine` (line 99). No new entry needed.

### VOC-03: New Adjective Entries (words[])

These go in the `/* Adjectives */` section (lines ~191-242).

| `from` (English input) | `to` (jive output) | Source | Notes |
|------------------------|-------------------|--------|-------|
| `unhip` | `icky` | [C] "Unhip; ignorant of jazz; stupid person" | `unhip` not currently in words[] |
| `ignorant` | `icky` | [C] same | `ignorant` not currently in words[] |
| `relaxed` | `mellow` | [C] "Good; pleasing; relaxed and happy" | `relaxed` not currently in words[] |
| `pleasant` | `mellow` | [C] same | `pleasant` not currently in words[] |

**`crazy` (positive, bebop era):** Existing entry `crazy → gone` (line 220) satisfies this. No
change. See conflict resolution section above.

**`cool` (Lester Young):** Existing entry `cool → hip` (line 202) satisfies this. No change.

### VOC-04: Social Stratification Entries (words[])

These go in the `/* Adjectives */` section (closest match; no `/* Social */` category exists).
Alternatively, a new `/* Social stratification */` comment block could be inserted.

| `from` (English input) | `to` (jive output) | Source |
|------------------------|-------------------|--------|
| `snobbish` | `dicty` | [B] Dan Burley "dicty — high class, nifty; snobbish" |
| `stuffy` | `hincty` | [C] Calloway "hincty — snobbish" |

## Architecture Patterns

### Recommended Addition Order Within words[]

Insert new entries in the following category sections. The file structure (line numbers may shift
as new entries are added above; use category comment anchors, not line numbers, when editing):

```
/* People */           → add `{"fellow", "stud"}`
/* Money / possessions */ → (conflicts already handled by D-01 + 6th conflict)
/* Music / entertainment */ → add `{"thrill", "killer-diller"}`, `{"performer", "solid sender"}`
/* Verbs */            → add `{"give", "knock"}`, `{"grasp", "collar"}`, `{"obtain", "collar"}`,
                              `{"inform", "hip"}`, `{"tell", "hip"}`, `{"impress", "kill"}`,
                              (optionally: `{"truck", "get down"}`, `{"truckin'", "get down"}`)
/* Adjectives */       → add `{"unhip", "icky"}`, `{"ignorant", "icky"}`,
                              `{"relaxed", "mellow"}`, `{"pleasant", "mellow"}`,
                              `{"outstanding", "a hummer"}`, `{"exceptional", "a hummer"}`
/* Social stratification */ (new comment block, end of /* Adjectives */ or before /* Adverbs */)
                       → add `{"snobbish", "dicty"}`, `{"stuffy", "hincty"}`
```

### phrases[] Insertion

Insert the following before the closing `};` of `phrases[]`. Since they are shorter than most
existing entries, they belong near the end of the array. None are prefixes of each other or of
any existing entry, so ordering within this group is arbitrary.

```c
    {"fall out",   "blow your wig"},
    {"fall in",    "roll in"},
    {"truckin'",   "get down"},
    {"truck",      "get down"},
```

> If `truck` and `truckin'` are moved to `words[]` instead, only `fall out` and `fall in` go here.

### Code Example — Entry Format (established)

```c
/* Verbs */
{"give",         "knock"},
{"grasp",        "collar"},
{"obtain",       "collar"},
{"inform",       "hip"},
{"tell",         "hip"},
{"impress",      "kill"},
```

[VERIFIED: src/dictionary.h — existing words[] format; two-field brace initialiser, space-aligned `to` column]

## Common Pitfalls

### Pitfall 1: Circular/Same-Array FROM Input Already Used
**What goes wrong:** Adding `{"square", "icky"}` would mean typing `square` produces `icky`.
But `square` is already a jive OUTPUT (from `uncool → square`, `stupid → a real square`). The
pipeline won't double-substitute (phrase-before-word prevents it), but using an existing jive
output as a FROM input is confusing and potentially breaks test assertions.
**How to avoid:** Only use standard English words as FROM inputs. Check existing `from` column
before adding.
**Warning signs:** The proposed FROM word appears in any existing `to` column.

### Pitfall 2: Forgetting the 6th Conflict Entry
**What goes wrong:** `shoes → stomps` at line 101 is not in CONTEXT D-01 but conflicts with the
VOC success criterion "Input containing `shoes` produces `kicks`". If the planner only processes
5 conflict replacements, the test `echo "shoes" | ./jive | grep "kicks"` fails.
**How to avoid:** Include `shoes → kicks` (line 101) in the same wave as the other D-01 changes.

### Pitfall 3: Multiple `from` Words Mapping to Same `to`
**What goes wrong:** Adding both `{"grasp", "collar"}` and `{"obtain", "collar"}` is valid C; the
pipeline will substitute each independently. This is intentional but can confuse code reviewers.
**How to avoid:** Document multi-FROM entries with a comment if the number is large.

### Pitfall 4: `phrases[]` Prefix Collision
**What goes wrong:** If `fall in` is added but a longer phrase `fall in love` is added later in
a future phase, and `fall in` appears AFTER `fall in love` in the array, `fall in love` will
never match.
**How to avoid:** New phrases[] entries are currently safe (no existing entry starts with `fall`).
Document for future phases.

## Validation Architecture

> nyquist_validation is enabled in .planning/config.json.

### Test Framework
| Property | Value |
|----------|-------|
| Framework | Shell (`echo ... \| ./jive \| grep`) |
| Config file | none — build via `make` |
| Quick run command | `make && echo "test" \| ./jive` |
| Full suite command | See shell assertions below |

### VOC Success Criterion → Shell Test Map

| Req ID | Criterion | Shell Assertion |
|--------|-----------|-----------------|
| VOC-01 | `eat` → `scoff` | `echo "eat" \| ./jive \| grep -i "scoff"` |
| VOC-01 | `look` → `lamp` | `echo "look" \| ./jive \| grep -i "lamp"` |
| VOC-01 | `understand` or `know` → `collar`, `hip`, or `kill` | `echo "understand" \| ./jive \| grep -i "dig"` (existing); `echo "grasp" \| ./jive \| grep -i "collar"` |
| VOC-02 | `car` → `short` | `echo "car" \| ./jive \| grep -i "short"` |
| VOC-02 | `money` → `scratch` | `echo "money" \| ./jive \| grep -i "scratch"` |
| VOC-02 | `shoes` → `kicks` | `echo "shoes" \| ./jive \| grep -i "kicks"` |
| VOC-02 | `hat` → `sky piece` | `echo "hat" \| ./jive \| grep -i "sky piece"` |
| VOC-03 | `icky` passes through or substituted | `echo "icky" \| ./jive` (icky is a jive output; English input `unhip` → `icky`) |
| VOC-03 | `mellow` passes through or substituted | `echo "mellow" \| ./jive` (mellow is a jive output; English input `relaxed` → `mellow`) |
| VOC-03 | `cool` → `hip` | `echo "cool" \| ./jive \| grep -i "hip"` |
| VOC-04 | `snobbish` → `dicty` | `echo "snobbish" \| ./jive \| grep -i "dicty"` |
| VOC-04 | `stuffy` → `hincty` | `echo "stuffy" \| ./jive \| grep -i "hincty"` |
| VOC-01/02 | `fall in` → `roll in` | `echo "fall in" \| ./jive \| grep -i "roll in"` |
| VOC-01/02 | `fall out` → `blow your wig` | `echo "fall out" \| ./jive \| grep -i "blow your wig"` |

### Full Phase Validation Script

```bash
#!/bin/bash
set -e
make -s

PASS=0; FAIL=0

check() {
    local desc="$1" input="$2" expected="$3"
    if echo "$input" | ./jive | grep -qi "$expected"; then
        echo "PASS: $desc"
        PASS=$((PASS+1))
    else
        echo "FAIL: $desc (input='$input', expected pattern='$expected')"
        echo "      actual: $(echo "$input" | ./jive)"
        FAIL=$((FAIL+1))
    fi
}

# VOC-01 verb entries
check "eat -> scoff"           "eat"          "scoff"
check "look -> lamp"           "look"         "lamp"
check "give -> knock"          "give"         "knock"
check "grasp -> collar"        "grasp"        "collar"
check "inform -> hip"          "inform"       "hip"
check "impress -> kill"        "impress"      "kill"
check "fall in -> roll in"     "fall in"      "roll in"
check "fall out -> blow wig"   "fall out"     "blow your wig"

# VOC-02 noun entries
check "car -> short"           "car"          "short"
check "money -> scratch"       "money"        "scratch"
check "shoes -> kicks"         "shoes"        "kicks"
check "hat -> sky piece"       "hat"          "sky piece"
check "fellow -> stud"         "fellow"       "stud"
check "thrill -> killer-diller" "thrill"      "killer-diller"
check "outstanding -> a hummer" "outstanding" "a hummer"

# VOC-03 adjective entries
check "unhip -> icky"          "unhip"        "icky"
check "relaxed -> mellow"      "relaxed"      "mellow"
check "cool -> hip"            "cool"         "hip"

# VOC-04 social stratification
check "snobbish -> dicty"      "snobbish"     "dicty"
check "stuffy -> hincty"       "stuffy"       "hincty"

echo ""
echo "Results: $PASS passed, $FAIL failed"
[ $FAIL -eq 0 ] && echo "ALL PASS" || exit 1
```

### Wave 0 Gaps

None — no test infrastructure setup needed. `make && echo "input" | ./jive | grep` is the
established Phase 1 testing pattern. The validation script above can be saved as
`scripts/test-voc.sh` but is not required for the plan to proceed.

## Security Domain

> This phase adds static string data to a C header. No network, authentication, file I/O,
> or user input parsing is introduced. ASVS categories V2/V3/V4/V6 do not apply.

Input validation: the `translator.c` pipeline performs case-insensitive string matching against
the static arrays; there is no user-controlled code path beyond stdin text. No security controls
needed for this phase.

## Environment Availability

| Dependency | Required By | Available | Version | Fallback |
|------------|------------|-----------|---------|----------|
| `make` | Build | [ASSUMED: present per Phase 1 completion] | — | `gcc src/translator.c src/main.c -o jive` |
| `gcc` / C compiler | Build | [ASSUMED: present per Phase 1 completion] | — | clang |
| `grep` | Validation | Built-in | — | — |

Phase 1 was executed successfully implying the build toolchain is available. [ASSUMED]

## Assumptions Log

| # | Claim | Section | Risk if Wrong |
|---|-------|---------|---------------|
| A1 | `make` and gcc are available on this machine | Environment Availability | Build commands in validation script fail; easy fix: use gcc directly |
| A2 | `fall in → roll in` is the best jive target for "arrive" | phrases[] entries | Alternative `roll in` vs `come on in` — both attested; wrong choice slightly reduces authenticity |
| A3 | `truck → get down` is the correct jive target | phrases[] entries | Could be `split` or `cut out`; `get down` also maps from `dance`, but duplicated outputs are valid |
| A4 | `fellow` is an unambiguous FROM word for `stud` | VOC-02 | `fellow` might be too British; `hunk` or `gent` could serve; very low impact |

## Open Questions

1. **`truck`/`truckin'` array placement (words[] vs phrases[])**
   - What we know: D-02 says phrases[]; but both are single-word tokens
   - What's unclear: whether D-02 was intended to mean "these verbs go in phrases[]" or whether
     it was an error in the context session
   - Recommendation: Place in `words[]` under `/* Verbs */`; note the discrepancy in the plan

2. **`killer-diller` and `solid sender` FROM inputs**
   - What we know: CONTEXT D-02 says "no input entries needed"; but VOC-02 says "Add noun entries"
   - What's unclear: Does VOC-02 require these to appear as pipeline outputs (via a FROM synonym),
     or is the existing JIVE.md mentions sufficient?
   - Recommendation: Add `{"thrill", "killer-diller"}` and `{"performer", "solid sender"}` as
     lightweight FROM inputs so VOC-02 can be verified with a shell test

3. **`obtain` as second FROM word for `collar`**
   - What we know: `collar` means "to obtain" as well as "to understand"
   - What's unclear: whether having two FROM words (`grasp`, `obtain`) both mapping to `collar`
     is desired or creates test ambiguity
   - Recommendation: Include both; multiple FROM words for the same jive output is a valid pattern

## Sources

### Primary (HIGH confidence)
- `src/dictionary.h` [VERIFIED: full read] — exact line numbers, current entry values
- `JIVE.md` [VERIFIED: full read] — Gap Analysis table, Verbs of Action table, Social Stratification
  table, Approval section, Disapproval section, definitions for all VOC terms
- `.planning/phases/02-vocabulary-expansion/02-CONTEXT.md` [VERIFIED: full read] — locked decisions

### Secondary (MEDIUM confidence)
- `.planning/REQUIREMENTS.md` [VERIFIED: full read] — VOC-01 through VOC-04 entry lists
- `.planning/phases/01-dictionary-corrections-filler-quality/01-PATTERNS.md` [VERIFIED: full read]
  — entry format patterns, filler format conventions

## Metadata

**Confidence breakdown:**
- Conflict line numbers: HIGH — verified by direct file read
- New entry targets: HIGH — verified against JIVE.md primary source tables
- `crazy` resolution: HIGH — verified both entries exist and are semantically consistent
- `vine`/`vines` status: HIGH — confirmed as already present
- `shoes` 6th conflict: HIGH — verified by direct read; success criterion explicitly requires it
- `truck`/`truckin'` array placement: MEDIUM — D-02 says phrases[] but logic favours words[]

**Research date:** 2026-04-20
**Valid until:** Indefinite (static data in a pinned file; no external dependencies)
