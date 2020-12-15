////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 14
//  Author:                 Jeff Henry
//  File Name:              stack_template.cpp
//
//  Purpose of Program:
//       Stack Template
////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include "stack_template.h"
using namespace std;

namespace Lab15
{
	template <class T>
	Stack<T>::Stack(int size) {
		arr = new T[size];
		capacity = size;
		top = -1; // Nothing in stack; first element will have the index 0
	}
	// Stack<T>::Stack(Stack oldStack) {

	// }
	template <class T>
	Stack<T>::~Stack() {
		delete[] arr;
	}

	// Adds a new element to the top of the stack
	//   Resizes if needed by adding 10 positions
	template <class T>
	void Stack<T>::push(T) {
		top++;
		if (top >= capacity)
			Stack<T>::resize(capacity + 10);
		arr[top] = T;
	}

	// Removes the element from the top of the stack and returns it
	//   Resizes if there are over 20 unused positions
	template <class T>
	T Stack<T>::pop() {
		if (top - capacity >= 20)
			Stack<T>::resize(capacity - 10);
		return arr[top--];
	}

	// Gets the element from the top of the stack, does not remove it
	template <class T>
	T Stack<T>::get() {
		return arr[top];
	}

	// Returns the amount of items in the stack
	template <class T>
	int Stack<T>::getSize() {
		return top + 1;
	}

	// Resizes the array
	template <class T>
	void Stack<T>::resize(int newSize) {
		T *newArr = new T[newSize];
		for (int i = 0; i < Stack<T>::getSize(); i++)
			newArr[i] = arr[i];
		capacity = newSize;
		delete[] arr;
		arr = newArr;
	}

	template <class T>
	bool Stack<T>::isEmpty() {
		return Stack<T>::getSize() == 0;
	}

	// private:
	// 	T *arr; // dynamic array
	// 	// the index of the element on the top of the stack
	// 	int top;
	// 	// how many elements the current stack can hold, will resize if needed
	// 	int capacity;
	// }; //Stack
} //Lab15
