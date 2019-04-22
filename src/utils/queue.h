/**
 *===========================================================================
 *  None Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: queue.h
 *      Version: v0.0.0
 *   Created on: 2019-04-22 18:16:25 by konyka
 *  Modified by: konyka
 *Modified time: 2019-04-22 18:51:55
 *       Editor: Sublime Text3
 *        Email: 
 *  Description: 
 * -------------------------------------------------------------------------
 *      History: 
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_QUEUE_H__
#define __DARKBLUE_MM_QUEUE_H__

/**
 * 使用-1初始化队列项---不属于任何队列。
 */
#define MM_QUEUE_NOTINQUEUE ((struct mm_queue_item*) -1)

/**
 * 静态初始化队列项。
 */
#define MM_QUEUE_ITEM_INITIALIZER {MM_LIST_NOTINQUEUE}

struct mm_queue_item {
    struct mm_queue_item *next;
};

struct mm_queue {
    struct mm_queue_item *head;
    struct mm_queue_item *tail;
};

/**
 * [mm_queue_init  初始化队列]
 * @Author   konyka
 * @DateTime 2019-04-22T18:26:14+0800
 * @param    self                     [队列结构体]
 */
void mm_queue_init (struct mm_queue *self);

/**
 * [mm_queue_term  销毁队列。注意：在销毁队列之前，必须手动清空该队列。]
 * @Author   konyka
 * @DateTime 2019-04-22T18:25:53+0800
 * @param    self                     [description]
 */
void mm_queue_term (struct mm_queue *self);

/**
 * [mm_queue_empty  判断队列是否为空。]
 * @Author   konyka
 * @DateTime 2019-04-22T18:30:17+0800
 * @param    self                     [description]
 * @return                            [如果队列中没有任何项，返回1，否则返回0.]
 */
int mm_queue_empty (struct mm_queue *self);

/**
 * [mm_queue_push  把一个元素插入到队列中。]
 * @Author   konyka
 * @DateTime 2019-04-22T18:31:59+0800
 * @param    self                     [要插入的队列]
 * @param    item                     [要插入的项]
 */
void mm_queue_push (struct mm_queue *self, struct mm_queue_item *item);

/**
 * [mm_queue_remove  移除队列中的项]
 * @Author   konyka
 * @DateTime 2019-04-22T18:32:49+0800
 * @param    self                     [要操作的队列]
 * @param    item                     [要移除的项]
 */
void mm_queue_remove (struct mm_queue *self, struct mm_queue_item *item);

/*  Retrieves one element from the queue. The element is removed
    from the queue. Returns NULL if the queue is empty. */
/**
 * [mm_queue_pop  从队列中获取一个项。并从队列中移除该项。]
 * @Author   konyka
 * @DateTime 2019-04-22T18:34:14+0800
 * @param    self                     [要操作的队列]
 * @return                            [如果队列为空，返回NULL，否则返回pop出的项。]
 */
struct mm_queue_item *mm_queue_pop (struct mm_queue *self);

/*
/**
 * [mm_queue_item_init  初始化队列项。此时，该项并不属于任何队列。]
 * @Author   konyka
 * @DateTime 2019-04-22T18:36:40+0800
 * @param    self                     [要操作的队列项]
 */
void mm_queue_item_init (struct mm_queue_item *self);

/**
 * [mm_queue_item_term  销毁队列项。在该调用之前，该项不能在某个队列中。]
 * @Author   konyka
 * @DateTime 2019-04-22T18:37:48+0800
 * @param    self                     [操作的队列项。]
 */
void mm_queue_item_term (struct mm_queue_item *self);

/**
 * [mm_queue_item_isinqueue  查找项目是否在队列中]
 * @Author   konyka
 * @DateTime 2019-04-22T18:50:27+0800
 * @param    self                     [要查找的项]
 * @return                            [在队列中返回1，否则返回0]
 */
int mm_queue_item_isinqueue (struct mm_queue_item *self);


#endif /* __DARKBLUE_MM_QUEUE_H__ */
