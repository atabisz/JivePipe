#!/usr/bin/env bash
# tests/validate_grammar_rules.sh — Phase 03 grammatical-rules validation
# Tests: GRAM-01, GRAM-02, GRAM-03, sort invariant, entry count, build, regression
# Usage: bash tests/validate_grammar_rules.sh
# Exit: 0 if all pass, 1 if any fail

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
JIVE="$REPO_ROOT/jive"
DIC="$REPO_ROOT/src/dictionary.h"

PASS=0
FAIL=0

pass() { echo "PASS $1"; PASS=$((PASS + 1)); }
fail() { echo "FAIL $1 — $2"; FAIL=$((FAIL + 1)); }

assert_contains() {
    local name="$1" input="$2" expected="$3"
    local actual
    actual=$(echo "$input" | "$JIVE" 2>/dev/null)
    if echo "$actual" | grep -qi "$expected"; then
        pass "$name"
    else
        fail "$name" "expected output to contain '$expected', got: $actual"
    fi
}

# ---------------------------------------------------------------------------
# BUILD CHECK
# ---------------------------------------------------------------------------

echo "--- BUILD CHECK ---"
if make -C "$REPO_ROOT" --quiet 2>&1; then
    pass "build: make exits 0"
else
    fail "build: make exits 0" "make returned non-zero"
    # Cannot run binary tests without a build
    echo ""
    echo "ABORTED: build failed, cannot run functional tests"
    exit 1
fi

# ---------------------------------------------------------------------------
# GRAM-01: Existential "it" substitutions
# ---------------------------------------------------------------------------

echo "--- GRAM-01: Existential it ---"
assert_contains "gram01_there_is_a"    "There is a cat in the hall" "It is a"
assert_contains "gram01_theres_a"      "There's a dog outside"      "It's a"
assert_contains "gram01_there_was_a"   "There was a time"           "It was a"
# NOTE: The original spec said "It are" but commit 491767c intentionally
# replaced it with "They be" (fix WR-01: grammatically invalid 'it are').
assert_contains "gram01_there_are"     "There are five cats"        "They be"

# ---------------------------------------------------------------------------
# GRAM-02: Completive "done" substitutions
# ---------------------------------------------------------------------------

echo "--- GRAM-02: Completive done ---"
assert_contains "gram02_she_has_already"  "She has already left"       "She done"
assert_contains "gram02_he_has_already"   "He has already done that"   "He done"
assert_contains "gram02_already_told"     "already told you"           "done told"
assert_contains "gram02_already_left"     "already left the building"  "done left"
assert_contains "gram02_i_already"        "I already told you"         "I done"

# ---------------------------------------------------------------------------
# GRAM-03: Contraction table
# ---------------------------------------------------------------------------

echo "--- GRAM-03: Contractions ---"
assert_contains "gram03_going_to_gonna"  "I am going to the store"    "gonna"
assert_contains "gram03_want_to_wanna"   "I want to eat"              "wanna"
assert_contains "gram03_give_me_gimme"   "Give me that"               "gimme"
assert_contains "gram03_got_to_gotta"    "I got to go"                "gotta"
assert_contains "gram03_let_me_lemme"    "Let me think"               "lemme"
assert_contains "gram03_fixing_to_finna" "She is fixing to leave"     "finna"
assert_contains "gram03_trying_to_tryna" "I am trying to understand"  "tryna"

# ---------------------------------------------------------------------------
# SORT INVARIANT (structural — checks dictionary.h source)
# ---------------------------------------------------------------------------

echo "--- SORT INVARIANT ---"

# "she has already" (15 chars) must appear before "he has already" (14 chars)
she_line=$(awk '/"she has already"/{print NR; exit}' "$DIC")
he_line=$(awk '/"he has already"/{print NR; exit}' "$DIC")
if [ -n "$she_line" ] && [ -n "$he_line" ] && [ "$she_line" -lt "$he_line" ]; then
    pass "sort_inv: she_has_already(15) before he_has_already(14)"
else
    fail "sort_inv: she_has_already(15) before he_has_already(14)" \
         "she_line=$she_line he_line=$he_line"
fi

# "fixing to" (9 chars) must appear before "going to" (8 chars)
fixing_line=$(awk '/"fixing to"/{print NR; exit}' "$DIC")
going_line=$(awk '/"going to"/{print NR; exit}' "$DIC")
if [ -n "$fixing_line" ] && [ -n "$going_line" ] && [ "$fixing_line" -lt "$going_line" ]; then
    pass "sort_inv: fixing_to(9) before going_to(8)"
else
    fail "sort_inv: fixing_to(9) before going_to(8)" \
         "fixing_line=$fixing_line going_line=$going_line"
fi

# "going to" (8 chars) must appear before "want to" (7 chars)
want_line=$(awk '/"want to"/{print NR; exit}' "$DIC")
if [ -n "$going_line" ] && [ -n "$want_line" ] && [ "$going_line" -lt "$want_line" ]; then
    pass "sort_inv: going_to(8) before want_to(7)"
else
    fail "sort_inv: going_to(8) before want_to(7)" \
         "going_line=$going_line want_line=$want_line"
fi

# "want to" (7 chars) must appear before "got to" (6 chars)
got_line=$(awk '/"got to"/{print NR; exit}' "$DIC")
if [ -n "$want_line" ] && [ -n "$got_line" ] && [ "$want_line" -lt "$got_line" ]; then
    pass "sort_inv: want_to(7) before got_to(6)"
else
    fail "sort_inv: want_to(7) before got_to(6)" \
         "want_line=$want_line got_line=$got_line"
fi

# ---------------------------------------------------------------------------
# PHRASES[] COUNT (must be 56 entries)
# ---------------------------------------------------------------------------

echo "--- PHRASES COUNT ---"
phrase_count=$(awk '/static const Entry phrases/,/^};/' "$DIC" | grep -c '{"')
if [ "$phrase_count" -eq 57 ]; then
    pass "phrases_count: exactly 57 entries in phrases[]"
else
    fail "phrases_count: exactly 57 entries in phrases[]" \
         "got $phrase_count"
fi

# ---------------------------------------------------------------------------
# REGRESSION: Phase 1/2 entries still work
# ---------------------------------------------------------------------------

echo "--- REGRESSION ---"
assert_contains "regression_buddy_ace"   "my buddy is here"    "ace"
assert_contains "regression_want_scoff"  "I want to eat food"  "scoff"

# ---------------------------------------------------------------------------
# SUMMARY
# ---------------------------------------------------------------------------

echo ""
echo "Results: $PASS passed, $FAIL failed"
if [ "$FAIL" -eq 0 ]; then
    echo "ALL TESTS PASSED"
    exit 0
else
    echo "SOME TESTS FAILED"
    exit 1
fi
