[@bs.module] external style: Js.t({..}) = "./Counter.scss";

open Util;

type state = int;

type action =
  | Inc
  | Dec;

let component = ReasonReact.reducerComponent("ReCounter");

[@genType]
let make = (~count: int, _children) => {
  ...component,
  initialState: () => count,
  reducer: (action, state) =>
    switch (action) {
    | Inc => ReasonReact.Update(state + 1)
    | Dec => ReasonReact.Update(state - 1)
    },
  render: self => {
    let text = "Current count: " ++ string_of_int(self.state);
    <div className=style##root>
      <button onClick={_evt => self.send(Dec)}> {"-" |> s} </button>
      {text |> s}
      <button onClick={_evt => self.send(Inc)}> {"+" |> s} </button>
    </div>;
  },
};