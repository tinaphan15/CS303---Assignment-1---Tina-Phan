// Name: Tina Phan
// Course: CS 303
// Assignment: Assignment 1

#include "Header.h"
using namespace std;

const int maxSize = 200;

int findIndex(int arr[], int size, int value) {
	for (int i = 0; i < size; ++i) { // A for loop that iterates through the elements of the array
		if (arr[i] == value) {
			return i; // Returns the index of the value in the array
		}
	}
	return -1;
}

bool modifyValue(int arr[], int size, int index, int newValue, int& oldValue) {
	if (index < 0 || index >= size)
		return false;

	oldValue = arr[index]; // Assigns current value as an old value
	arr[index] = newValue; // Then updates the element at the index with a new value
	return true;
}

bool addValue(int arr[], int& size, int value) {
	if (size >= maxSize)
		return false;

	arr[size++] = value; // Adds the value to the end of the array and increments the size
	return true;
}

bool removeIndex(int arr[], int& size, int index) {
	if (index < 0 || index >= size)
		return false;

	for (int i = index; i < size - 1; ++i) { // A for loop that iterates from the given index to the 2nd to last element
		arr[i] = arr[i + 1];
	}

	--size; // Decreases the size, due to removing an integer
	return true;
}

int main() {

	int arr[maxSize];
	int size = 0;

	ifstream inputFile("A1input.txt"); // Creates input file

	if (!inputFile) { // Ensures input file can be opened
		cout << "Error opening input file..." << endl;
		return 1;
	}

	while (inputFile >> arr[size]) { // Reads data from input file
		size++;
		if (size >= maxSize) {
			cout << "Reached maximum capacity for array..." << endl;
			break;
		}
	}

	inputFile.close(); // Closes input file

	int choice;
	do {
		// Output a menu for user selection
		cout << "\nChoose an option 1, 2, 3, 4, or 5:" << endl;
		cout << "1. Find index of a value" << endl;
		cout << "2. Modify the value of an integer" << endl;
		cout << "3. Add a new integer to the end" << endl;
		cout << "4. Remove an integer" << endl;
		cout << "5. Exit\n" << endl;
		cin >> choice; // Receive user input

		switch (choice) {
		case 1: { // Function that finds the index of a value and returns the index
			int value;
			cout << "Enter a value: ";
			cin >> value;
			int index = findIndex(arr, size, value);
			if (index != -1)
				cout << "Value found at index: " << index << endl;
			else
				cout << "Value not found in array." << endl;
			break;
		}
		case 2: { // Function that modifies the value of an integer and returns the old and new value to user (includes a try/catch)
			try {
				int index, oldValue, newValue;
				cout << "Enter index to modify value: ";
				cin >> index;
				cout << "Enter a new value: ";
				cin >> newValue;
				modifyValue(arr, size, index, newValue, oldValue);
				cout << "Modified index " << index << ": " << oldValue << " -> " << newValue << endl;
			}
			catch (const exception& e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		}
		case 3: { // Function that adds a new integer to the end of the array (includes a try/catch)
			try {
				int newValue;
				cout << "Enter a new integer: ";
				cin >> newValue;
				addValue(arr, size, newValue);
				cout << "Integer " << newValue << " added. New size of the array: " << size << endl;
			}
			catch (const exception& e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		}
		case 4: { // Function that intakes an index of an array and removes the integer
			int index;
			cout << "Enter index to remove an integer: ";
			cin >> index;
			removeIndex(arr, size, index);
			cout << "Removed integer at index: " << index << endl;
			break;
		}
		case 5: { // When user decides they want to exit the program
			cout << "Exiting program...\n" << endl;
			break;
		}
		default: // When user does not input correct options as a choice
			cout << "Please choose 1, 2, 3, 4, or 5. " << endl;
		}
	} while (choice != 5);

	return 0;

}