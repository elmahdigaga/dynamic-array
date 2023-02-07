# DynamicArray

This is a dynamic array implementation in C++.

The **`DynamicArray.hpp`** header file contains all **attributes** and **methods**.

The **`menu.cpp`** test file is used for testing purposes.

## Installation

1. [Download](https://github.com/elmahdigaga/dynamic-array/archive/refs/heads/main.zip) the Latest release from gitHub.
2. Unzip the Folder
3. Copy the `DynamicArray.hpp` file to your project folder
4. Include the header file:
```C++
#include "DynamicArray.hpp"
```
5. Ready to use.

-------------------------

## Getting started

### The `DynamicArray` class

In case you don't know what a Dynamic Array is and what it's used for, take a quick look at [Wikipedia::DynamicArray](https://en.wikipedia.org/wiki/Dynamic_array) before continuing.

#### To declare a DynamicArray object
```c++
// Instantiate a Dynamic Array
DynamicArray myArray = DynamicArray();

// Or just this
DynamicArray myArray;
```

#### Getting the size of the Dynamic Array
```c++
// To get the size of a Dynamic Array, make use of the getSize() method
int arrSize = myArray.getSize();
```

#### Adding elements
```c++
// push(value) method will insert at the END of the array
myArray.push(value);

// insert(value, index) method will try to insert the value at the specified index
myArray.insert(value, 0); // Add at the beginning
myArray.insert(value, 3); // Add at index 3
```

#### Getting elements
```c++
// get(index) will return the element at index
// (notice that the start element is 0, not 1)

// Get the FIRST element
value = myArray.get(0);

// Get the THIRD element
value = myArray.get(2);

// Get the LAST element
value = myArray.get(myArray.getSize() - 1;
```

#### Searching for elements
```c++
// find(value) will return the index of the element if found, -1 if not.
int myIndex = myArray.find(value);
```

#### Changing elements
```c++
// change(newValue, index) method will change the element at index to newValue

// Change the first element to newValue
myArray.change(newValue, 0);

// Change the third element to newValue
myArray.change(newValue, 2);

// Change the LAST element of the list
myArray.change(newValue, myArray.getSize() - 1;
```

#### Deleting elements
```c++
// pop() method will remove from the END of the array
myArray.pop();

// remove(index) method will try to remove the value at the specified index
myArray.remove(0); // Remove from the beginning
myArray.remove(3); // Remove from index 3
```

#### Sorting elements
```c++
// Sorts in ascending order using the QuickSort Algorithm
myArray.sort();
```

#### Reversing elements
```c++
// Reverses the array
myArray.reverse();
```

#### Printing the Dynamic Array
```c++
// Display the elements of the array
myArray.print();
```

#### Check if the array is empty
```c++
bool state = myArray.isEmpty();
```
