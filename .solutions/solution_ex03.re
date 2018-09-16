/* We give the compiler type hints by using an annotation */
let figs: list(Solution_chess.figure) = [
    { color: Black, position: (A, One), kind: King},
    { color: White, position: (H, Three), kind: Queen},
];

/* Use a function by accessing the Module directly */
Solution_chess.filterColor(Black, figs) |> Js.log;