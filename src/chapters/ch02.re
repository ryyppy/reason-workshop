/* Chapter 2: Functions & Currying */

/****************************/
/*** FUNCTION VALUE & TYPES */
/****************************/

/* A function is just a value */
let add = (a, b) => a + b;

/* We can define types of a function */
type addFn = (int, int) => int;

/* We can define generic placeholders for function types as well */
type genericAdd('a) = ('a, 'a) => 'a;

/* Here we are giving type hints to make addFloat complain
   if we use the + operator instead of +. */
let addFloat: genericAdd(float) = (a, b) => a +. b;


/****************************/
/*** CURRYING & APPLICATION */
/****************************/

/* We bind the first argument (a) to 3, which
   will return a new function (int) => int called add3 */
let add3 = add(3);

/* returns 5 */
add3(2);

/* This can sometimes cause confusing type problems
   let result = add(3);
   let str = "Result: " + string_of_int(result);
   */

/****************************/
/*** LABELED FUNCTIONS      */
/****************************/

/* One labeled argument, all parameters required */
let processFilepath = (~ext, filepath: string) : string =>
  filepath ++ "." ++ ext;

/* Labeled arguments can have a default value */
let processFilePathWithDefaultExt = (~ext="txt", filepath) =>
  /* handy shorthand, longversion: ~ext=ext */
  processFilepath(~ext, filepath);

/* This function has all labeled args, but one unit as last argument */
let processFullPath = (~name: string, ~dir: string, ~ext: string, ()) => {j|$dir/$name.$ext|j};

/* We can now apply all labeled arguments without applying the function */
let runProcessFullPath =
  processFullPath(~name="test", ~dir="test", ~ext="txt");

/* This calls the function */
runProcessFullPath();


/*******************************/
/* Pipe Operator / Composition */
/*******************************/

let convertMtoF = ch =>
  switch (ch) {
  | 'M' => 'F'
  | v => v
  };

/* Trivia: How to optimize this for JS ?
   Tip: Look in the BS JS-Api for another interop function */
let repeatString = (n, str) =>
  Array.fold_left((++), "", Array.make(n, str));

let result =
  "moo" |> String.capitalize |> String.map(convertMtoF) |> repeatString(2);

let repeatFoo3times = 3 |> repeatString(_, "foo");

/* Equivalent: Fast-Pipe operator to inject the left side value as the
   first position parameter of the right side function: */
let repeatFoo3times_fastpipe = 3->repeatString("foo");