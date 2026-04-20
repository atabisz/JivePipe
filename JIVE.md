# Harlem Jive Language Reference

A comprehensive language rules document for the jivepipe translator, grounded in primary historical sources from the 1930s–1950s Harlem jazz scene.

> **Note on Use:** Harlem Jive was an in-group argot with specific social functions — it signaled membership, encoded resistance, and created community boundaries. This reference provides a lexical and phonological approximation for educational and entertainment purposes; it is not a substitute for the lived linguistic tradition. Users seeking authentic engagement are encouraged to consult the primary sources listed in the Historical Context section below.

---

## Table of Contents

1. [Historical Context](#historical-context)
2. [Phonological Rules](#phonological-rules)
3. [Grammatical Rules](#grammatical-rules)
4. [Vocabulary Reference](#vocabulary-reference)
5. [Filler Phrases and Exclamations](#filler-phrases-and-exclamations)
6. [Sentence-Level Transformation Rules](#sentence-level-transformation-rules)
7. [Register Variation and Code-Switching](#register-variation-and-code-switching)
8. [Related Dialects](#related-dialects)
9. [Authenticity Guidelines](#authenticity-guidelines)
10. [JivePipe Gap Analysis](#jivepipe-gap-analysis)

---

## Historical Context

Harlem Jive (also called *jive talk*, *hep talk*, or *Harlemese*) emerged as a distinct linguistic register in Harlem during the **late 1920s–1930s**, reaching its peak in the **1940s**. It developed within the African American jazz community and spread through live performances at Harlem clubs, national radio broadcasts, touring bands, and wartime military service.

Jive was an **argot** — a deliberately coded, in-group language. As historian Eric Hobsbawm observed, it was "an argot or cant designed to set the group apart from outsiders." Fluency in jive signaled membership in the hip jazz community; ignorance of it marked you as a "jeff" (outsider). When terms crossed over to mainstream white usage, they lost their cachet and were replaced — a cycle that made jive one of the most generative slang systems in American English history.

Notable speakers included Cab Calloway, Fats Waller, Ella Fitzgerald, Billie Holiday, Billie Louis Armstrong, and Lester Young. White musicians like Mezz Mezzrow embedded themselves deeply enough in the scene to become part of the lexicon itself.

### Primary Sources

Three foundational texts document authentic period vocabulary:

**1. Cab Calloway's *Hepster's Dictionary* (1938, revised 1944)**
The first dictionary published by an African American; became the official jive language reference of the New York Public Library. Calloway defined jive as "Harlemese speech." Three editions were published: *Cat-ologue: A "Hepster's" Dictionary* (1938), *Professor Cab Calloway's Swingformation Bureau* (1939), and *The New Cab Calloway's Hepsters Dictionary: Language of Jive* (1944).

**2. Dan Burley's *Original Handbook of Harlem Jive* (1944)**
Compiled at the suggestion of Langston Hughes. Sold over 100,000 copies and was translated into French, Italian, Spanish, and Norwegian. Burley (1907–1962) was a journalist and pianist who served as managing editor of *Jet* and is reputedly credited with coining the term "bebop."

**3. Mezz Mezzrow & Bernard Wolfe, *Really the Blues* (1946)**
An autobiography with an extensive glossary documenting vocabulary from the 1920s through 1940s Harlem scene. Mezzrow became so embedded in the scene that his name became slang: "mezz" and "mighty mezz" meant marijuana and an expertly rolled joint respectively.

**Additional sources:**
- Harry "The Hipster" Gibson — glossary in *Boogie Woogie In Blue* (1944); formally introduced the word "hipster"
- Albert Lavada Durst ("Dr. Hepcat") — *Jives of Dr. Hep Cat* (1953)
- Clarence Major — *Juba to Jive: A Dictionary of African-American Slang* (1994)
- Yale Grammatical Diversity Project — grammatical rule documentation

### Relationship to the Harlem Renaissance

The Harlem Renaissance (roughly 1918–1937) preceded and overlapped with the peak jive era. Langston Hughes directly encouraged Dan Burley to compile his handbook, linking the literary Renaissance to jive documentation. The Renaissance's central principle — that Black cultural production had inherent value — provided the intellectual foundation for treating jive as legitimate language deserving codification.

---

## Phonological Rules

Jive phonology was not a separate invention but the natural phonology of **African American Vernacular English (AAVE)** as spoken in 1930s–1940s Harlem. The following rules are systematic, not errors. They are the obligatory features of the register.

### Rule 1: G-Dropping (Velar Nasal Fronting)

The verbal -ing suffix loses its final /g/, producing /in'/:

- `going` → `goin'`
- `working` → `workin'`
- `cooking` → `cookin'`
- `jumping` → `jumpin'`
- `finger-poppin' daddies` (attested: Lord Buckley)

**Critical constraint:** This rule targets the *grammatical -ing suffix* only. It does **not** apply to monosyllabic content words. `sing`, `ring`, `king`, `thing`, `bring`, `swing`, `string`, `sting`, `spring` are **never** reduced. "Sing" never becomes "sin."

**Implementation note:** jivepipe already implements this rule in Phase 3 of `translator.c` with the `ing_exceptions` list. The exceptions list correctly excludes monosyllabic words.

### Rule 2: Consonant Cluster Reduction

Word-final consonant clusters simplify by deleting the final consonant, particularly when both consonants share voicing:

- `best` → `bes'`
- `most` → `mos'`
- `just` → `jus'`
- `last` → `las'`
- `hand` → `han'`
- `cold` → `col'`
- `told` → `tol'`

**Constraint:** Mixed-voicing clusters resist reduction. Past tense -ed can create clusters that reduce, making past tense phonologically invisible in some forms (context disambiguates).

**Implementation note:** jivepipe does not currently implement this rule. It is a lower-priority enhancement — the effect is subtle and best handled through specific dictionary entries rather than a general rule.

### Rule 3: Vowel Elisions and Contractions

Common contracted forms attested in jive sources:

| Standard | Jive Form | Notes |
|----------|-----------|-------|
| am not / is not / are not / have not | ain't | Universal present-tense negative |
| going to | gonna | |
| want to | wanna | |
| got to | gotta | |
| about | 'bout | |
| fixing to (about to) | finna / fixinta | Marks imminent action |
| trying to | tryna | |
| let me | lemme | |
| give me | gimme | |
| kind of | kinda | |

`Ain't` is the single most productive contraction in the system, replacing *am not, isn't, aren't, haven't, hasn't*, and in some speakers' systems *don't/doesn't/didn't*.

### Rule 4: Th-Stopping (Word-Initial Position)

Voiced /th/ moves to /d/ at the start of words:

- `the` → `de`
- `that` → `dat`
- `there` → `dere`
- `them` → `dem`

This is a variable rule — speakers alternate between standard and non-standard realizations depending on social context.

### Rule 5: R-lessness (Non-rhoticity)

/r/ is deleted when not immediately preceding a vowel. Harlem AAVE shared this feature with New York City English generally, but maintained it more consistently:

- `four` → `fo'`
- `your` → `yo'`
- `more` → `mo'`

### Rule 6: Vowel Monophthongization

The diphthong /ai/ monophthongizes to [a:] before voiced consonants and word-finally:

- `ride` → [ra:d]
- `time` → [ta:m]
- `my` → [ma:]

**Constraint:** Does not typically occur before voiceless consonants. `bite`, `rice`, `type` retain the diphthong.

---

## Grammatical Rules

Like phonology, jive grammar draws on the AAVE grammatical substrate. These are systematic linguistic features with precise constraints, not random errors.

### Implementation Tiers

Grammatical rules vary in what they require to implement. Each rule below is marked:

- **Tier 1** — Implementable via string/regex substitution (current jivepipe approach)
- **Tier 2** — Requires part-of-speech (POS) tagging
- **Tier 3** — Requires full parse tree (not currently implemented in jivepipe)

Rules marked Tier 2 or Tier 3 describe the language as it was spoken; jivepipe approximates them through dictionary entries where possible.

---

### Rule 1: Double Negation (Negative Concord)

When a sentence is negative, **all negatable elements are negated**. Multiple negative markers produce a single semantic negation — they reinforce rather than cancel:

- `I don't never have no problems` = I don't ever have any problems
- `I ain't got none` = I don't have any
- `He don't know nothing` = He doesn't know anything
- `Nobody ain't doin' nothin' wrong` = Nobody is doing anything wrong
- `I don't never have no problems with nobody` = I never have any problems with anyone

This is a systematic grammatical rule (negative concord) found in the majority of the world's languages and in English through the 17th century. It is not an error.

**Tier 1** — Partially implementable via phrase substitution (e.g., `anything` → `nothing`, `ever` → `never` in negative contexts). Full application requires sentence-level parse context.

### Rule 2: Be-Deletion / Zero Copula

Present-tense forms of `be` (specifically `is` and `are`) may be deleted where standard English can contract them (Labov's Contraction-Deletion Principle, 1969):

- `He gone` = He's gone
- `She fine` = She's fine
- `You crazy` = You're crazy
- `That real mellow` = That's real mellow
- `He a good cat` = He's a good cat

**Strict constraints:**
- Only `is` and `are` can be deleted. `am`, `was`, and `were` are **never** deleted.
- Deletion is prohibited at clause-final position: *"I don't know where he __"* is ungrammatical.
- Deletion is prohibited in emphatic/contrastive contexts.
- Deletion is prohibited in tag questions.

**Frequency hierarchy:** Deletion most common before `gonna`, then before progressive -ing, then before adjectives/locatives, least common before noun phrases.

**Tier 3** — Requires parse tree to distinguish `is`/`are` from other verbs and to enforce the clause-final prohibition. Not currently implemented in jivepipe.

### Rule 3: Habitual "Be" (Invariant Be)

Uninflected `be` marks **habitual, recurring, or characteristic** actions — not what is happening right now:

- `He be workin' late` = He regularly works late (NOT "he is working right now")
- `The joint be jumpin' on Saturday nights` = The place is routinely lively on Saturdays
- `She be tellin' people she eight` = She is always telling people she's eight

**Critical semantic distinction:**
- `He workin'` = He is working (right now) [zero copula]
- `He be workin'` = He works regularly / He is usually working [habitual aspect]

Negation uses `don't`: `He don't be in school`. Questions use `do/did`: `Do he be comin' home late?`

**Tier 2** — Requires POS tagging to distinguish habitual `be` from other uses of `be`. Not currently implemented in jivepipe.

### Rule 4: Existential "It" Instead of "There"

`It` replaces standard English `there` in existential constructions:

- `It's a cat on the corner` = There's a cat on the corner
- `It ain't nothing going on` = There isn't anything going on
- `It's a party tonight` = There's a party tonight

**Tier 1** — Implementable via string substitution (`There's` → `It's`, `There is` → `It is`).

### Rule 5: Negative Inversion

A negated auxiliary moves to clause-initial position before an indefinite subject for emphatic negation:

- `Can't nobody stop me` = Nobody can stop me (emphatic)
- `Don't nobody know the answer` = Nobody knows the answer
- `Ain't nothing going on` = Nothing is going on

**Constraints:** Contracted negation (n't) is required. Subjects must be indefinite/quantificational (nobody, nothing, everybody). Definite subjects (names, pronouns) are ungrammatical in this construction.

**Tier 3** — Requires parse tree to identify and front the negated auxiliary. Not currently implemented in jivepipe.

### Rule 6: Completive "Done"

Preverbal `done` marks completed action, often with emphasis, surprise, or speaker attitude:

- `I done told you` = I already told you (with emphasis)
- `He done left` = He has already left
- `She done spent all the bread` = She has spent all the money (with disapproval)

**Tier 1** — Partially implementable via phrase substitution (`I already` → `I done`, `already told` → `done told`). Some contexts require POS context to apply correctly.

### Rule 7: Remote Past "BIN" (Stressed Been)

Stressed `BIN` [bee:n] marks events in the distant past or states that have persisted since the remote past:

- `I BIN known that` = I've known that for a long time
- `He BIN married` = He's been married for a long time (and still is)
- `I BIN had that` = I've had that for ages

Cannot combine with specific time markers. With nonverbal predicates, implies the state still holds.

**Tier 3** — Requires prosodic/stress analysis to distinguish BIN from unstressed "been." Not implementable via string substitution.

---

## Vocabulary Reference

All entries are attested in primary sources unless noted. Sources: [C] = Calloway 1938/1944, [B] = Burley 1944, [M] = Mezzrow 1946, [G] = general jive, era-attested.

### Greetings and Farewells

| Term | Meaning | Source |
|------|---------|--------|
| What's your story, morning glory? | How are you? / What's going on? | C |
| What's the word? | What's the news? | B |
| What's buzzin', cousin? | Casual greeting | Swing era, 1943+ |
| Slide me some skin / Gimme some skin | Greeting via handshake | C: "Give me some skin — shake hands" |
| What it is | General greeting or affirmation | G, 1940s |
| Collar me | Come see me; get in touch | C |
| Fall in | Arrive; show up | C |
| See you later, alligator | Farewell | Oral tradition, 1940s; widespread pre-1955 |
| After while, crocodile | Response to "later, alligator" | Paired response, 1940s |
| Cut out / Cut on out | Leave; depart | C, B |
| I'm blowing / I got to blow | I'm leaving | C: "Blow — to leave" |
| Take it slow | Farewell; be careful | G, 1940s |

### Address and Kinship Terms

| Term | Meaning | Source |
|------|---------|--------|
| daddy-o | All-purpose address for a man | B, widespread 1940s |
| cat | Any man; a jazz musician; a hip person | C, from 1930s jazz |
| hep cat (later: hip cat) | A knowledgeable, culturally aware person | C 1938: "a guy who knows all the answers, understands jive" |
| gate / gator | Any man (direct address) | C: "Gate — a male person" |
| Jack | General address for any man | C: "name for all male members of the human race" |
| Jim | A man; general address | B |
| skin | A person (address: "Hey, skin") | B |
| ace | Best friend; top person | G, 1940s |
| chick | A woman or girl | C |
| frail / frail eel / frail sister | A woman; girlfriend | C: "Frail eel — a young girl" |
| queen | An attractive, impressive woman | G, 1940s |
| mop | A woman; girlfriend | M, 1930s–40s |
| stud | A man, especially strong or impressive | M |
| ofay | A white person (possibly pig Latin of "foe") | G, from 1920s; C |
| jeff | An uncool, uninformed person; opposite of hep | G, 1940s |
| viper | A marijuana user; a hep cat of the 1930s | C; Stuff Smith's "If You're a Viper" |
| jitterbug | A swing dancer or fan | C |
| alligator | A jazz/swing devotee; non-musician fan | C |

### Music and Performance Terms

| Term | Meaning | Source |
|------|---------|--------|
| blow | To play an instrument (not just wind instruments); to improvise | C |
| axe / ax | A musical instrument | B, 1930s+ |
| chops | A musician's technical ability (from brass players' embouchure muscles) | C |
| woodshed / shed (v.) | To practice intensively in private | G, 1930s jazz |
| cooking / cooking with gas | Playing exceptionally well | C era, 1930s–40s |
| wail | To play superbly; to perform with great intensity | G, 1940s |
| sender / solid sender | A performer who thrills the audience | C: "Sender — one who sends; a hot player" |
| cut | To outperform another musician in a cutting contest | Jazz tradition, 1920s–30s |
| jam / jam session | An informal improvised performance | G, 1930s; standard jazz terminology |
| lick | A short musical phrase; a solo passage | G, from 1920s |
| riff | A repeated musical phrase | Swing era, 1930s |
| in the groove | Playing perfectly; in deep sync with the music | C; origin of "groovy" |
| real gone | Transcendently good; beyond excellent | C: "Gone — out of this world" |
| gig | A musical engagement; a job | G, from 1920s |
| sit in | To join a band temporarily | Jazz tradition, 1930s–40s |
| platter | A phonograph record | G, 1930s–40s |
| wax | A phonograph record; to record | G, 1930s |
| number | A song or musical piece | G |
| outfit | A band or musical group | C |
| the joint is jumping | The venue is lively, the music is hot | C; also a Fats Waller song (1938) |
| killer-diller | Something sensationally exciting | C: "Killer-diller — a great thrill" |

### Money and Material Possessions

| Term | Meaning | Source |
|------|---------|--------|
| bread | Money | Attributed to Lester Young, 1940s |
| loot | Money; cash | B |
| scratch | Money | G, 1930s–40s |
| clams | Dollars | G, 1930s |
| gold | Money | G |
| threads | Clothes | C: "Threads — suit, dress, clothes" |
| vine / vines | A suit; clothes | C: "Vine — a suit of clothes" |
| drape / drapes | Clothes, especially a suit | Zoot suit era, 1940s |
| togged to the bricks | Dressed to the nines; perfectly dressed | C |
| lid | A hat; also the head | C: "Lid — a hat" |
| sky piece | A hat | C |
| stomps / stompers | Shoes; feet | B |
| kicks | Shoes | G, 1940s |
| zoot suit | High-waisted, wide-legged suit with long coat; "the only truly American civilian suit" | C 1938/1944 |
| short | An automobile | C: "Short — a car" |
| wheels | An automobile | G, 1940s |
| pad | Originally a bed; by extension, one's apartment or home | C: "Pad — bed"; expanded meaning late 1940s |
| stash | A hiding place; one's personal supply | G, 1940s |
| cubby | A small room | G |

### Approval and Affirmation

| Term | Meaning | Source |
|------|---------|--------|
| solid | Excellent; agreeable; all-purpose affirmation | C: "Solid — great, swell" |
| copasetic / copacetic | Excellent; fine; all is well | Attested from 1919; attributed to Bill "Bojangles" Robinson; C |
| the most | The best; superlative praise | G, 1940s; peak bebop-era usage |
| real gone / gone | Transcendently good; beyond excellent | C: "Gone — out of this world" |
| righteous | Excellent; authentic; the real thing | C: "Righteous — splendid, okay"; M |
| hip | Aware; knowledgeable; in the know | Post-WWII dominant form (replaced "hep") |
| hep | Earlier form of "hip"; knowledgeable, aware | C 1938 |
| dig / dig it | To understand; to appreciate; to approve | C, 1930s–40s jazz |
| a gasser / a gas | Something extremely funny or enjoyable | G, 1940s |
| mellow | Good; pleasing; relaxed and happy | C: "Mellow — all right, fine" |
| fine as wine | Extremely good or attractive | G, 1940s |
| a hummer | Exceptionally good | C: "A hummer — exceptionally good" |
| groovy / in the groove | Excellent; perfectly in sync | From "in the groove" (1930s); "groovy" by 1940s |
| out of sight | Extraordinary; beyond excellent | G, 1940s |
| crazy | Wonderful; amazing (positive) | Bebop era, late 1940s; Charlie Parker's circle |
| cool | Fashionable; excellent; calm and composed | Lester Young, 1940s; entered mainstream via bebop |
| sharp | Well-dressed; stylish; impressive | G, 1930s–40s |
| killer | Impressively good (shortened from killer-diller) | G, 1940s |

### Disapproval and Negation

| Term | Meaning | Source |
|------|---------|--------|
| nowhere | Bad; worthless; out of place | C: "Nowhere — no good, out of place" |
| a drag | Something boring or unpleasant | G, 1940s |
| square | An unhip, conventional, boring person; someone out of touch with jazz | First attested 1944; possibly from a conductor's rigid four-beat motion |
| moldy fig | A person with outdated musical tastes; a Dixieland purist who rejected swing or bop | Late 1930s–40s jazz criticism |
| corny / corn | Old-fashioned; stale; unsophisticated | C: "Corny — old-fashioned, stale" |
| icky | A person ignorant of jazz; someone unhip | C: "Icky — one who is not hip, a stupid person" |
| lame | Dull; uninspired; unhip | G, 1940s |
| jive (adj.) | False; dishonest; insincere | C: "Jive — to kid along" |
| sad | Inferior; below standard; pathetic | G, 1940s (not the standard emotional sense) |
| beat | Exhausted; also: broke, without money | G, 1940s; carried into Beat Generation vocabulary |
| offtime jive | Nonsense; speech that misses the mark | C |
| jeff | A dull, conventional person | G, 1940s |

### Verbs of Action

| Term | Meaning | Source |
|------|---------|--------|
| cut out | To leave | C |
| split | To leave quickly | G, 1940s |
| blow | To leave; to play; to fail | C: multiple senses documented |
| dig | To understand; to appreciate; to listen attentively | C |
| lay it on me | Tell me; give it to me | G, 1940s |
| run it down | To explain something in detail | G, 1940s |
| cop | To get; to obtain | C: "Cop — to get, to obtain" |
| collar | To understand; to grasp; to obtain | C: "Collar — to get, to obtain, to comprehend" |
| knock | To give ("Knock me a kiss") | C: "Knock — to give" |
| fall in | To arrive; to come | C |
| fall out | To be overcome with laughter or emotion; to faint | G, 1940s |
| hip (v.) | To inform; to make aware ("Let me hip you to this") | G, 1940s |
| lamp | To look at; to see | C: "Lamp — to look, see" |
| peep | To look at | G, 1940s |
| truck / truckin' | To go; to walk; also the "Truckin'" dance | G, 1930s Harlem |
| scoff | To eat | C: "Scoff — to eat" |
| sound (v.) | To speak; to talk | G, 1940s |
| kill | To impress greatly; to overwhelm with excellence | G, 1940s: "She killed 'em" |
| kick off | To start | G |
| lay it to rest | To finish | G |

### People and Body

| Term | Meaning | Source |
|------|---------|--------|
| wig | The mind; the brain | C: "Wig — head"; "blow your wig" = lose your mind |
| lid | The head; also: a hat | C (dual meaning) |
| peepers | Eyes | G, 1930s–40s |
| gams | Legs | G, 1930s–40s |
| stomps | Feet; shoes | B |
| mug | Face | G, 1930s–40s |
| claws | Hands | G, 1940s |
| frame | The body | G, 1940s |
| noggin | Head | G |

### Places and Environments

| Term | Meaning | Source |
|------|---------|--------|
| pad | Bed; room; apartment; one's home | C |
| joint | Any establishment — club, bar, venue, building | G, 1930s–40s |
| scene | A place; a situation; the current environment | G, 1940s |
| turf | One's neighborhood; territory | G, 1940s urban slang |
| spot | A specific venue or location | G, 1940s |
| the Apple / the Big Apple | New York City; Harlem | G, 1930s jazz |
| the stroll | The main strip; the avenue where people promenade | G, 1930s–40s Harlem |
| the rack | Bed | G, 1940s |
| tea pad | An after-hours Harlem club with marijuana and jazz | G, 1930s–40s |

### Social Stratification and Venue Terms

These terms encode the social hierarchy and physical spaces of Harlem Jive culture. They are tightly linked to register — who you were with and where determined which end of this vocabulary you reached for.

#### Social Standing

| Term | Meaning | Source |
|------|---------|--------|
| dicty | High-class; affecting airs; snobbish — but used admiringly of genuine elegance | B: "dicty — high class, nifty" |
| ofay | A white person (possibly pig Latin of "foe") | G, from 1920s; C |
| gray | A white person (cooler, less charged register than "ofay") | M, 1940s |
| spade | A Black person (in-group term; reclaimed within the community) | M |
| oreo | A Black person perceived as acting white; "black outside, white inside" | G, emerging 1940s |
| high-yellow | A light-skinned Black person; term reflecting intra-community color politics | G, 1920s–40s |
| oftime / off time | Out of step; not hip; failing to meet the standard | C: "offtime jive — stuff that is not hip" |
| lame | An outsider; an unhip person | G, 1940s |
| hincty | Snobbish; putting on airs; looking down on others | C: "hincty — snobbish" |

#### Venues and Spaces

| Term | Meaning | Source |
|------|---------|--------|
| the Savoy | The Savoy Ballroom (Lenox Ave, 140th St) — the premier Harlem dance venue, integrated, site of Lindy Hop | G, 1926–1958 |
| Minton's | Minton's Playhouse (Cecil Hotel, 118th St) — birthplace of bebop; weekly Monday jam sessions | G, 1938–1974 |
| the Apollo | The Apollo Theater (125th St) — the central stage for Black performance; Amateur Night launched careers | G, 1934+ |
| Small's Paradise | Small's Paradise (135th St) — known for dancing waiters; a major Harlem social hub | G, 1925–1986 |
| the cutting session | A competitive improvisation contest, especially at Minton's — musicians "cut" each other | Jazz tradition, 1930s–40s |
| the bandstand | The stage at a venue; the performative space | G |
| after-hours | The period after official closing when informal playing continued | G, 1930s–40s |
| the gig circuit | The touring network of Black venues (the "Chitlin' Circuit") | G, 1930s–40s |

#### Dances and Movement

| Term | Meaning | Source |
|------|---------|--------|
| Lindy Hop | The foundational swing dance born at the Savoy; named for Lindbergh's 1927 flight | G, 1928+ |
| truckin' | A walking dance step with finger-pointing; also general: to move, to go | G, 1930s |
| the big apple | A circle-formation swing dance popularized from Harlem | G, 1937 |
| jitterbugging | Energetic swing dancing; by extension, any frenzied movement | C, 1930s+ |
| get your kicks | To dance; to have a great time | G, 1940s |

---

## Filler Phrases and Exclamations

These are appended to statements for rhythm, emphasis, and in-group signaling. Authentic patterns attested in primary sources:

| Filler | Function | Source |
|--------|----------|--------|
| daddy-o | All-purpose address; punctuates statements | B, 1940s ubiquitous |
| dig? / you dig? | Tag question: "Do you understand?" | G, 1940s |
| can you dig it? | "Do you understand / appreciate this?" | G, 1940s |
| solid! | Exclamation of approval or agreement | C |
| man! | General emphasis: "Man! That cat can blow!" | G, 1940s |
| no jive | "Seriously; I'm not kidding; for real" | G, 1940s |
| I ain't jivin' | "I'm serious; I'm not kidding" | G, 1940s Harlem |
| you hip? / you hip to that? | "Are you aware of this?" | G, 1940s |
| Jack | Filler address: "Listen, Jack" | C |
| baby | Warm, familiar filler address | G, 1940s |
| now you're cooking (with gas) | "Now you've got it; you're doing great" | G, swing era |
| that's the lick | "That's exactly right" | G, 1940s |
| what's the riff? | "What's the deal? What's going on?" | G, 1940s |
| like | Pause filler (pre-dates beatniks; already in 1940s jive) | G, 1940s |
| gate | Used as filler address: "What's happening, gate?" | C |

**Authentic placement pattern:** In authentic Jive speech, fillers were not random insertions — they fell at **phrase boundaries and rhythmic stress points**, giving speech its musical timing. Fillers typically appear: (a) after the main clause at sentence end, (b) after a comma-natural pause mid-sentence, or (c) as a tag question closing a statement. Fillers dropped mid-phrase between subject and verb, or between verb and object, are arhythmic and inauthentic.

**Implementation note:** jivepipe's current filler list includes `— dig?`, `, daddy-o`, `— you hip?`, `, can you dig it?`, `— solid!`, `, no jive`, `— that's the real deal`, `, baby`, `— lay it on me`, `, feel me?`, `— you know the scene`. All except `, feel me?` (modern AAVE, 1990s) are era-appropriate. The current ~20% injection rate is a pragmatic approximation; authentic density varied by speaker and social context.

---

## Sentence-Level Transformation Rules

### 1. Phrase-First Substitution (Longest Match Wins)

Always attempt phrase substitutions before single-word substitutions. "You know what I mean" should match the phrase entry before "know" is independently replaced by "dig." This prevents double-substitution artifacts.

### 2. Case Preservation

Replacement terms should preserve the capitalization of the original:
- `Hello` → `Hey there, Daddy-O` (first letter capitalized)
- `HELLO` → `HEY THERE, DADDY-O` (all caps preserved)

### 3. Contraction Preference

Jive speech strongly prefers contracted and elided forms. Standard English full forms should contract:
- `I am not` → `I ain't`
- `going to` → `gonna`
- `do not` → `don't`

### 4. Negation Conversion

Standard negative constructions should add secondary negation markers on indefinite complements when naturally possible:
- `I don't have anything` → `I ain't got nothing`
- `Nobody is doing anything` → `Nobody ain't doin' nothin'`

### 5. Evaluative Inversion

When a standard English statement uses a neutral evaluative adjective that jive has a specific replacement for, prefer the jive term even when the semantic intensity differs slightly:
- `That's good` → `That's solid`
- `That's bad` → `That's nowhere`

### 6. Address Term Insertion

Jive speech frequently punctuates direct address and statements with address terms. These can be appended as fillers (daddy-o, baby, Jack, gate) or inserted mid-utterance.

### 7. Verbal -ing Reduction

Drop the final `g` from all verbal -ing forms (gerunds, participles, progressives) except monosyllabic content words. See Phonological Rule 1 for the complete exceptions list.

---

## Register Variation and Code-Switching

Harlem Jive was not a single undifferentiated style — it was one register in a speaker's full repertoire. Speakers shifted fluidly based on audience, venue, and era.

### The Three-Register System

| Register | Context | Vocabulary Density | Grammar Features |
|----------|---------|-------------------|-----------------|
| **Full Jive** | In-group, all-Black setting (Minton's cutting session, tea pad, among close cats) | Maximum — dense vocabulary, heavy filler, all phonological rules applied | Full AAVE grammar: habitual be, copula deletion, negative concord |
| **Mixed Jive** | Integrated settings (Savoy Ballroom, mixed-race jam sessions) | Moderate — key terms retained, toned-down density | Selective — g-dropping and contractions present; copula deletion reduced |
| **Performed Jive** | Public performance for mainstream audiences (radio, recordings, Calloway's stage shows) | Stylized — iconic terms for effect, comprehensible to outsiders | Mostly standard grammar with jive vocabulary overlay |

Calloway's Hepster's Dictionary was explicitly oriented toward the **Performed Jive** register — it was a crossover marketing tool. Burley's Handbook documents **Full Jive** more authentically.

### Hot Era vs. Cool Era Vocabulary

The linguistic style shifted markedly between the swing peak and the bebop consolidation:

**Hot Era (1928–1942):** Extroverted, crowd-pleasing vocabulary. Exclamations, high-energy affirmations, dance terms dominant.

| Representative Terms | Character |
|---------------------|-----------|
| `killer-diller`, `solid sender`, `the joint is jumpin'` | High-energy, performative |
| `hep cat`, `hep to the jive`, `alligator` | Swing-oriented identity markers |
| `gate`, `Jack`, `daddy-o` | Direct, warm address terms |
| `togged to the bricks`, `zoot suit`, `vine` | Zoot culture, visual self-presentation |

**Cool Era (1945–1952):** Introverted, ironic vocabulary. Understatement, intellectual distance, anti-entertainment stance.

| Representative Terms | Character |
|---------------------|-----------|
| `cool`, `hip` (replacing `hep`), `out`, `far out` | Restrained aesthetic; anti-mainstream |
| `crazy`, `the most`, `bad` (positive) | Semantic inversion; insider readings |
| `bread`, `charts`, `bopper` | Professionalized; less theatrical |
| `funky`, `earthy`, `back to basics` | Rejection of swing's showmanship |

**The hep-to-hip shift** is the clearest date marker: using `hep` after ~1947 marked you as behind the times. A period-accurate jivepipe output might reflect this by treating `hep` as the earlier form and `hip` as the later form.

### Social Stratification and Register

The social vocabulary in the [Social Stratification and Venue Terms](#social-stratification-and-venue-terms) section maps directly to register choice:

- `dicty` was used admiringly in Full Jive but ironically in Mixed Jive (class resentment from working-class Harlemites toward bourgeois Black society)
- `ofay` was Full Jive in-group; `gray` was the cooler, safer form in mixed company
- Venue terms (Minton's, Savoy) carried implicit register signals — Minton's implied Full/Cool Jive; Savoy implied Mixed/Hot Jive

---

## Related Dialects

### Swing Era / Big Band Slang (1935–1945)

Swing slang was more populist and dance-oriented than core Harlem Jive. It spread to white middle-class youth via radio and dance halls. Cab Calloway's dictionary explicitly served this crossover audience. By contrast, core Harlem Jive retained more in-group function among Black Harlemites.

**Swing-specific terms:**

| Term | Definition | Distinction from Core Jive |
|------|-----------|--------------------------|
| jitterbug | A swing dancer; swing fan | Swing-specific; core jive speakers more likely said "cat" |
| alligator | Swing music fan (from "See you later, alligator") | Dance culture term |
| canary | A female vocalist with a big band | Music-industry term; not typical jive |
| sideman | A band member (not the leader) | More formal than jive usage |
| one-nighter | A single engagement in a town | Band business term |
| killer-diller | Something sensationally exciting | Shared with jive; especially popular in swing |
| jump / jump band | Uptempo swing; a driving band | Swing-specific genre term |
| reet / reet pleat | "Right"; correct; good. "Reet pleat" = the correct zoot suit fold | Swing/zoot culture; phonological play on "right" |
| solid sender | A performer who thrills the audience | Calloway 1944; became a swing catchphrase |
| hep to the jive | In the know about music and culture | Swing's fuller form of "hip"; fell from favor in bop era |
| trickeration | Complex arranging; musical tricks | Swing arrangers' term |

### Bebop Slang (1945–1960)

Bebop musicians deliberately distanced themselves from the swing establishment. The speech shift was intentional — boppers rejected the entertainer role swing musicians played for white audiences. Where swing was populist, bop was elitist and intellectual.

**The hep-to-hip transition:** The single most documented linguistic shift of the era. When "hep" entered mainstream white usage, bop musicians replaced it with "hip." By the early 1950s, using "hep" marked you as a square. Harry Gibson's 1947 song directly addressed this transition.

**The cool/hot dichotomy:** The central aesthetic shift from swing to bop was *hot vs. cool*. Swing valued "hot" — extroverted, crowd-pleasing, energetic. Bop valued "cool" — introverted, restrained, intellectually complex. Lester Young embodied this shift; the entire Cool Jazz movement took its name from this linguistic-aesthetic revolution.

**Bebop-specific terms:**

| Term | Definition | Relationship to Earlier Jive |
|------|-----------|------------------------------|
| hip (replacing hep) | Aware; knowing | Deliberate replacement; "hep" was now square |
| cool | Restrained excellence; emotional control | Popularized by Lester Young; defined the bop aesthetic |
| crazy | Wonderful; amazing (positive) | New positive usage in bop; not in Calloway |
| far out | Extremely good; avant-garde | Bop/post-bop era |
| out / way out | Avant-garde; advanced; beyond conventional | Bop musicians' self-description |
| bad (meaning good) | Excellent; impressive | Emerging late 1940s bop circles |
| funky | Earthy; raw; soulful; back-to-basics | Originally negative (smelly); reclaimed as positive earthiness |
| bread | Money | Attributed to Lester Young; standard across bop |
| charts | Musical arrangements; sheet music | Bop-era formalization |
| bebop / bop | The music itself; onomatopoeic two-note phrase | Burley "reputedly" coined the term |
| bopper | A bebop musician or devotee | Stock character by 1950s |

### AAVE Overlap and Distinctions

**Key distinctions between Harlem Jive and AAVE:**

1. **Jive was an argot; AAVE is a dialect.** Jive was intentionally coded to set the group apart from outsiders. AAVE is a full linguistic system with its own grammar, phonology, and pragmatics — not a slang register.

2. **Jive vocabulary was performative; AAVE vocabulary is communal.** Jive terms were often coined by specific individuals (Lester Young coined "bread," Cab Calloway systematized the dictionary) and spread through performance. AAVE vocabulary emerges from community usage.

3. **AAVE grammatical features did not come from jive.** Features like habitual `be`, copula deletion, remote past `BIN`, and negative concord are structural features of AAVE as a language system. They predate jive. Jive speakers used them because they spoke AAVE — jive did not invent them.

4. **Jive was era-bound; AAVE is continuous.** Jive as a distinct register peaked 1938–1948. AAVE has been a continuously evolving linguistic system from its origins through the present day.

**Terms that became permanent AAVE (and often general American English):**

| Term | Trajectory |
|------|-----------|
| cool | Perhaps the most successful slang export in English history; fully mainstream |
| hip | Permanent AAVE; also mainstream via "hipster" |
| dig | Remained AAVE through 1970s; still understood |
| cat | Remained AAVE; less common now |
| pad | Entered general slang via Beat Generation |
| gig | Fully mainstream; standard in music and general employment |
| bread (money) | Active AAVE through 1980s |
| square | Remained AAVE; still active |
| bad (positive) | Fully flowered in 1960s–70s AAVE; went mainstream (Michael Jackson, 1987) |
| funky | Became genre name; fully mainstream |

**Terms that stayed niche or became archaic:**

| Term | Why |
|------|-----|
| gate | Replaced by other address terms; archaic by 1950s |
| ofay | Considered offensive; declined |
| hep | Deliberately replaced by "hip"; became a marker of being out of date |
| killer-diller | Compound forms dated quickly |
| icky / jeff | Period-specific; replaced by newer terms |
| frail | Sexist connotation became apparent |
| togged to the bricks | Vivid but complex; replaced by simpler expressions |
| viper | Tied to specific 1930s marijuana subculture |

---

## Authenticity Guidelines

### Era Boundaries

Authentic Harlem Jive is **1928–1952**. Terms coined outside this window require clear attestation before inclusion.

**Avoid:**
- Terms from 1960s+ AAVE that weren't present in the Harlem era
- Terms invented for comedic effect in Hollywood films or TV shows
- Beatnik-era terms (1955–1963) unless also attested in primary jive sources
- Hip-hop era terminology (post-1979)

### Specific Terms to Avoid in a Period-Accurate Implementation

| Term | Problem |
|------|---------|
| homeboy | Emerged in Chicano/Black usage in the 1960s–70s |
| feel me? | Modern AAVE, 1990s+ |
| twenty-four seven (for "always") | Modern expression, not period |
| for real though | Modern AAVE phrasing |
| in the cut | More modern AAVE than 1940s jive |
| the ginchiest | 1959 (Maynard G. Krebs on *Dobie Gillis*); post-period |
| brand-spanking | General colloquial, not specifically jive |

### Fabrication Warning

Several terms in wide circulation online as "Harlem Jive" are invented or misattributed:
- "Dig me, daddy-o?" — overused in comedic parody; the authentic construction is "Dig?" or "You dig?"
- Extended compound negatives like "nowhere near boss" or "nowhere near fine" — constructed for humor, not attested
- Body-part compounds like "soul pocket" (heart) or "lid holder" (head) — not found in primary sources

### Drug Vocabulary

Authentic period jive contains extensive marijuana vocabulary: `gage`, `muggles`, `mezz`, `tea`, `reefer`, `pot`, `stick of tea`, `lid` (one ounce), `teapad`, `T-man`, `vipers`, `light up`, `puff`, `mugglin'`. This was a genuine coded sub-lexicon. The jivepipe translator's general-audience use case may justify omitting these terms, but they are historically accurate.

---

## JivePipe Gap Analysis

### Confirmed Authentic (existing dictionary.h entries)

The following current entries have strong primary-source attestation and should be retained:
`bread`, `cat`, `chick`, `dig`, `solid`, `righteous`, `pad`, `threads`, `lid`, `stomps`, `gig`, `joint`, `turf`, `hip`, `square`, `nowhere`, `a drag`, `copasetic`, `daddy-o`, `cut out`, `split`, `blow`, `cop`, `loot`, `clams`, `platter`, `wax`, `fuzz`, `togged to the bricks`, `the early bright`, `the early black`, `ace`, `peepers`, `gams`, `mug`, `frame`, `wig`, `sawbones`, `hep cat`, `the most`, `real gone`, `groovy`

### Inauthentic / Anachronistic (consider replacing)

| Current Term/Phrase | Issue | Suggested Replacement |
|---------------------|-------|----------------------|
| `homeboy` (for buddy) | 1960s–70s, not 1940s jive | `ace`, `gate`, `Jack` |
| `, feel me?` (filler) | Modern AAVE, 1990s+ | `, you dig?` or `, dig?` |
| `twenty-four seven` (for always) | Modern expression | `from sun up to sun down` or `all the time, daddy-o` |
| `for real though` (for actually) | Modern AAVE | `no jive` |
| `in the cut` (for basically) | More modern AAVE | `on the real` or `dig this` |
| `brand-spanking` (for new) | General colloquial, not jive | `fresh-pressed` |
| `the ginchiest` | 1959 TV slang | `the most` or `real gone` |
| `soul pocket` (for heart) | Not attested | `ticker` |
| `lid holder` (for head) | Not attested | `wig` (already in dict for brain) |
| `shop on the square` (for store) | Not attested | `the commissary` |
| `the square factory` (for school) | Not attested | `the hip grinder` |
| `square bylaws` (for rules) | Not attested | `the straight-up code` |
| `nowhere near boss` (for small) | Not attested | `short`, `a lightweight` |
| `nowhere near fine` (for ugly) | Not attested | `beat`, `a real drag to look at` |

### Authentic Terms Missing from Current Dictionary

High-value additions with strong primary-source backing:

| Term | Replace / Add As | Definition | Source |
|------|-----------------|-----------|--------|
| `collar` | verb | To understand; to grasp | C |
| `gate` | address | Any man (direct address) | C |
| `Jack` | address | Any man (direct address) | C |
| `frail` | noun | A woman | C |
| `killer-diller` | adj | Something sensationally good | C |
| `sender` / `solid sender` | noun | A thrilling performer | C |
| `scoff` | verb | To eat | C |
| `lamp` | verb | To look at | C |
| `knock` | verb | To give | C |
| `fall in` | verb | To arrive | C |
| `sky piece` | noun | A hat | C |
| `short` | noun | A car | C |
| `vine` / `vines` | noun | A suit; clothes | C |
| `icky` | adj | Unhip; ignorant of jazz | C |
| `truck` / `truckin'` | verb | To go; to walk | G |
| `scratch` | noun | Money | G |
| `kicks` | noun | Shoes | G |
| `wail` | verb | To play superbly | G |
| `sound` | verb | To speak | G |
| `stud` | noun | A man (strong/impressive) | M |
| `fall out` | verb | To be overcome; to faint | G |
| `hip` (v.) | verb | To inform; to make aware | G |
| `kill` | verb | To impress greatly | G |
| `mellow` | adj | Good; pleasing; calm | C |
| `a hummer` | noun phrase | Something exceptionally good | C |
| `crazy` | adj (positive) | Wonderful; amazing | Bebop era |
| `cool` | adj | Excellent; composed | Lester Young |

---

*Sources: Cab Calloway's Hepster's Dictionary (1938–1944) [C]; Dan Burley's Original Handbook of Harlem Jive (1944) [B]; Mezz Mezzrow & Bernard Wolfe, Really the Blues (1946) [M]; General jive, era-attested [G]; Yale Grammatical Diversity Project (AAVE grammar rules); Wikipedia synthesis of primary source content.*
