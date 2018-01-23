/* CHAPTER 1: Types & Modules */
type someRecord = {
    test: string,
    good: bool,
};
/****************/
/*** DATA TYPES */
/****************/

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

/* Some record (needs type definition of given record) */
let someRecord = {test: "test", good: true };

/********************/
/*** DEFINING TYPES */
/********************/

type aa = int;
type bb = string;
type cc = float;
type tupleT = (int, int);

/* You can do type aliases */
type someAlias = aa;

/* A record type for structured data */
type user = {
  name: string,
  friendly: bool
};

/* Closed JS object type */
type jsUser = {.
    "name": string,
    "friendly": Js.boolean,
};

/* Open JS object type */
type openUser('a) = {..
    "fullname": string
} as 'a;

/*****************************/
/*** MUTABLE RECORD REF TYPE */
/*****************************/
let mutInt = ref(1);
mutInt := 3;
let readMut = mutInt^;


/********************/
/*** VARIANTS       */
/********************/

/* This is a variant type `color` with 3 tags */
type color = Red | Green | Blue;

/* Tags don't have any concrete value. 
Note that we never have to annotate `myColor` */
let myColor = Red;

/* You can define type constructors, which
can attach data to provided Tags */
type distance = int;
type movement = 
    | Up(distance)
    | Down(distance) 
    | Left(distance) 
    | Right(distance);

/* When we want to use `Up`, we need to provide a value */
let myMove = Up(10);

/***************************/
/*** VARIANTS: OPTION TYPE */
/***************************/

let maybeString = Some("test");
let notAString = None;

/***************************/
/*** VARIANTS: REF TYPE    */
/***************************/

/* This defines a mutable value of type ref('a) */

let mutti = ref(1);
mutti.contents;

/**************/
/*** MODULES  */
/**************/

module MyValidator {
    type t('a) = Validated('a) | NotValidated;

    let validate = (a) => Validated(a);

    /* Needs to be implemented */
    let isValidated = (_a) => false;
};


let validatedInt = MyValidator.validate(1);
let isActuallyValidated = MyValidator.isValidated(validatedInt);

/**********************/
/*** PATTERN MATCHING */
/**********************/

switch(myMove) {
    | Up(distance) => Js.log({j|Walked $distance upwards|j})
    | Down(distance) => Js.log({j|Walked $distance downwards|j})
    | Left(distance) => Js.log({j|Walked $distance to the left|j})
    | Right(_) => Js.log({j|We don't really walk to the right|j})
};

switch someList {
    | [] => Js.log("Empty list")
    | [a] => Js.log("First value: " ++ string_of_int(a))
    | [_, ...b] => {
        let sum = List.fold_left((+), 0, b) |> string_of_int;
        Js.log("Sum: " ++ sum)
      }
};
