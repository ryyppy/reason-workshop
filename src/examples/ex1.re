/* Data Types */

let str = "Some string";

/* Int is its own data type */
let someInt = 1;

/* The dot signals a floating point number */
let someFloat = 1.;

/* Yeah, Reason also supports single characters */
let someChar = 'c';

/* List is immutable, good for small number of entries */
let someList = [1, 2, 3];

/* Arrays are quicker and mutable... good for JS interop */
let someArray = [|1, 2, 3|];

/* Tuples always contain a strict fixed number of elements */
let someTuple = (1, 2);

/* You can annotate variables as well */
let someAnnotated: string = "";

/* Defining Types */

type aa = int;
type bb = string;
type cc = float;
type tupleT = (int, int);

/* You can do type aliases */
type someAlias = aa;