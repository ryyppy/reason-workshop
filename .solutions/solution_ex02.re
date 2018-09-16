open Solution_chess;

/* Test data sets */
let figs: list(figure) = [
  {color: Black, position: (A, One), kind: King},
  {color: White, position: (A, One), kind: Queen},
  {color: Black, position: (B, Two), kind: Queen},
  {color: Black, position: (D, Four), kind: Queen},
];

filterColorAndPosition(Black, (C, Three), figs)
|> List.map(figureToString)
|> Array.of_list
|> Js.log;