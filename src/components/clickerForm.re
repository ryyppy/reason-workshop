/* src/components/clickerForm.re */

let component = ReasonReact.statelessComponent("ClickerForm");

let s = ReasonReact.stringToElement;

let make = (~onClick, ~onReset, _children) => {
  ...component,
  render: _self => <div> 
    <button onClick> ("Count up" |> s) </button>
    <button onClick=onReset> ("Reset" |> s) </button>
  </div>
};
