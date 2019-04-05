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


/**
 * 使用未定义的值初始化列表项，用来表示非列表项。
 */
#define MM_LIST_NOTINLIST ((struct mm_list_item*) -1)

/**
 * 静态方式初始化列表项
 */
#define MM_LIST_ITEM_INITIALIZER {MM_LIST_NOTINLIST, MM_LIST_NOTINLIST}


/**
 * [mm_list_init  初始化list]
 * @param self [需要对其操作的列表]
 */
void mm_list_init (struct mm_list *self);


/**
 * [mm_list_term  销毁list,需要注意的是，在销毁之前，需要移除所有的项.]
 * @param self [需要对其操作的列表]
 */
void mm_list_term (struct mm_list *self);


/**
 * [mm_list_empty  判断list是否为空，即没有任何列表项。]
 * @param  self [需要对其操作的列表]
 * @return      [1 :list中有0个项，否则返回0]
 */
int mm_list_empty (struct mm_list *self);


/**
 * [mm_list_begin  返回list中指向第一个列表项的迭代器]
 * @param  self [需要对其操作的列表]
 * @return      [返回list中指向第一个列表项的迭代器]
 */
struct mm_list_item *mm_list_begin (struct mm_list *self);


/**
 * [mm_list_end  返回list中指向最后一个列表项的迭代器]
 * @param  self [需要对其操作的列表]
 * @return      [返回list中指向最后一个列表项的迭代器]
 */
struct mm_list_item *mm_list_end (struct mm_list *self);


/**
 * [mm_list_prev  返回指向参数it的前一项的迭代器，]
 * @param  self [需要对其操作的列表]
 * @param  it   [指向的列表项]
 * @return      [返回指向参数it的前一项的迭代器]
 */
struct mm_list_item *mm_list_prev (struct mm_list *self,
    struct mm_list_item *it);

/*  Returns iterator to one past the item pointed to by 'it'. */
/**
 * [mm_list_next  返回指向参数it的后一项的迭代器]
 * @param  self [需要对其操作的列表]
 * @param  it   [指向的列表项]
 * @return      [返回指向参数it的后一项的迭代器]
 */
struct mm_list_item *mm_list_next (struct mm_list *self,
    struct mm_list_item *it);

/*  Adds the item to the list before the item pointed to by 'it'. Priot to
    insertion item should not be part of any list. */
/**
 * [mm_list_insert  将item插入到list中，it指向的列表项的前面。
 *                                 在插入之前，item不应该是其他list的一部分。]
 * @param self [需要对其操作的列表]
 * @param item [description]
 * @param it   [指向的列表项]
 */
void mm_list_insert (struct mm_list *self, struct mm_list_item *item,
    struct mm_list_item *it);


/**
 * [mm_list_erase  从列表self中移除列表项item，并返回列表中下一个项的指针。其中参数
 *                             item必须是列表项的一部分。]
 * @param  self [需要对其操作的列表]
 * @param  item [要移除列表项item]
 * @return      [item之后的列表项指针]
 */
struct mm_list_item *mm_list_erase (struct mm_list *self,
    struct mm_list_item *item);


/**
 * [mm_list_item_init  初始化列表项。此刻，该列表项不属于任何list。]
 * @param self [需要对其操作的列表]
 */
void mm_list_item_init (struct mm_list_item *self);


/**
 * [mm_list_item_term  销毁列表项。在销毁列表项之前，它不能属于任何一个列表。]
 * @param self [需要对其操作的列表]
 */
void mm_list_item_term (struct mm_list_item *self);

/*  Returns 1 is the item is part of a list, 0 otherwise. */
/**
 * [mm_list_item_isinlist  判断项是否属于列表self]
 * @param  self [需要对其操作的列表]
 * @return      [1：在列表中；0：不在列表中]
 */
int mm_list_item_isinlist (struct mm_list_item *self);


#endif /* __DARKBLUE_MM_LIST_H__ */



