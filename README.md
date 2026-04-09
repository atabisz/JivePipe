# JivePipe

Translate any text into authentic Harlem Jive slang. Pipe text in, get jive out.

Phrases get swapped, `-ing` endings drop their `g`, and the occasional filler — *daddy-o* — rolls in at random. The translation is single-pass, so substitutions never cascade into each other.

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

Requires [Bun](https://bun.sh).

```bash
bun install
bun run build
```

This produces a standalone `./jivepipe` binary in the project root (no Bun required at runtime).

To install system-wide:

```bash
bun run build:install
```

This builds and moves the binary to `/usr/local/bin/jivepipe`.

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
# → "What's your story, morning glory, daddy-o?"
```

**Run without building (via Bun):**
```bash
bun start
```

## Example output

```
$ echo "The meeting is at the office. My boss wants to talk about money." | jivepipe
The powwow is at the gig spot. My big daddy wants to rap about bread.
```

```
$ echo "Good morning. I don't know what's happening today, but let's go." | jivepipe
Solid morning, daddy-o. I ain't hip to it what's goin' down today, but let's split.
```

## Creative uses

**Jive-ify your git log:**
```bash
git log --oneline | jivepipe
```

**Translate error messages:**
```bash
npm install 2>&1 | jivepipe
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
bun test
```
