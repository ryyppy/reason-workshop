/* Originally extracted from the results of exercise01 */
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

/* Originally extracted from the results of exercise02 */
let rowToInt: row => int =
  fun
  | One => 1
  | Two => 2
  | Three => 3
  | Four => 4
  | Five => 5
  | Six => 6
  | Seven => 7
  | Eight => 8;

let colToInt = (col: col): int =>
  switch (col) {
  | A => 1
  | B => 2
  | C => 3
  | D => 4
  | E => 5
  | F => 6
  | G => 7
  | H => 8
  };

let rowSmallerThan = (r1: row, r2: row): bool =>
  rowToInt(r1) < rowToInt(r2);

let colSmallerThan = (c1: col, c2: col): bool =>
  colToInt(c1) < colToInt(c2);

let filterColor = (color: color, figures: list(figure)) =>
  Belt.List.keep(figures, f => f.color === color);

let filterPosition = ((thanCol, thanRow): position, figures: list(figure)) =>
  Belt.List.keep(
    figures,
    f => {
      let (col, row) = f.position;
      colSmallerThan(col, thanCol) && rowSmallerThan(row, thanRow);
    },
  );

let filterColorAndPosition = (color, position, figs) =>
  figs |> filterColor(color) |> filterPosition(position);

/* Helper for printing human readable values */

let rowToString = row => rowToInt(row) |> string_of_int;
let colToString =
  fun
  | A => "A"
  | B => "B"
  | C => "C"
  | D => "D"
  | E => "E"
  | F => "F"
  | G => "G"
  | H => "H";

let posToString = ((col, row): position) => {
  let rowStr = rowToString(row);
  let colStr = colToString(col);

  /* Equivalent to a template literal (you can only inline simple binding names)*/
  {j|($colStr, $rowStr)|j};
};

let colorToString =
  fun
  | Black => "Black"
  | White => "White";

let kindToString =
  fun
  | King => "King"
  | Queen => "Queen"
  | Bishop => "Bishop"
  | Knight => "Knight"
  | Rook => "Rook"
  | Pawn => "Pawn";

let figureToString = (f: figure) => {
  let kindStr = kindToString(f.kind);
  let posStr = posToString(f.position);
  let colorStr = colorToString(f.color);

  {j|$colorStr $kindStr on $posStr|j};
};