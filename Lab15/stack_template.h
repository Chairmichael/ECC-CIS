////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 14
//  Author:                 Jeff Henry
//  File Name:              stack_template.h
//
//  Purpose of Program:
//       Stack Template
////////////////////////////////////////////////////////////////////////////////

#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

#include <cstdlib>
using namespace std;

namespace Lab15
{
	template <class T>
	class Stack {
	public:
		// Constructors
		Stack(int size = 10);
		// Stack(Stack oldStack);
		~Stack();

		// Adds a new element to the top of the stack
		//   Resizes if needed by adding 10 positions
		void push(const T& data);

		// Removes the element from the top of the stack and returns it
		//   Resizes if there are over 20 unused positions
		const T& pop();

		// Gets the element from the top of the stack, does not remove it
		const T& get();

		// Returns the amount of items in the stack
		int getSize();

		bool isEmpty();
		
	private:
		T *arr; // dynamic array

		// the index of the element on the top of the stack
		int top;

		// how many elements the current stack can hold, will resize if needed
		int capacity;

		// Resizes the array
		void resize(int size);

	}; //Stack
} //Lab15
#endif //STACK_TEMPLATE_H