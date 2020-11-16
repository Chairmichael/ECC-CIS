////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 9
//  Author:                 Jeff Henry
//  File Name:              lab9_exercise3.h
//
//  Purpose of Program:
//       Linked List Class
////////////////////////////////////////////////////////////////////////////////

#ifndef LabLinkedList_H
#define LabLinkedList_H
namespace LabLinkedList
{
	struct Node {
		double n;
		Node *link;
	};
	typedef Node* NodePtr;

	class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		// Adds new node to the front of the list
		void add(double x);
		// Checks if a value is already a member in the list
		bool isMember(double x);
		// Search the list for x. Return the index if found, -1 otherwise
		int search(double x);
		// Prints the list from front to back
		void printList();
		// Removes a node from the list
		void remove(double x);
	private:
		// Finds x in the list and returns a NodePtr. Returns NULL otherwise.
		NodePtr find(double x);
		// The front of the list
		NodePtr head;
	};
} // LabLinkedList
#endif // LabLinkedList_H