console.log ("anuj");

// Variables 
// const collegId = 5; // once defined should be initialised and cannot be changed later / block scoped
let x = 5; // can be changed later / block scoped / cannot be redeclared
var y = 5; // can be changed later / global scoped / can be redeclared

// collegId = 5; -> gives error ("can not assign to a constant variable")
// let x = 7; -> gives an error ("can not re initialise a let") 
var y = 7; // no error

/**************************************************************************************************************************/


// Data Types 

/*
    number
    bingInt
    string
    boolean
    undefined
    null
    obj

    typeof() can be used for finding the types of variable instances
    typeof (null) is object
    typeof (undefined) if undefined
*/

/**************************************************************************************************************************/

// Conversion

let score = "33"
let value = Number (score)
console.log (typeof (score), typeof(value))
console.log (score, value)

/*
    Type conversion can be done through (type with capital first letter)
    e.g. Number ("33"), String (33), Boolean (1) etc.
    score = 33bc -> val = NaN (Not a Number)
    score = null -> val = 0
    score = undefined -> value = NaN
    score = 33 -> value = 33
    NaN is a number type
*/




