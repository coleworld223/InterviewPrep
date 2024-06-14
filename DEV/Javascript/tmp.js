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

// let x = " anujanand-anujanand  "
// console.log (x)
// console.log (x.trim())
// console.log (x.substr (0, 5));
// console.log (x.slice(-8, 3));
// console.log (x.split('-'));



//***************************************MATHS******************************************************************************

// console.log(Math.abs(-4));
// console.log(Math.min (3, 3, 5, 6));
// console.log(Math.max (2, 523, 545, 523));
// console.log(Math.sqrt (4));
// console.log(Math.pow (2, 4));


// console.log(Math.random()); // gives [0, 1] random distribution

// console.log (Math.floor (Math.random () * 10) + 1);
// let mx = 20;
// let mn = 10;
// console.log (Math.floor (Math.random () * (mx - mn + 1) + 1) + mn); // random integer in (10, 20)



//****************************************DATE-AND-TIME********************************************************************

// let newDate = new Date();
// let createdDate = new Date (2023, 0, 1);

// console.log (newDate.toString());
// console.log (newDate.toLocaleDateString());
// console.log (createdDate.toString());
// console.log (createdDate.toLocaleDateString());
// console.log (newDate.getTime());
// console.log (createdDate.getTime());

// You can create a Date Object and see and test all of the functions that come with it

// **********************************ARRAYS***********************************************************************************

// const myArr = [0, 1, 2, 3, 4, 5];
// console.log (myArr);
// console.log (myArr.slice(0, 3));
// console.log (myArr);
// console.log (myArr.splice(0, 4));
// console.log (myArr);

// Practice all the suggested methods of array to get an idea

// const arr = Array (0, 2, 3, 4);
// console.log (arr);
// const arr1 = [0, 1, 2, 3];
// const arr2 = [4, 5, 6, 7];
// // const arr3 = arr1.concat(arr2);
// const arr3 = [...arr1, ...arr2];
// console.log (arr3);
// const arr5 = [0, 1, [2, [4, 5, [6, 6, 6]]]];
// const arr6 = arr5.flat(Infinity);
// console.log (arr5);
// console.log (arr6);

// console.log (Array.isArray(arr1));
// console.log (Array.of(0, 1, 2));

// **************************************OBJECTS*******************************************************************************





























//**************************************************