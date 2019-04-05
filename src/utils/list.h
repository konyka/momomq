/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: list.h
 *      Version: v0.0.0
 *   Created on: Apr 4, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_LIST_H__
#define __DARKBLUE_MM_LIST_H__



struct mm_list_item {
    struct mm_list_item *next;
    struct mm_list_item *prev;
};

struct mm_list {
    struct mm_list_item *first;
    struct mm_list_item *last;
};

/*  Undefined value for initializing a list item which is not part of a list. */
#define MM_LIST_NOTINLIST ((struct mm_list_item*) -1)

/*  Use for initializing a list item statically. */
#define MM_LIST_ITEM_INITIALIZER {MM_LIST_NOTINLIST, MM_LIST_NOTINLIST}

/*  Initialise the list. */
void mm_list_init (struct mm_list *self);

/*  Terminates the list. Note that all items must be removed before the
    termination. */
void mm_list_term (struct mm_list *self);

/*  Returns 1 is list has zero items, 0 otherwise. */
int mm_list_empty (struct mm_list *self);

/*  Returns iterator to the first item in the list. */
struct mm_list_item *mm_list_begin (struct mm_list *self);

/*  Returns iterator to one past the last item in the list. */
struct mm_list_item *mm_list_end (struct mm_list *self);

/*  Returns iterator to an item prior to the one pointed to by 'it'. */
struct mm_list_item *mm_list_prev (struct mm_list *self,
    struct mm_list_item *it);

/*  Returns iterator to one past the item pointed to by 'it'. */
struct mm_list_item *mm_list_next (struct mm_list *self,
    struct mm_list_item *it);

/*  Adds the item to the list before the item pointed to by 'it'. Priot to
    insertion item should not be part of any list. */
void mm_list_insert (struct mm_list *self, struct mm_list_item *item,
    struct mm_list_item *it);

/*  Removes the item from the list and returns pointer to the next item in the
    list. Item must be part of the list. */
struct mm_list_item *mm_list_erase (struct mm_list *self,
    struct mm_list_item *item);

/*  Initialize a list item. At this point it is not part of any list. */
void mm_list_item_init (struct mm_list_item *self);

/*  Terminates a list item. Item must not be part of any list before it's
    terminated. */
void mm_list_item_term (struct mm_list_item *self);

/*  Returns 1 is the item is part of a list, 0 otherwise. */
int mm_list_item_isinlist (struct mm_list_item *self);


#endif /* __DARKBLUE_MM_LIST_H__ */



