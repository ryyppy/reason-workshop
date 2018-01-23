# reason-workshop

This repository contains all the code snippets & examples used in the
presentation slides.

**Important Links:**

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

### Editor

**Install reason-cli ([Docs](https://reasonml.github.io/docs/en/global-installation.html#recommended-through-npm-yarn))**

```
# On MacOS:
npm install -g https://github.com/reasonml/reason-cli/archive/3.0.4-bin-darwin.tar.gz 

# On Linux:
npm install -g https://github.com/reasonml/reason-cli/archive/3.0.4-bin-linux.tar.gz

# Verify your installation (command should yield this output)
readlink `which ocamlmerlin refmt ocamlmerlin-reason`

# Should output something similar like this:
../lib/node_modules/reason-cli/.bin/ocamlmerlin
../lib/node_modules/reason-cli/.bin/refmt
../lib/node_modules/reason-cli/.bin/ocamlmerlin-reason
```

After that, install your **editor plugin** for syntax-highlighting and
autocompletion
([Docs](https://reasonml.github.io/docs/en/editor-plugins.html#officially-supported-editors))**


### Testing your setup

```sh
# Tip: You probably enjoy this the best inside your Editor terminal
# Install all project dependencies (+ the BuckleScript build system)
yarn install

# Open new tab and run the BuckleScript compiler in watch mode
yarn run bs:watch
```

After running your BS compiler in the background, you will be able to
play around with the examples with compiler warnings etc.


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

- **Merlin** - Merlin is your editor helper process to give you code-completion & type information
- **BuckleScript** - The Reason-to-JS compiler platform used in this workshop
- **refmt** - The Reason pretty-printer used for reformatting code in your editor ("Prettier for reason")
- **rtop** - The Reason REPL (interesting for running Reason code interactively in your terminal)
- **Interop** - This refers to the interoperability layer in **BuckleScript**

## Tips & Tricks

**Bucklescript builds the code without any warnings, but my editor still complains about type errors**

This usually happens if you are building a module and later on change
some type / function signatures. Merlin will not pick up the changes
right away, so quit the `yarn run bs:watch` process, run `yarn run
bs:clean` and start the watch mode again.

For the same reasons, sometimes file tabs of certain editors (VSCode)
get out of sync with Merlin. Closing and reopening the files should
help as well.

**I get really confusing type errors and I don't know what to do**

Having a type-system with strong type inference is usually very
confusing in the beginning. Always check out the output of your
BuckleScript process in your terminal, since it uses a plugin which
shows you more human-friendly errors and offers ways to fix them
(especially for common ReasonReact related errors).
