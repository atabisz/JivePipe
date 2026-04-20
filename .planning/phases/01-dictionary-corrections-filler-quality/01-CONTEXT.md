# Phase 1: Dictionary Corrections + Filler Quality - Context

**Gathered:** 2026-04-20
**Status:** Ready for planning

<domain>
## Phase Boundary

Fix 14 inauthentic/anachronistic word entries in `words[]` and repair `fillers[]` by removing the one modern AAVE filler and adding 3 era-authentic replacements. All changes are in `src/dictionary.h` only — no binary, build, or pipeline changes.

</domain>

<decisions>
## Implementation Decisions

### Filler Resolution (DICT-02 vs FILL-01+FILL-02 conflict)

The requirements contain a tension: DICT-02 described replacing `, feel me?` with `, you dig?`, but FILL-01+FILL-02 form the complete implementation spec — remove `, feel me?` and add `— you hip to that?`, `, Jack`, `— that's the lick`. No `, you dig?` addition.

- **D-01:** FILL-01+FILL-02 is the authoritative implementation spec. Do NOT add `, you dig?` as an additional filler. DICT-02 was a rough description; FILL-01+02 governs implementation. Net change: remove 1, add 3 → fillers count goes from 11 to 13. (Note: current `fillers[]` in `src/dictionary.h` has 11 entries including `, feel me?`.)

### Filler Deduplication

FILL-02 adds `— you hip to that?`. The current `fillers[]` already contains `— you hip?` (shorter form). Both are era-authentic.

- **D-02:** Keep both `— you hip?` and `— you hip to that?` in the filler list. Authentic variation — real jive speakers used both forms. Final filler count after phase: 13.

### Claude's Discretion

- Array ordering within `words[]` and `fillers[]` — maintain existing grouping/comment conventions.
- Whether to add a trailing comment on changed entries noting the source — acceptable but not required.

</decisions>

<canonical_refs>
## Canonical References

**Downstream agents MUST read these before planning or implementing.**

### Language Reference and Source of Truth
- `JIVE.md` — Comprehensive language reference; Gap Analysis section documents all 14 inauthentic entries and all FILL changes with primary-source backing. **Primary authority for era-authenticity decisions.**

### Requirements
- `.planning/REQUIREMENTS.md` — Exact substitution pairs for all 14 DICT entries and both FILL items.
- `.planning/ROADMAP.md` §Phase 1 — Success criteria (runnable shell assertions).

### Implementation Target
- `src/dictionary.h` — The only file to be modified in this phase.

</canonical_refs>

<code_context>
## Existing Code Insights

### Reusable Assets
- `src/dictionary.h` `words[]`: Static `Entry` array (`{from, to}` pairs). All 14 fixes are direct value replacements in existing entries.
- `src/dictionary.h` `fillers[]`: Static `const char*` array. FILL-01 is a deletion; FILL-02 adds 3 new string literals.

### Established Patterns
- Entries are grouped by semantic category with inline comments (`/* People */`, `/* Adjectives */`, etc.). Maintain this convention.
- Filler strings use em-dash via UTF-8 bytes `\xe2\x80\x94` where needed — match this convention for `— you hip to that?` and `— that's the lick`.
- `phrases[]` is longest-first sorted — irrelevant for this phase (no phrase changes).

### Integration Points
- No `translator.c` changes needed; the pipeline reads `dictionary.h` arrays directly via `words_count` and `fillers_count` macros.
- Build: `make` compiles `src/main.c` + `src/translator.c`. No new files, no Makefile changes.

</code_context>

<specifics>
## Specific Ideas

- JIVE.md's Filler Phrases table lists `Jack` as `C` (Calloway) — use `, Jack` with leading comma-space to match existing `, daddy-o` and `, baby` filler format convention.
- `— that's the lick` and `— you hip to that?` both use em-dash prefix — match existing `— dig?` and `— you hip?` format.

</specifics>

<deferred>
## Deferred Ideas

- Automated test target (`make test`) with ROADMAP shell assertions — user chose to defer; manual verification at execution time is sufficient for this phase.

</deferred>

---

*Phase: 01-dictionary-corrections-filler-quality*
*Context gathered: 2026-04-20*
