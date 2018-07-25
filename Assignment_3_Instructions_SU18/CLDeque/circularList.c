#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
 /*********************************************************************
 ** Function: init
 ** Description: Allocates the list's sentinel and sets the size to 0.
 The sentinel's next and prev should point to the sentinel itself.
 ** Parameters: list
 ** Pre-condition: make sure sentinel is not NULL
 ** Post-condition: size get 0 and sentinel points to itself
 *********************************************************************/
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->sentinel = malloc(sizeof(struct Link));
	assert(list->sentinel !=0);

	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;

	list->size =0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
 /*********************************************************************
 ** Function: createLink
 ** Description:Creates a link with the given value and NULL next and prev pointers.
 ** Parameters: value
 ** Pre-condition: None
 ** Post-condition: return the link that we created
 *********************************************************************/
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link *mylink  = (struct Link *)malloc(sizeof(struct Link));
	mylink->next = NULL;
	mylink->prev = NULL;

	mylink->value = value;
	return mylink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
 /*********************************************************************
 ** Function: addLinkAfter
 ** Description:Adds a new link with the given value after the given link and
  increments the list's size.
 ** Parameters:list, link, value
 ** Pre-condition: none
 ** Post-condition:increase size by 1
 *********************************************************************/
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link *add =  createLink(value);

	add->next = link->next;
	add->prev = link;

	add->next->prev = add;
	add->prev->next = add;

	list->size++;


}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
 /*********************************************************************
 ** Function: removeLink
 ** Description:Removes the given link from the list and
 decrements the list's size.
 ** Parameters: list, link
 ** Pre-condition: None
 ** Post-condition: decrease size by 1
 *********************************************************************/
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	link->prev->next = link->next;
	link->next->prev = link->prev;
	link->next = NULL;
	link->prev = NULL;
	free(link);
	list->size--;

}

/**
 * Allocates and initializes a list.
 */
 /*********************************************************************
 ** Function: circularListCreate
 ** Description:Allocates and initializes a list.
 ** Parameters: none
 ** Pre-condition:none
 ** Post-condition: return the list
 *********************************************************************/
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
 /*********************************************************************
 ** Function: circularListDestroy
 ** Description:Deallocates every link in the list and frees the list pointer.
 ** Parameters:list
 ** Pre-condition: list not empty
 ** Post-condition: None
 *********************************************************************/
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	while (!circularListIsEmpty(list)) {
		struct Link *tmp = list->sentinel->next;
		removeLink(list, tmp);
	}
	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
 /*********************************************************************
 ** Function: circularListAddFront
 ** Description:Adds a new link with the given value to the front of the deque.
 ** Parameters: list, value
 ** Pre-condition: None
 ** Post-condition:None
 *********************************************************************/
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel,value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
 /*********************************************************************
 ** Function: circularListAddBack
 ** Description: Adds a new link with the given value to the back of the deque.
 ** Parameters: list, value
 ** Pre-condition: none
 ** Post-condition: none
 *********************************************************************/
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
 /*********************************************************************
 ** Function: circularListFront
 ** Description: Returns the value of the link at the front of the deque.
 ** Parameters: list
 ** Pre-condition:none
 ** Post-condition: the value
 *********************************************************************/
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
 /*********************************************************************
 ** Function: circularListBack
 ** Description:Returns the value of the link at the back of the deque.
 ** Parameters:list
 ** Pre-condition:none
 ** Post-condition: the value
 *********************************************************************/
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
 /*********************************************************************
 ** Function: circularListRemoveFront
 ** Description:Removes the link at the front of the deque.
 ** Parameters: list
 ** Pre-condition: none
 ** Post-condition:none
 *********************************************************************/
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
 /*********************************************************************
 ** Function: circularListRemoveBack
 ** Description:Removes the link at the back of the deque.
 ** Parameters: list
 ** Pre-condition:none
 ** Post-condition: none
 *********************************************************************/
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if (list->size == 0) {
		return 1;
	}
	return 0;
}
/**
 * Prints the values of the links in the deque from front to back.
 */
 /*********************************************************************
 ** Function: circularListPrint
 ** Description:Prints the values of the links in the deque from front to back.
 ** Parameters: list
 ** Pre-condition: none
 ** Post-condition:print the list
 *********************************************************************/
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *ptr = list->sentinel->next;
	for (int i=0; i<list->size; i++){
		printf("Printing val  link from front to back   %g\n", ptr->value);
		ptr = ptr->next;

	}

}

/**
 * Reverses the deque.
 */
 /*********************************************************************
 ** Function: circularListReverse
 ** Description: Reverses the deque.
 ** Parameters:list
 ** Pre-condition:None
 ** Post-condition: none 
 *********************************************************************/
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *ptr = list->sentinel;
	for (int i=0; i<list->size+1; i++){
		struct Link *tmp = ptr->next;

		ptr->next = ptr->prev;
		ptr->prev = tmp;
		ptr = ptr->next;
	}

}
