/* Variants */

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

/* Option Type */
let maybeString = Some("test");
let notAString = None;

/* Modules */

module MyValidator {
    type t('a) = Validated('a) | NotValidated;
    
    let validate = (a) => Validated(a);
  
    /* Needs to be implemented */
    let isValidated = (_a) => false;
};


let validatedInt = MyValidator.validate(1);
let isActuallyValidated = MyValidator.isValidated(validatedInt);


/* Pattern Matching */

let myMove = Left(10);

switch(myMove) {
| Up(distance) => Js.log({j|Walked $distance upwards|j})
| Down(distance) => Js.log({j|Walked $distance downwards|j})
| Left(distance) => Js.log({j|Walked $distance to the left|j})
| Right(_) => Js.log({j|We don't really walk to the right|j})
};
