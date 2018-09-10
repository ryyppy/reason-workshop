/* Chapter 3: ReasonReact & Interop */

/* Embed a raw function */

let add: (int, int) => int = [%raw
  (a, b) => {|
    console.log("hello from raw JavaScript!");
    return a + b
|}
];

add(1, 2);

/* Map to require('path').dirname function */
[@bs.module "path"] external dirname: string => string = "dirname";
let root = dirname("/User/chenglou");

/* Import an ES6 default value */
[@bs.module "./student"] external studentName: string = "default";
let fullname = "Hans " ++ studentName;

/* Map global values */
[@bs.val] external setTimeout: (unit => unit, int) => float = "setTimeout";
[@bs.val] external clearTimeout: float => unit = "clearTimeout";