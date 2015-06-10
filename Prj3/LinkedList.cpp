#include "LinkedList.h"

#include <typeinfo>

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

	while (temp != NULL){
		cout << "Temp element: " << temp->element << endl;
		temp = temp->next;
	}
	//cout << "In copy constructor" << endl;
	//cout << "Cursor element of src is: " << src.cursor->element << endl;
	
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
		cout << "Should return 'a' : Return is: " << retrieve() << endl;
	}
	else{
		if (i == 0){	// inserts the item immediately after the cursor
			node = new ListElement(item, cursor->next);
			cursor->next = node;
			cursor = node;
			cout << "Should return 'b' : Return is: " << retrieve() << endl;
		}
		if (i == -1){	// inserts the item immediately before the cursor
			cout << "Cursor currently: " << cursor->element << endl;
			gotoPrior();
			cout << "Cursor now: " << cursor->element << endl;
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
			cout << "Cursor at the start: " << cursor->element << endl;
			gotoPrior();
			cout << "Prior cursor: " << cursor->element << endl;
			delete(cursor->next);
			cursor->next = NULL;
			cursor = head;

			cout << "Cursor value is now: " << cursor->element << endl;
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
			cout << "moving forward..." << endl;
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
	if (empty()){
		return 1;
	}
	else{
		cursor = head;
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


// ------------------------------------------------------- remove display method when done
template <typename Type>
void LinkedList<Type>::display(){
	gotoBeginning();

	cout << endl << "Displaying..." << endl;

	if (cursor == NULL){
		cout << "NULLLLLLL" << endl;
		return;
	}

	if (cursor->next == NULL){
		cout << "Value: " << cursor->element << endl;
	}
	else{
		cout << "Values found: ";
		while (cursor != NULL){
			cout << cursor->element;
			cursor = cursor->next;
			if (cursor != NULL){
				cout << ", ";
			}
			
		}
		cout << endl;
	}
}






// ===================
