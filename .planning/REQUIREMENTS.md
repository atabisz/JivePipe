# Requirements: JivePipe

**Defined:** 2026-04-20
**Core Value:** Any text piped through `jive` should produce output that a 1940s Harlem jazz musician would recognize as authentic — not parody, not Hollywood, not anachronistic AAVE.

## v1.0 Requirements

### Dictionary Corrections

Fix the 14 inauthentic/anachronistic entries identified in JIVE.md Gap Analysis, all sourced against Calloway, Burley, and Mezzrow primary sources.

- [x] **DICT-01**: `buddy` → `ace` (replaces `homeboy` — 1960s–70s, not 1940s jive)
- [x] **DICT-02**: `, feel me?` filler → `, you dig?` (modern AAVE, 1990s+)
- [x] **DICT-03**: `always` → `from sun up to sun down` (replaces `twenty-four seven` — modern expression)
- [x] **DICT-04**: `actually` → `no jive` (replaces `for real though` — modern AAVE)
- [x] **DICT-05**: `basically` → `dig this` (replaces `in the cut` — more modern AAVE)
- [x] **DICT-06**: `new` → `fresh out the box` (replaces `brand-spanking` — general colloquial, not jive)
- [x] **DICT-07**: `wonderful` → `the most` (replaces `the ginchiest` — 1959 TV slang, post-period)
- [x] **DICT-08**: `heart` → `ticker` (replaces `soul pocket` — not attested in primary sources)
- [x] **DICT-09**: `head` → `wig` (replaces `lid holder` — not attested; `wig` already in dict for brain)
- [x] **DICT-10**: `store` → `the commissary` (replaces `shop on the square` — not attested)
- [x] **DICT-11**: `school` → `the knowledge mill` (replaces `the square factory` — not attested)
- [x] **DICT-12**: `rules` → `the straight-up code` (replaces `square bylaws` — not attested)
- [x] **DICT-13**: `small` → `lightweight` (replaces `nowhere near boss` — not attested compound)
- [x] **DICT-14**: `ugly` → `a real drag` (replaces `nowhere near fine` — not attested compound)

### Vocabulary Expansion

Add authentic terms from the JIVE.md Gap Analysis with primary-source backing.

- [ ] **VOC-01**: Add verb entries: `collar` [C], `scoff` [C], `lamp` [C], `knock` [C], `fall in` [C], `fall out` [G], `hip` (v.) [G], `kill` [G], `truck`/`truckin'` [G]
- [ ] **VOC-02**: Add noun entries: `killer-diller` [C], `sender`/`solid sender` [C], `sky piece` [C], `short` (car) [C], `vine`/`vines` [C], `scratch` (money) [G], `kicks` (shoes) [G], `stud` [M], `a hummer` [C]
- [ ] **VOC-03**: Add adjective entries: `icky` [C], `mellow` [C], `crazy` (positive, bebop era), `cool` (Lester Young)
- [ ] **VOC-04**: Add social stratification word entries: `snobbish`→`dicty`, `stuffy`→`hincty`, `white person`-adjacent phrases using `ofay`/`gray` per register context

### Grammatical Rules (Tier 1)

Implement the Tier 1 rules from JIVE.md — achievable via phrase substitution in `translator.c`'s existing pipeline.

- [ ] **GRAM-01**: Existential "it" phrase entries: `There's a` → `It's a`, `There is a` → `It is a`, `There was a` → `It was a`, `There are` → `It is`
- [ ] **GRAM-02**: Completive "done" phrase entries: `I already` → `I done`, `already told` → `done told`, `He has already` → `He done`, `She has already` → `She done`, `already left` → `done left`
- [ ] **GRAM-03**: Contraction table as phrase entries: `going to` → `gonna`, `want to` → `wanna`, `got to` → `gotta`, `fixing to` → `finna`, `trying to` → `tryna`, `let me` → `lemme`, `give me` → `gimme`

### Filler Quality

- [x] **FILL-01**: Remove `, feel me?` from `fillers[]` array in `dictionary.h`
- [x] **FILL-02**: Add 3 era-authentic replacement fillers: `— you hip to that?`, `, Jack`, `— that's the lick`

## Future Requirements

### Tier 2/3 Grammar Rules

- **GRAM-F01**: Habitual "be" insertion — requires POS tagger
- **GRAM-F02**: Zero copula deletion — requires parse tree
- **GRAM-F03**: Negative inversion — requires parse tree

### Prosodic Filler Placement

- **FILL-F01**: Phrase-boundary-aware filler injection — requires sentence segmentation

## Out of Scope

| Feature | Reason |
|---------|--------|
| Tier 2/3 grammatical rules | Require POS tagging or full parse tree — beyond string-substitution architecture |
| Prosodic filler placement | Requires sentence parser; append-to-end is sufficient approximation |
| Era/register command-line flags | No-flags-needed is a hard requirement; tool targets Performed Jive register |
| Drug vocabulary sub-lexicon | General-audience tool; omitted by design despite historical accuracy |
| Th-stopping (the→de) | Variable rule; applying universally would make text look like parody |
| R-lessness (four→fo') | Same risk as th-stopping; better as specific dictionary entries |

## Traceability

| Requirement | Phase | Status |
|-------------|-------|--------|
| DICT-01 | Phase 1 | Complete |
| DICT-02 | Phase 1 | Complete |
| DICT-03 | Phase 1 | Complete |
| DICT-04 | Phase 1 | Complete |
| DICT-05 | Phase 1 | Complete |
| DICT-06 | Phase 1 | Complete |
| DICT-07 | Phase 1 | Complete |
| DICT-08 | Phase 1 | Complete |
| DICT-09 | Phase 1 | Complete |
| DICT-10 | Phase 1 | Complete |
| DICT-11 | Phase 1 | Complete |
| DICT-12 | Phase 1 | Complete |
| DICT-13 | Phase 1 | Complete |
| DICT-14 | Phase 1 | Complete |
| FILL-01 | Phase 1 | Complete |
| FILL-02 | Phase 1 | Complete |
| VOC-01 | Phase 2 | Pending |
| VOC-02 | Phase 2 | Pending |
| VOC-03 | Phase 2 | Pending |
| VOC-04 | Phase 2 | Pending |
| GRAM-01 | Phase 3 | Pending |
| GRAM-02 | Phase 3 | Pending |
| GRAM-03 | Phase 3 | Pending |

**Coverage:**
- v1.0 requirements: 23 total
- Mapped to phases: 23
- Unmapped: 0 ✓

---
*Requirements defined: 2026-04-20*
*Last updated: 2026-04-20 after roadmap creation*
