/*
Simon Sharudin
CS331 - Project 3
June 9, 2015
*/

#include "LinkedList.h"

/*
Default constructor
*/
template <typename Type>
LinkedList<Type>::LinkedList(){
	head = NULL;
	cursor = head;
}

/*
Copy constructor
*/
template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList &src){
	ListElement* temp = src.head;

	// Reset the head and cursor pointers to NULL
	head = NULL;
	cursor = NULL;

	// Insert the nodes
	while (temp != NULL){
		insert(temp->element, 0);
		temp = temp->next;
	}
}

/*
Destructor
*/
template <typename Type>
LinkedList<Type>::~LinkedList(){
	ListElement* temp = head;
	while (temp != NULL){
		temp = temp->next;
		delete(head);
		head = temp;
	}
}

// ============= Insert and Remove operations

/*
When a list is not full, inserts the item into a list.
- If the list is empty, inserts the item as the first element in the list.
  The head and cursor pointer should be properly initialized after the insert.
- If the list is not empty and the second integer argument has the value of 0, inserts
  the item immediately after the cursor element.
- If the list is not empty and the second integer argument has the value of -1, inserts
  the item immediately before the cursor element.
In all cases, properly moves the cursor to designate inserted item as the current element.
*/
template <typename Type>
void LinkedList<Type>::insert(const Type &item, int i){
	ListElement *node;

	// ======== insert the item into a list
	// create the new node to add
	
	if (empty()){	// Insert the item as the first element in the list
		node = new ListElement(item, NULL);
		head = node;
		cursor = head;
	}
	else{
		if (i == 0){	// inserts the item immediately after the cursor
			node = new ListElement(item, cursor->next);
			cursor->next = node;
			cursor = node;
		}
		if (i == -1){	// inserts the item immediately before the cursor
			gotoPrior();
			node = new ListElement(item, cursor->next);
			cursor->next = node;
			cursor = node;
		}
	}
}

/*
When a list is not empty, removes the current elemnt from the list.
After deleting the cursor pointing element, set the cursor to the following element.
- If the cursor is pointing to an element that is the only element in the list, you
should properly set the head and cursor pointer after deleting the node.
- If the cursor is pointing to the last element of the list, the link field of the
previous node of the last node should be set to null after deleting the node.
Set the cursor to the head pointing element.
*/
template <typename Type>
void LinkedList<Type>::remove(){
	if (!empty()){	// an element can be removed
		if (cursor == head){	// there is only one node in the list
			delete(head);
			head = cursor = NULL;
		}
		else if (cursor->next == NULL){		// cursor pointing to the last element in the list
			gotoPrior();
			delete(cursor->next);
			cursor->next = NULL;
			cursor = head;
		}
	}
	else{
		cout << "Nothing to remove" << endl;
		return;
	}
}

/*
Returns a copy of the cursor pointing element when the list is not empty
*/
template <typename Type>
Type LinkedList<Type>::retrieve() const{
	if (empty()){
		return NULL;
	}
	else{
		Type copyElement = cursor->element;
		return copyElement;
	}
}

/*
If a list is not empty and the cursor is not pointing to the first element
of the list, then designates the element immediately before the current
element as the current element and returns 1. Otherwise, returns 0;
*/
template <typename Type>
int LinkedList<Type>::gotoPrior(){
	if (empty() || cursor == head){
		return 0;
	}
	else{
		ListElement *temp = head;

		while (temp->next != cursor){
			temp = temp->next;
		}
		cursor = temp;

		return 1;
	}
}

/*
If the current element is not at the end of the list, then designates the 
element immediately after the current element as the current element and
returns 1. Otherwise, returns 0.
*/
template <typename Type>
int LinkedList<Type>::gotoNext(){
	if (empty()){
		return 0;
	}
	if (cursor->next != NULL){
		cursor = cursor->next;

		return 1;
	}
	else{
		return 0;
	}
}

/*
If a list is not empty, then designates the element at the beginning
of the lsit as the current element and returns 1. Otherwise, returns 0.
*/
template <typename Type>
int LinkedList<Type>::gotoBeginning(){
	if (!empty()){
		cursor = head;
		return 1;
	}
	else{
		return 0;
	}
}

/*
Remove all the elements in a list and deallocates associated dynamic memory
*/
template <typename Type>
void LinkedList<Type>::clear(){
	gotoBeginning();
	
	while (cursor != NULL){
		cursor = cursor->next;
		delete(head);
		head = cursor;
	}
}

/*
Return 1 when empty, else 0
*/
template <typename Type>
int LinkedList<Type>::empty() const{
	if (head == NULL && cursor == NULL){	// Empty list
		return 1;
	}
	else{	// There are elements in the list
		return 0;
	}
}