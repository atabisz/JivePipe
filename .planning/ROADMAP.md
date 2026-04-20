# Roadmap: JivePipe

## Overview

Three phases bring the dictionary into full alignment with JIVE.md: first, fix the 14 anachronistic entries and repair the filler list; then, expand vocabulary with primary-source-backed verb, noun, adjective, and social terms; finally, implement the Tier 1 grammatical rules via phrase substitution. Every change lives in `src/dictionary.h`.

## Phases

**Phase Numbering:**
- Integer phases (1, 2, 3): Planned milestone work
- Decimal phases (2.1, 2.2): Urgent insertions (marked with INSERTED)

Decimal phases appear between their surrounding integers in numeric order.

- [ ] **Phase 1: Dictionary Corrections + Filler Quality** - Fix 14 inauthentic entries and repair the era-authenticity of the filler list
- [ ] **Phase 2: Vocabulary Expansion** - Add primary-source-backed verb, noun, adjective, and social stratification entries
- [ ] **Phase 3: Grammatical Rules** - Implement Tier 1 grammatical transformations via phrase substitution

## Phase Details

### Phase 1: Dictionary Corrections + Filler Quality
**Goal**: The `words[]` and `fillers[]` arrays contain no anachronistic or unattested entries
**Depends on**: Nothing (first phase)
**Requirements**: DICT-01, DICT-02, DICT-03, DICT-04, DICT-05, DICT-06, DICT-07, DICT-08, DICT-09, DICT-10, DICT-11, DICT-12, DICT-13, DICT-14, FILL-01, FILL-02
**Success Criteria** (what must be TRUE):
  1. `echo "my buddy" | jive` produces `ace` in output, never `homeboy`
  2. `echo "this is small and ugly" | jive` produces `lightweight` and `a real drag` in output
  3. `echo "always" | jive` produces `from sun up to sun down`, not `twenty-four seven`
  4. Filler output never contains `, feel me?`; it can produce `— you hip to that?`, `, Jack`, or `— that's the lick`
  5. All 14 corrected entries (`buddy`, `always`, `actually`, `basically`, `new`, `wonderful`, `heart`, `head`, `store`, `school`, `rules`, `small`, `ugly`, and the DICT-02 filler) map to their era-authentic replacements
**Plans**: 1 plan

Plans:
- [ ] 01-01-PLAN.md — Apply all 13 word corrections and filler list repair to src/dictionary.h

### Phase 2: Vocabulary Expansion
**Goal**: `words[]` contains a richer set of era-authentic verb, noun, adjective, and social stratification terms
**Depends on**: Phase 1
**Requirements**: VOC-01, VOC-02, VOC-03, VOC-04
**Success Criteria** (what must be TRUE):
  1. Input containing `eat` produces output using `scoff`; `look` produces `lamp`; `understand` or `know` can trigger `collar`, `hip`, or `kill` substitutions
  2. Input containing `car` produces `short`; `money` produces `scratch`; `shoes` produces `kicks`; `hat` produces `sky piece`
  3. Input containing `icky` or `mellow` or `cool` passes through or produces correct adjective substitution
  4. Input containing `snobbish` produces `dicty`; `stuffy` produces `hincty`
**Plans**: TBD

### Phase 3: Grammatical Rules
**Goal**: The `phrases[]` array implements existential "it", completive "done", and the contraction table
**Depends on**: Phase 2
**Requirements**: GRAM-01, GRAM-02, GRAM-03
**Success Criteria** (what must be TRUE):
  1. `echo "There is a cat in the hall" | jive` produces output with `It is a cat` (existential "it" rule)
  2. `echo "I already told you" | jive` produces `I done told you` (completive "done" rule)
  3. `echo "I am going to the store" | jive` produces output containing `gonna` (contraction table)
  4. All GRAM-01 existential patterns, GRAM-02 done-substitutions, and GRAM-03 contractions are present and produce correct output
**Plans**: TBD

## Progress

**Execution Order:**
Phases execute in numeric order: 1 → 2 → 3

| Phase | Plans Complete | Status | Completed |
|-------|----------------|--------|-----------|
| 1. Dictionary Corrections + Filler Quality | 0/1 | Not started | - |
| 2. Vocabulary Expansion | 0/0 | Not started | - |
| 3. Grammatical Rules | 0/0 | Not started | - |
