let component = ReasonReact.statelessComponent("ExerciseList");

open Util;
module Link = ReactRouterDom.Link;

let make = _children => {
    ...component,
    render: _ => {
        <ul>
            <li><Link to_="/exercise1"> ("") </Link>
        </ul>
    }
}