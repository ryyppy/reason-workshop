/* src/components/counterApp.re */

type action = 
  | Click
  | Reset;

type state = {
  count: int
};

let component = ReasonReact.reducerComponent("CounterApp");

let make = (_children) => {
  ...component,
  initialState: () => { count: 0 },
  reducer: (action, state) => switch(action) {
    | Click => ReasonReact.Update({count: state.count + 1})
    | Reset => ReasonReact.Update({count: 0})
  },
  render: (self) => {
    let message = "Clicked " ++ string_of_int(self.state.count) ++ " time(s)";
    let onClick = (_event) => self.send(Click);
    let onReset = (_event) => self.send(Reset);
    <div>
      {ReasonReact.string(message)}
      <ClickerForm onClick onReset />
    </div>
  }
}