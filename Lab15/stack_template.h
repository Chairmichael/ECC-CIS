////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 15
//  Author:                 Jeff Henry
//  File Name:              stack_template.h
//
//  Purpose of Program:
//       Stack Template
////////////////////////////////////////////////////////////////////////////////

#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

#include <iostream>
using namespace std;

namespace Lab15
{
	template <class T>
	class Stack {
	public:
		Stack(int size = 10) {
			arr = new T[size];
			capacity = size;
			top = -1; // Nothing in stack; first element will have the index 0
		}
		// Stack(Stack oldStack) {

		// }
		~Stack() {
			delete[] arr;
		}

		// Adds a new element to the top of the stack
		//   Resizes if needed by adding 10 positions
		void push(const T& data) {
			top++;
			if (top >= capacity)
				resize(capacity + 10);
			arr[top] = data;
		}

		// Removes the element from the top of the stack and returns it
		//   Resizes if there are over 20 unused positions
		const T& pop() {
			if (capacity - top >= 20)
				resize(capacity - 10);
			return arr[top--];
		}

		// Gets the element from the top of the stack, does not remove it
		const T& get() {
			return arr[top];
		}

		// Returns the amount of items in the stack
		int getSize() {
			return top + 1;
		}

		// Returns the capacity of the stack
		int getCapacity() {
			return capacity;
		}

		bool isEmpty() {
			return getSize() == 0;
		}

	private:
		T *arr; // dynamic array

		// the index of the element on the top of the stack
		int top;

		// how many elements the current stack can hold, will resize if needed
		int capacity;

		// Resizes the array
		void resize(int newSize) {
			T *newArr = new T[newSize];
			for (int i = 0; i < getSize(); i++)
				newArr[i] = arr[i];
			capacity = newSize;
			delete[] arr;
			arr = newArr;
		}

	}; //Stack
} //Lab15
#endif //STACK_TEMPLATE_H