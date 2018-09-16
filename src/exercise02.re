/*
Tip 1)
Use the `Belt.List` module for useful utility functions.
Alternatively, you can also use the OCaml stdlib `List` module

Belt.List.keep(values, (v) => bool)

Take some time to look at the Belt Modules and try to
understand the usage of some functions:
Belt: https://bucklescript.github.io/bucklescript/api/Belt.html
Belt.List: https://bucklescript.github.io/bucklescript/api/Belt.List.html

Tip 2)
Add `open Exercise01;` before your actual code to reuse the type definitions
from the previous example
*/

/*
let figs: list(figure) = [
  {color: Black, position: (A, One), kind: King},
  {color: White, position: (A, One), kind: Queen},
  {color: Black, position: (B, Two), kind: Queen},
  {color: Black, position: (D, Four), kind: Queen},
];
*/