#pragma once
#include <iostream>
#include <fstream>

// Function 1 - Checks if a certain integer exists in the array if the number is present, return the index where the number is present.
int findIndex(int arr[], int size, int value);

// Function 2 - Modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to user.
bool modifyValue(int arr[], int size, int index, int newValue, int& oldValue);

// Function 3 - Adds a new integer to the end of the array.
bool addValue(int arr[], int& size, int value);

// Function 4 - Intakes an index of an array and removes the integer altogether.
bool removeIndex(int arr[], int& size, int index);
