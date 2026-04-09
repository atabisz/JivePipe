# JivePipe

Translate any text into authentic Harlem Jive slang. Pipe text in, get jive out.

Phrases get swapped, `-ing` endings drop their `g`, and the occasional filler — *daddy-o* — rolls in at random. The translation is single-pass, so substitutions never cascade into each other.

Written in C. Binary is ~35KB.

## Download

Grab the latest release from [GitHub Releases](https://github.com/atabisz/JivePipe/releases/latest):

**Linux**
- `jive-linux-amd64.tar.gz` — extract and run directly
- `jive_*_amd64.deb` — installs to `/usr/bin`

```bash
# Binary
tar -xzf jive-linux-amd64.tar.gz
./jive

# Deb
sudo dpkg -i jive_*_amd64.deb
```

**Windows**
- `jive-windows-amd64.zip` — extract and run directly

```powershell
Expand-Archive jive-windows-amd64.zip
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
