type color =
  | Black
  | White;

type kind =
  | King
  | Queen
  | Bishop
  | Knight
  | Rook
  | Pawn;

type col =
  | A
  | B
  | C
  | D
  | E
  | F
  | G
  | H;

type row =
  | One
  | Two
  | Three
  | Four
  | Five
  | Six
  | Seven
  | Eight;

type position = (col, row);

type figure = {
  color,
  kind,
  position,
};

let fig1 = {color: Black, kind: King, position: (D, Eight)};
let fig2 = {color: White, kind: Rook, position: (H, One)};

let figArray = [| fig1, fig2 |];
let figList = [fig1, fig2];