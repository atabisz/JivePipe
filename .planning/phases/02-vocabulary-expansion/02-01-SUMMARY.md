---
phase: 02-vocabulary-expansion
plan: 01
subsystem: dictionary
tags: [c, jive, dictionary, vocabulary, slang]

# Dependency graph
requires:
  - phase: 01-dictionary-corrections-filler-quality
    provides: corrected base dictionary with era-authentic entries
provides:
  - 6 conflict-resolved entries: money->scratch, car->short, hat->sky piece, shoes->kicks, eat->scoff, look->lamp
  - 8 new verb entries: give->knock, grasp->collar, obtain->collar, inform->hip, tell->hip, impress->kill, truck->get down, truckin'->get down
  - 3 new people/entertainment entries: fellow->stud, thrill->killer-diller, performer->solid sender
  - 6 new adjective entries: unhip->icky, ignorant->icky, relaxed->mellow, pleasant->mellow, outstanding->a hummer, exceptional->a hummer
  - 2 new social stratification entries: snobbish->dicty, stuffy->hincty
  - 2 new phrase entries: fall out->blow your wig, fall in->roll in
affects: [03-grammatical-rules, vocabulary, phrases]

# Tech tracking
tech-stack:
  added: []
  patterns: [category-comment-blocks in words[], longest-first phrase ordering in phrases[]]

key-files:
  created: []
  modified: [src/dictionary.h]

key-decisions:
  - "truck/truckin' added to words[] as single-word tokens (not phrases[]) per D-02 intent"
  - "fall in/fall out added to phrases[] as multi-word tokens per D-02"
  - "Social stratification comment block added after adjectives section for dicty/hincty"
  - "ofay/gray entries explicitly deferred per D-06 general-audience constraint"

patterns-established:
  - "New adjective categories get their own comment block within words[] when semantically distinct"
  - "All entries must be attested in [C] Calloway, [B] Burley, [M] Mezzrow, or [G] general"

requirements-completed: [VOC-01, VOC-02, VOC-03, VOC-04]

# Metrics
duration: 2min
completed: 2026-04-20
---

# Phase 2 Plan 1: Vocabulary Expansion Summary

**6 era-authentic conflict resolutions + 20 new 1940s Harlem jive entries across verb, noun, adjective, and social-stratification categories**

## Performance

- **Duration:** 2 min
- **Started:** 2026-04-20T03:24:14Z
- **Completed:** 2026-04-20T03:26:18Z
- **Tasks:** 2
- **Files modified:** 1

## Accomplishments

- Resolved 6 entry conflicts replacing inauthentic jive terms (bread, wheels, lid, stomps, put on the feedbag, peep) with era-authentic equivalents (scratch, short, sky piece, kicks, scoff, lamp)
- Added 20 new entries satisfying VOC-01 through VOC-04: 8 verbs, 3 people/entertainment nouns, 6 adjectives, 2 social stratification terms, 2 multi-word phrases
- All 20 assertions in the validation script pass; pre-existing entries (suit→vine, cool→hip, crazy→gone) undisturbed

## Task Commits

Each task was committed atomically:

1. **Task 1: Resolve 6 entry conflicts in words[]** - `d382bd1` (fix)
2. **Task 2: Add new words[] and phrases[] entries for VOC-01 through VOC-04** - `1d97526` (feat)

## Files Created/Modified

- `src/dictionary.h` - 6 entry conflicts resolved; 20 new entries added across words[] and phrases[]

## Decisions Made

- `truck` and `truckin'` belong in words[] (single-word tokens) rather than phrases[], per D-02 intent that multi-word inputs go to phrases[]
- `fall in` and `fall out` go into phrases[] as two-word inputs
- A new `/* Social stratification */` comment block was added between the Adjectives and Adverbs sections to house `dicty` and `hincty`
- `ofay` and `gray` entries remain deferred per D-06 (general-audience constraint)

## Deviations from Plan

None - plan executed exactly as written.

## Issues Encountered

None.

## User Setup Required

None - no external service configuration required.

## Next Phase Readiness

- VOC-01 through VOC-04 fully satisfied; dictionary is ready for Phase 3 (Grammatical Rules)
- Phrase array still has room for GRAM-01/GRAM-02/GRAM-03 entries (existential "it", completive "done", contraction table)
- No blockers

---
*Phase: 02-vocabulary-expansion*
*Completed: 2026-04-20*
