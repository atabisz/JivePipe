# JivePipe

Translate any text into authentic Harlem Jive slang (1928–1952). Pipe text in, get jive out.

Written in C. Binary is ~35KB. Dictionary is in `src/dictionary.h` — 234 word entries, 56 phrase entries, 13 era-authentic fillers.

See [JIVE.md](JIVE.md) for the full language reference — vocabulary, phonological rules, grammatical rules, and historical context.

## How it works

JivePipe runs a four-phase pipeline on each line of input:

1. **Phrase substitution** — multi-word phrases matched longest-first (grammar rules, idioms, multi-word expressions)
2. **Word substitution** — single-word vocabulary replacements
3. **G-dropping** — verbal `-ing` endings become `-in'`; monosyllabic words (`sing`, `ring`, `king`, `thing`, `bring`, `swing`) are excluded
4. **Filler injection** — era-authentic filler appended at ~20% rate

Phases run in order and never cascade — a word replaced in phase 2 cannot re-trigger a phrase match in phase 1.

Grammar rules (existential "it", completive "done", contraction table) are implemented as phrase substitutions in phase 1. More complex rules requiring part-of-speech tagging or a parse tree — habitual `be`, copula deletion, negative inversion — are not implemented.

## Download

Grab the latest release from [GitHub Releases](https://github.com/atabisz/JivePipe/releases/latest):

**Linux**
- `jive-linux-amd64-<version>.tar.gz` — extract and run directly
- `jive_<version>_amd64.deb` — installs to `/usr/bin`

```bash
# Binary
tar -xzf jive-linux-amd64-*.tar.gz
./jive

# Deb
sudo dpkg -i jive_*_amd64.deb
```

**Windows**
- `jive-windows-amd64-<version>.zip` — extract and run directly

```powershell
Expand-Archive jive-windows-amd64-*.zip
.\jive.exe

# Pipe in PowerShell
Get-Content sometext.txt | .\jive.exe
```

## Build

Requires `gcc` and `make`.

```bash
make
```

This produces a stripped `./jive` binary (~35KB) in the project root.

To install system-wide:

```bash
sudo make install
```

This installs to `/usr/local/bin/jive`.

## Usage

**Pipe from stdin:**
```bash
cat sometext.txt | jive
```

**Pass a file directly:**
```bash
jive sometext.txt
```

**Inline with echo:**
```bash
echo "Hello, how are you doing today?" | jive
# → "Hey there, daddy-o, what's your story, morning glory doin' today?"
```

## Example output

```
$ echo "The meeting is at the office. My boss wants to talk about money." | jive
The powwow is at the gig spot. My big daddy wants to rap about bread.
```

```
$ echo "Good morning. I don't know what's happening today, but let's go." | jive
Solid mornin', daddy-o. I ain't hip to it what's goin' down today, but let's split.
```

## Creative uses

**Jive-ify your git log:**
```bash
git log --oneline | jive
```

**Translate error messages:**
```bash
make 2>&1 | jive
```

**Pipe man pages through it:**
```bash
man ls | col -b | jive | less
```

**Liven up a meeting agenda:**
```bash
cat agenda.txt | jive > agenda-jive.txt
```

**Commit message translator (for posterity):**
```bash
git log --format="%s" | jive
```

**Pipe in your README for a vibe check:**
```bash
cat README.md | jive
```

## Development

```bash
make
make clean
```
