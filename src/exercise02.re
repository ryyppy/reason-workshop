type color =
  | Black
  | White;

type figure = {
  kind: string,
  color,
  position: (int, int),
};

let figures = [
  {kind: "king", color: Black, position: (1, 1)},
  {kind: "pawn", color: Black, position: (1, 2)},
  {kind: "tower", color: White, position: (3, 3)},
  {kind: "queen", color: Black, position: (4, 1)},
];
