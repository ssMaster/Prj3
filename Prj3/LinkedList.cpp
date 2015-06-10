#include "LinkedList.h"

#include <typeinfo>

template <typename Type>
LinkedList<Type>::LinkedList(){

}



template <typename Type>
LinkedList<Type>::~LinkedList(){

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
	cout << "In insert method." << endl;
	cout << "Item type: " << typeid(item).name() << endl;
	cout << "Item value: " << item << "\tInteger value: " << i << endl;

	// ======== insert the item into a list

	ListElement->element = item;
	ListElement->next = NULL;

}

/*
0 when empty, else 1
*/
template <typename Type>
int LinkedList<Type>::empty() const{
	return 1;
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
