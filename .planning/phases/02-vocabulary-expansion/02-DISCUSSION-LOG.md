# Phase 2: Vocabulary Expansion - Discussion Log

> **Audit trail only.** Do not use as input to planning, research, or execution agents.
> Decisions are captured in CONTEXT.md — this log preserves the alternatives considered.

**Date:** 2026-04-20
**Phase:** 02-vocabulary-expansion
**Areas discussed:** Entry conflicts, Multi-word inputs, VOC-03 cool/icky/mellow, VOC-04 scope

---

## Entry Conflicts

| Option | Description | Selected |
|--------|-------------|----------|
| Replace with VOC target | Swap Phase 1 target for the VOC-required target for eat, look, car, money, hat | ✓ |
| Keep both (add VOC as 2nd entry) | Impossible — words[] first-hit wins | |
| Keep Phase 1, skip conflicting VOC | Don't touch Phase 1 entries; VOC criteria would fail for 5 words | |

**User's choice:** Replace with VOC target
**Notes:** Phase 1 jive values (put on the feedbag, peep, wheels, bread, lid) remain valid pass-through jive when typed directly.

---

## Multi-Word Inputs

| Option | Description | Selected |
|--------|-------------|----------|
| Add to phrases[] | Add fall in, fall out, truck/truckin' as phrase entries, longest-first sorted | ✓ |
| Skip multi-word verbs | Only add single-word inputs; skip fall in/fall out/truck | |

**User's choice:** Add to phrases[]

| Option | Description | Selected |
|--------|-------------|----------|
| Outputs only | killer-diller and solid sender are output targets only, no input entry needed | ✓ |
| Map them as inputs too | Add input entries for killer-diller / solid sender | |

**User's choice:** Outputs only — no input entries for killer-diller or solid sender.

---

## VOC-03 cool / icky / mellow

| Option | Description | Selected |
|--------|-------------|----------|
| Leave cool→hip as-is | Existing entry satisfies VOC-03; cool is already jive-authentic | ✓ |
| Remove cool entry | Let cool pass through unchanged | |

**User's choice:** Leave cool→hip as-is

| Option | Description | Selected |
|--------|-------------|----------|
| Map English synonyms | Add input→icky and input→mellow with English synonyms per JIVE.md definitions | ✓ |
| Add as pass-through only | No new entries; icky/mellow pass through when typed directly | |
| Claude's discretion | Claude decides inputs | |

**User's choice:** Map English synonyms (Claude's discretion on exact inputs per JIVE.md)

---

## VOC-04 Scope

| Option | Description | Selected |
|--------|-------------|----------|
| Skip ofay/gray entirely | Implement dicty and hincty only; omit ofay/gray per general-audience constraint | ✓ |
| Include all four | Add all VOC-04 entries including ofay and gray | |
| Include ofay/gray as output-only | No input mapping but mention in comments | |

**User's choice:** Skip ofay/gray entirely

---

## Claude's Discretion

- Exact English inputs for `icky` and `mellow`
- Exact jive targets for `fall in`, `fall out`, `truck`/`truckin'` (verify against JIVE.md)
- Where in array to insert new entries
- `crazy` conflict resolution (existing `crazy`→`gone` may already cover VOC-03)

## Deferred Ideas

- ofay / gray — deferred permanently (general-audience constraint)
- Automated test target — deferred from Phase 1, still out of scope
