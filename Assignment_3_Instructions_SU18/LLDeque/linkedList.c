/*********************************************************************
** Program Filename: linkedList.c
** Author: Nhu Duong
** Date: July 23, 2018
** Description: functions for linkedList
** Input: None
** Output: None
*********************************************************************/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
 /*********************************************************************
 ** Function: init
 ** Description: Allocates the list's sentinel and sets the size to 0.
 The sentinels' next and prev should point to eachother or NULL as appropriate.
 ** Parameters: list
 ** Pre-condition:make sure frontSentinel and backSentinel not NULL
 ** Post-condition: make size to 0
 *********************************************************************/
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	list->frontSentinel = malloc(sizeof(struct Link));
	assert(list->frontSentinel !=0);
	list-> backSentinel = malloc(sizeof(struct Link));
	assert(list->backSentinel !=0);
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
/*********************************************************************
** Function: addLinkBefore
** Description: Adds a new link with the given value before the given link and
 increments the list's size.
** Parameters: list, link, value
** Pre-condition: newLink not NULL
** Post-condition: size++
*********************************************************************/

static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link *newLink = (struct Link*)malloc(sizeof(struct Link));
	assert(newLink != 0);
	newLink->value = value;
	newLink->next = link;
	newLink->prev = link->prev;
	link->prev->next = newLink;
	link->prev = newLink;
	list->size ++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
 /*********************************************************************
 ** Function: removeLink
 ** Description:Removes the given link from the list and decrements the list's size.
 ** Parameters: list, link
 ** Pre-condition: None
 ** Post-condition: size--
 *********************************************************************/
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(link);
	link = 0;
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
 /*********************************************************************
 ** Function: linkedListCreate
 ** Description: Allocates and initializes a list.
 ** Parameters: None
 ** Pre-condition: None
 ** Post-condition: return pointer to newDeque
 *********************************************************************/
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
 /*********************************************************************
 ** Function: linkedListDestroy
 ** Description:Deallocates every link in the list including the sentinels,
  and frees the list itself.
 ** Parameters: list
 ** Pre-condition: list is not empty
 ** Post-condition: free frontSentinel, backSentinel, list
 *********************************************************************/
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
 /*********************************************************************
 ** Function: linkedListAddFront
 ** Description: Adds a new link with the given value to the front of the deque.
 ** Parameters: list, value
 ** Pre-condition: none
 ** Post-condition: list get value in it  in the front
 *********************************************************************/
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list,list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
 /*********************************************************************
 ** Function: linkedListAddBack
 ** Description:Adds a new link with the given value to the back of the deque.
 ** Parameters: list, value
 ** Pre-condition: none
 ** Post-condition: list get value in it  in the back
 *********************************************************************/
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list,list->backSentinel, value);

}

/**
 * Returns the value of the link at the front of the deque.
 */
 /*********************************************************************
 ** Function: linkedListFront
 ** Description:Returns the value of the link at the front of the deque.
 ** Parameters: list
 ** Pre-condition: linkedListIsEmpty is false
 ** Post-condition: return the value at the front.
 *********************************************************************/
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	return list->frontSentinel->next->value;

}

/**
 * Returns the value of the link at the back of the deque.
 */
 /*********************************************************************
 ** Function: linkedListBack
 ** Description:Returns the value of the link at the back of the deque.
 ** Parameters: list
 ** Pre-condition: linkedListIsEmpty is false
 ** Post-condition: return the value at the back.
 *********************************************************************/
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
 /*********************************************************************
 ** Function: linkedListRemoveFront
 ** Description:Removes the link at the front of the deque.
 ** Parameters: list
 ** Pre-condition: linkedListIsEmpty is false
 ** Post-condition: remove link
 *********************************************************************/
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
 /*********************************************************************
 ** Function: linkedListRemoveBack
 ** Description:Removes the link at the back of the deque.
 ** Parameters: list
 ** Pre-condition: linkedListIsEmpty is false
 ** Post-condition: remove link
 *********************************************************************/
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
 /*********************************************************************
 ** Function: linkedListIsEmpty
 ** Description: Returns 1 if the deque is empty and 0 otherwise.
 ** Parameters: none
 ** Pre-condition: none
 ** Post-condition:return 1 or 0
 *********************************************************************/
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	return list->size ==0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
 /*********************************************************************
 ** Function: linkedListPrint
 ** Description:Prints the values of the links in the deque from front to back.
 ** Parameters:list
 ** Pre-condition: none
 ** Post-condition: print out the value
 *********************************************************************/
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	struct Link *current = list->frontSentinel->next;

	for (int i =0; i<list->size; i++){
		printf("Printing values of links in the deque from front to back %i\n", current->value);
		current = current->next;
	}

}

/**
 * Adds a link with the given value to the bag.
 */
 /*********************************************************************
 ** Function: linkedListAdd
 ** Description: Adds a link with the given value to the bag.
 ** Parameters: list, value
 ** Pre-condition: None
 ** Post-condition: Added the value
 *********************************************************************/
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	addLinkBefore(list,list->backSentinel, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
 /*********************************************************************
 ** Function: linkedListContains
 ** Description: Returns 1 if a link with the value is in the bag and 0 otherwise.
 ** Parameters: list, value
 ** Pre-condition: list not NULL
 ** Post-condition: true or false
 *********************************************************************/
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list !=0 );
	struct Link *current = list->frontSentinel->next;
	if(list->size == 0){
		return 0;
	}
	else {
		for (int i =0; i< list->size; i++){
			if(current->value == value){
				return 1;
			}
			else {
				current = current->next;
			}
		}
	}
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
 /*********************************************************************
 ** Function: linkedListRemove
 ** Description: Removes the first occurrence of a link with the given value.
 ** Parameters: list, value
 ** Pre-condition: list not NULL
 ** Post-condition:remove the value in the bag
 *********************************************************************/
 void linkedListRemove(struct LinkedList* list, TYPE value)
 {
	 // FIXME: you must write this
	 assert(list !=0);
	 struct Link *current = list->frontSentinel->next;
	 int myval;
	 myval=0;
	 for(int i=0; i<list->size && myval ==0; i++){
		 if (current->value == value){removeLink(list, current);
			 myval =1;
		 }
		 else {
			 current = current->next;
		 }
	 }
 }
