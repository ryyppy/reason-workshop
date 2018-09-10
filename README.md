# reason-workshop

This repository contains all the code snippets & examples used in the
presentation slides.

**Important Links:**

- [Sketch.sh (Online REPL)](https://sketch.sh)
- [Reason Playground](https://reasonml.github.io/en/try.html)
- [Reason Docs](https://reasonml.github.io/docs/en/quickstart-javascript.html)
- [ReasonReact Docs](https://reasonml.github.io/reason-react/)
- [BuckleScript Docs](https://bucklescript.github.io/docs/en/installation.html)
- [Redex (BS library Index)](https://redex.github.io)
- [Discord Channel](https://discord.gg/reasonml)


## Setup

This section explains how to set up your editor and how to build /
compile the examples.  After completing all steps, you should be able
to see type-errors / autocompletion in your editor. If there are any
troubles, please ask your workshop instructor for support.

### Cleanup for older Reason installations

If you have been using Reason a while ago, especially with VSCode, please uninstall any Reason / OCaml related plugins from your VSCode installation first.

Please make sure to uninstall any existing `reason-cli` installations via `npm`:

- `npm -g ls reason-cli` 
- If the command above delivered results, please run: `npm -g remove reason-cli`

### Editor

- Download [VSCode](https://code.visualstudio.com/)
- Install VSCode plugin: [reason-vscode](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode#overview) by **Jared Forsyth**

You can find a more descriptive article on my development workflow with VSCode [right here](https://medium.com/@ryyppy/a-quick-look-on-my-reasonml-workflow-with-vscode-637685f9417a).

### Building the project

Make sure to run `npm install` before trying to build the source.

```sh
# For a single build run
npm run bs:build

# For watch mode building (recommended to run in your VSCode terminal so
# it's easier to see the compiler output next to the code)
npm run bs:watch
```

Note: If you don't do an initial build before using your editor, you will see a lot of error messages. This is because there aren't any build artifacts to inspect for the plugin. So make sure to run the watch mode before coding.

### Extra: Install BuckleScript CLI

BuckleScript also offers a CLI, called `bsb`. You can install it via npm:

```
npm install -g bs-platform
```

Later on for this workshop we need this tool to add BS to an existing
JS project... in every project you are required to add `bs-platform`
as a devDependency, so usually it's not really necessary to actually
have it installed globally.

## Overview

- The examples used in the slides can be found in `src/examples`
- Exercise files should be put in `src` directly

## Glossar

- **BuckleScript** - The Reason-to-JS compiler platform used in this workshop
- **refmt** - The Reason pretty-printer used for reformatting code in your editor ("Prettier for reason")
- **Interop** - This refers to the interoperability layer in **BuckleScript**

## Tips & Tricks

**Bucklescript builds the code without any warnings, but my editor still complains about type errors**

Sometimes it happens that VSCode gets out of sync with the backing Language Server process and it reports type errors which are actually not there (e.g. caused by moving files around etc).

Always check the output of your BuckleScript process first. If BuckleScript doesn't yield any errors, then try closing tabs / saving all relevant files and reopen them to sync up the error reporting.

**I get really confusing type errors and I don't know what to do**

Having a type-system with strong type inference is usually very
confusing in the beginning. Always check out the output of your
BuckleScript process in your terminal, since it uses a plugin which
shows you more human-friendly errors and offers ways to fix them
(especially for common ReasonReact related errors).
