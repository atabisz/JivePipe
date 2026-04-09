#!/usr/bin/env bun
import { createInterface } from "node:readline";
import { translateLine } from "./translator";

async function printTranslated(lines: AsyncIterable<string> | Iterable<string>) {
  for await (const line of lines) {
    process.stdout.write(translateLine(line) + "\n");
  }
}

async function main() {
  const filePath = process.argv[2];

  if (filePath) {
    const text = await Bun.file(filePath).text();
    await printTranslated(text.split("\n"));
    return;
  }

  const rl = createInterface({ input: process.stdin, crlfDelay: Infinity });
  await printTranslated(rl);
}

main();
