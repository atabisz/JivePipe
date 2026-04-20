# Phase 2: Vocabulary Expansion - Context

**Gathered:** 2026-04-20
**Status:** Ready for planning

<domain>
## Phase Boundary

Add era-authentic verb, noun, adjective, and social stratification entries to `words[]` and `phrases[]` in `src/dictionary.h`. Covers VOC-01 through VOC-04. All changes are in `src/dictionary.h` only.

</domain>

<decisions>
## Implementation Decisions

### Entry Conflicts (VOC vs Phase 1)

Five Phase 1 entries conflict with VOC success criteria requirements:

- **D-01:** Replace conflicting Phase 1 targets with the VOC-required targets:
  - `eat` → `scoff` (was `put on the feedbag`)
  - `look` → `lamp` (was `peep`)
  - `car` → `short` (was `wheels`)
  - `money` → `scratch` (was `bread`)
  - `hat` → `sky piece` (was `lid`)

  The old jive values (`put on the feedbag`, `peep`, `wheels`, `bread`, `lid`) remain valid jive terms and pass through the pipeline unchanged when typed directly.

### Multi-Word Verb Placement

- **D-02:** `fall in`, `fall out`, and `truck`/`truckin'` are multi-word inputs — they MUST go in `phrases[]`, not `words[]`. Add them maintaining longest-first sort order.
  - Suggested targets: `fall in` → `roll in`, `fall out` → `blow your wig`, `truck` → `get down`, `truckin'` → `get down` (verify against JIVE.md before finalizing exact targets)
  - `killer-diller` and `solid sender` appear only as output targets in VOC-02 — no input entries needed for them.

### VOC-03 Adjective Handling

- **D-03:** `cool` → `hip` entry stays as-is. VOC-03's intent is that `cool` is authentic jive (it is — Lester Young's term); the existing entry satisfies this.
- **D-04:** `icky` and `mellow` should have English-synonym inputs added (they are jive outputs, not English inputs):
  - Map English inputs to `icky` (JIVE.md: "unhip; ignorant of jazz") — Claude's discretion on exact inputs (e.g., `unhip`, `square`)
  - Map English inputs to `mellow` (JIVE.md: "good; pleasing; relaxed") — Claude's discretion on exact inputs (e.g., `relaxed`, `pleasant`)
  - `crazy` (positive/bebop era) — add per REQUIREMENTS.md VOC-03; existing `crazy` → `gone` entry maps FROM `crazy` which may conflict; verify

### VOC-04 Social Stratification

- **D-05:** Implement `snobbish` → `dicty` and `stuffy` → `hincty` as word entries.
- **D-06:** SKIP `ofay` and `gray` entirely. JIVE.md notes `ofay` "considered offensive; declined" and PROJECT.md explicitly targets a general-audience tool. VOC-04 partial completion: dicty and hincty only.

### Claude's Discretion

- Exact English inputs for `icky` and `mellow` mappings — use JIVE.md definitions as the guide
- Exact jive targets for `fall in`, `fall out`, `truck`/`truckin'` — verify against JIVE.md before writing
- Where in the array to insert new entries (maintain existing category comment groupings)
- `crazy` conflict resolution: existing `crazy` → `gone` may already satisfy VOC-03's "crazy (positive, bebop era)"; evaluate whether to add a second sense or keep as-is

</decisions>

<canonical_refs>
## Canonical References

**Downstream agents MUST read these before planning or implementing.**

### Language Reference and Source of Truth
- `JIVE.md` — Comprehensive language reference; Gap Analysis table (around line 750+) lists all VOC-01 through VOC-04 entries with primary-source backing. **MUST read to verify exact targets for fall in, fall out, truck, and synonym inputs for icky/mellow.**

### Requirements
- `.planning/REQUIREMENTS.md` §Vocabulary Expansion — Exact entry lists for VOC-01 through VOC-04 with source citations.
- `.planning/ROADMAP.md` §Phase 2 — Success criteria (runnable shell assertions).

### Implementation Target
- `src/dictionary.h` — The only file to be modified.

</canonical_refs>

<code_context>
## Existing Code Insights

### Reusable Assets
- `src/dictionary.h` `words[]`: `{from, to}` Entry pairs; single-word inputs only. New VOC-01/02/03/04 single-word entries go here.
- `src/dictionary.h` `phrases[]`: Multi-word input entries, sorted longest-first. `fall in`, `fall out`, `truck`, `truckin'` go here.

### Established Patterns
- Category comment groups in `words[]`: `/* People */`, `/* Verbs */`, `/* Adjectives */`, etc. — new entries should slot into the appropriate group.
- `phrases[]` requires longest-first sort; inserting multi-word verb phrases must maintain this ordering.
- Em-dash via UTF-8 `\xe2\x80\x94` for any output strings that start with `—`.

### Integration Points
- No `translator.c` changes needed; pipeline reads arrays directly via `words_count`, `phrases_count`, `fillers_count` macros.
- Replacing a `words[]` entry is a simple value change (`{from, to}` — only `to` changes for conflict resolutions).

### Conflict Detail
Five existing `words[]` entries have their `to` value replaced by D-01:

| Line (approx) | `from` | Old `to` | New `to` |
|---------------|--------|----------|----------|
| ~149 | `eat` | `put on the feedbag` | `scoff` |
| ~165 | `look` | `peep` | `lamp` |
| ~94 | `car` | `wheels` | `short` |
| ~88 | `money` | `bread` | `scratch` |
| ~101 | `hat` | `lid` | `sky piece` |

</code_context>

<specifics>
## Specific Ideas

- JIVE.md Gap Analysis table (line ~757) is the authoritative list for this phase — read it in full before writing the plan.
- `stud` is listed as source [M] (Mezzrow) — attested, include as `stud` → something meaningful (JIVE.md: "a man, especially strong or impressive"); could map FROM `guy` or similar, but `guy` already maps to `cat`. Claude's discretion.
- `a hummer` maps FROM what? JIVE.md: "exceptionally good." English inputs like `exceptional` or `outstanding` could work — Claude's discretion.
- `scratch` (money) from [G]; `kicks` (shoes) from [G]; `vine`/`vines` already exists in dictionary as `suit` → `vine` — check if `vine` needs updating or if it's already correct.

</specifics>

<deferred>
## Deferred Ideas

- ofay / gray entries — explicitly deferred per D-06 (general-audience constraint). Not a future phase candidate.
- Automated `make test` target with VOC shell assertions — deferred from Phase 1; still out of scope.

</deferred>

---

*Phase: 02-vocabulary-expansion*
*Context gathered: 2026-04-20*
