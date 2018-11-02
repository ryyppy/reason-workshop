/*
We need this script to consistently run BSB on Unix & Windows based systems

In other words, this is essentially doing this:
export BS_CMT_POST_PROCESS_CMD="gentype" bsb x y z
*/

const child_process = require("child_process");
const path = require("path");

const spawn = child_process.spawn;

const isWindows = /^win/i.test(process.platform);

process.env.BS_CMT_POST_PROCESS_CMD = "gentype";

const input = (args = process.argv.slice(2));

const shell = isWindows ? true : false;

spawn("bsb", input, { stdio: ["inherit", "inherit"], shell }).on(
  "exit",
  code => process.exit(code)
);