#include "LinkedList.h"

#include <typeinfo>

template <typename Type>
LinkedList<Type>::LinkedList(){
	head = NULL;
	cursor = head;
}



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

		}
	}
}

template <typename Type>
int LinkedList<Type>::gotoPrior(){
	if (empty() || cursor == head){
		cout << "Nothing prior to head" << endl;
		return 0;
	}
	else{
		ListElement *temp = head;

		cout << "Cursor is currently pointing to value: " << cursor->element << endl;

		while (temp->next != cursor){
			temp = temp->next;
			cout << "moving forward..." << endl;
		}

		cout << "Prior element: " << temp->element << endl;

		return 1;
	}
}

template <typename Type>
int LinkedList<Type>::gotoNext(){
	if (cursor->next != NULL){
		cursor = cursor->next;
		cout << "going to next..." << endl;
		return 1;
	}
	else{
		return 0;
	}
}

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

template <typename Type>
void LinkedList<Type>::display(){
	gotoBeginning();

	cout << endl << "Displaying..." << endl;

	if (cursor == NULL){
		cout << "NULLLLLLL" << endl;
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


/*
When a list is not empty, removes the current elemnt from the list.
After deleting the cursor pointing element, set the cursor to the following element.
- If the cursor is pointing to an element that is the only element in the list, you
  should properly set the head and cursor pointer after deleting the node.
- If the cursor is pointing to the last element of the list, the link field of the 
  previous node of the last node should be set to null after deleting the node.
  Set the cursor to the head pointing element.
*/
/*
template <typename Type>
void LinkedList<Type>::remove(){

}*/

// ===================
