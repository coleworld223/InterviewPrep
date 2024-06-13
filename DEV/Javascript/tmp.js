console.log ("anuj");

// Variables 
// const collegId = 5; // once defined should be initialised and cannot be changed later / block scoped
// let x = 5; // can be changed later / block scoped / cannot be redeclared
// var y = 5; // can be changed later / global scoped / can be redeclared

// collegId = 5; -> gives error ("can not assign to a constant variable")
// let x = 7; -> gives an error ("can not re initialise a let") 
// var y = 7; // no error

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

// let score = "33"
// let value = Number (score)
// console.log (typeof (score), typeof(value))
// console.log (score, value)

/*
    Type conversion can be done through (type with capital first letter)
    e.g. Number ("33"), String (33), Boolean (1) etc.
    score = 33bc -> val = NaN (Not a Number)
    score = null -> val = 0
    score = undefined -> value = NaN
    score = 33 -> value = 33
    NaN is a number type
*/

// *********************************OPERATIONS*****************************************************************************

// console.log (2 + 2)
// console.log (2 * 2)
// console.log (2 ** 2)
// console.log (2 - 2)
// console.log (2 / 2)
// console.log (2 % 2)

// console.log ("2" + 2)
// console.log ("2" + 2 + 2)
// console.log (2 + 2 + "2")
// console.log (+true)
// console.log (+false)
// console.log (+"")

// let gameCounter = 100
// gameCounter++
// console.log (gameCounter)
// ++gameCounter
// console.log (gameCounter)

// This is short revision notes -> you can read more on MDN Docs 


// ***************************************COMPARISIONS*************************************************************************

// console.log (2 > 3)
// console.log (2 < 3)
// console.log (2 == 3)
// console.log (2 <= 3)
// console.log (2 >= 3)
// console.log (2 <= 3)
// console.log (2 != 3)
// console.log (2 == 2)


//Avoid these comparisions as they create confusion
// console.log (null > 0)
// console.log (null == 0)
// console.log (null >= 0)

// console.log (undefined > 0)
// console.log (undefined == 0)
// console.log (undefined >= 0)
//Avoid these comparisions as they create confusions

// === : triple equal (data types are not converted and comparisions are based on data types also)

// console.log ("2" === 2) // gives a false


//***********************************************DATATYPES-INTERVIEW**************************************************

//Data types categorised in two based on How it is stored and used from memory (concept somewhat like call by ref and value)
 
// 1. Primitive (copies are created and changes are made in copy)
// 7 types :  String, Number, Boolean, null, undefined, Symbol, BigInt

// 2. Non-Primitive (Reference)
// Array, Object, Function

// JS is a dynamically typed language (we do not define the datatype to be stored in variables beforehand)

// const s = Symbol ('123');
// const ns = Symbol ('123');
// console.log (s === ns) // (return false) -> Symbol return a unique id even for same parameters for different variables

// const bigNumber = 34234232442343224234n // n at the end makes it a BigInt
// console.log (bigNumber);

// const tiles = ["size1", "size2", "size3"]; // array inside [] brackets, can hold different datatypes also

// const myObj = {                    // Objects in {} brackets, hold key: value pair, value can be of any datatype (even Objects, Arrays, Functions)
//     name: "anuj",
//     age: 22,
//     class: "Btech",
//     Friends: {
//         name: "none",
//     },
//     Does: function () {
//         console.log ("Hello This is An")
//     }
// }

// const myFunc = function () {
//     console.log ("This is a function made by Anuj, during Interview Preparation 2025 Placement season")
// }

// myFunc();

// For interviews, You can use console.log(typeof var_name) to see what values return what datatype
// null -> object, BigInt -> undefined. etc check yourselves


//********************************************MEMORY*******************************************************************************

// Stack (Primitive)  ,   Heap (Non Primitive)

// In primitive data types we deal with copies of data stored, so if we take the value of a variable in another variable and change it
// the value in the original variable does not change

// let firstNumber = 10
// let secondNumber = firstNumber // a copy of firstNumber is created and passed in secondNumber
// secondNumber = 20
// console.log (firstNumber, secondNumber) // first number did not change

// Non primitive data types are stored in heap, and we deal with addresses or reference to the locations of storage
// so the changes are reflected in original values as well ... see e.g. for better understanding

// let carOne = {
//     name: "car1",
//     speed: 12
// };

// let carTwo = carOne

// carTwo.name = "car2"

// console.log (carOne, carTwo) // changes are reflected in carOne as well, because both carOne and carTwo refer to the same object in memory


//***************************************STRING_METHODS*************************************************************

// There are a lot of string methods which can help you modify and solve problems of string with relative ease 
// Also you can find methods in prototype of string object when created in a browser
// Go through the MDN Docs and implement some of the methods

let x = " anujanand-anujanand  "
console.log (x)
console.log (x.trim())
console.log (x.substr (0, 5));
console.log (x.slice(-8, 3));
console.log (x.split('-'));





























//**************************************************