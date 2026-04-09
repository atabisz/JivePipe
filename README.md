# JivePipe

Translate any text into authentic Harlem Jive slang. Pipe text in, get jive out.

Phrases get swapped, `-ing` endings drop their `g`, and the occasional filler — *daddy-o* — rolls in at random. The translation is single-pass, so substitutions never cascade into each other.

Written in C. Binary is ~35KB.

## Download

Grab the latest release from [GitHub Releases](https://github.com/atabisz/JivePipe/releases/latest):

**Linux**
- `jivepipe-linux-amd64.tar.gz` — extract and run directly
- `jivepipe_*_amd64.deb` — installs to `/usr/bin`

```bash
# Binary
tar -xzf jivepipe-linux-amd64.tar.gz
./jivepipe

# Deb
sudo dpkg -i jivepipe_*_amd64.deb
```

**Windows**
- `jivepipe-windows-amd64.zip` — extract and run directly

```powershell
Expand-Archive jivepipe-windows-amd64.zip
.\jivepipe.exe

# Pipe in PowerShell
Get-Content sometext.txt | .\jivepipe.exe
```

## Build

Requires `gcc` and `make`.

```bash
make
```

This produces a stripped `./jivepipe` binary (~35KB) in the project root.

To install system-wide:

```bash
sudo make install
```

This installs to `/usr/local/bin/jivepipe`.

## Usage

**Pipe from stdin:**
```bash
cat sometext.txt | jivepipe
```

**Pass a file directly:**
```bash
jivepipe sometext.txt
```

**Inline with echo:**
```bash
echo "Hello, how are you doing today?" | jivepipe
# → "Hey there, daddy-o, what's your story, morning glory doin' today?"
```

## Example output

```
$ echo "The meeting is at the office. My boss wants to talk about money." | jivepipe
The powwow is at the gig spot. My big daddy wants to rap about bread.
```

```
$ echo "Good morning. I don't know what's happening today, but let's go." | jivepipe
Solid mornin', daddy-o. I ain't hip to it what's goin' down today, but let's split.
```

## Creative uses

**Jive-ify your git log:**
```bash
git log --oneline | jivepipe
```

**Translate error messages:**
```bash
make 2>&1 | jivepipe
```

**Pipe man pages through it:**
```bash
man ls | col -b | jivepipe | less
```

**Liven up a meeting agenda:**
```bash
cat agenda.txt | jivepipe > agenda-jive.txt
```

**Commit message translator (for posterity):**
```bash
git log --format="%s" | jivepipe
```

**Pipe in your README for a vibe check:**
```bash
cat README.md | jivepipe
```

## Development

```bash
make
make clean
```
