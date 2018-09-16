/*
TASK 1
Define a function citation(name, msg, loud)

name: string
msg: string
loud: boolean

if loud is true, the whole citation is ALL UPPERCASE. Use the `String` module for this.
Citation format: "$msg" - $name

Examples:
citation("Fritz", "Test", false) --> "Test" - Fritz
citation("Franz", "Hello", true) --> "HELLO" - Franz

Use the function and pipe the output to Js.log
*/



/*
TASK 2:
Define a new function citation2, but with all parameters marked as labeled arguments

Partially apply the name parameter, use the function and pipe the output to Js.log
Play around with the currying feature.
*/



/* 
TASK 3:
Define a new function citation3 similar to citation2, but `loud` should now be an optional parameter
which defaults to `false`.

Don't forget that fully labeled functions require a unit () parameter in the last parameter position.
Call / curry the function in severl ways and pipe the output to Js.log
*/


/*
TASK 4:
Define a new function citation4 similar to citation3, but `msg` should now be an unlabeled argument and placed
on the last position (remove the unit type), the function should feed the arguments to `citation3`.

Call the function in several ways and pipe the output to Js.log.
Don't forget to verify the output by running the exercise in node: `node lib/js/src/exercise04.bs.js`
*/
