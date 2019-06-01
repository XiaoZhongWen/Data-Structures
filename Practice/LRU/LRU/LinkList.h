//
//  LinkList.h
//  LRU
//
//  Created by 肖仲文 on 2019/2/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

/**
 *  LRU缓存淘汰算法
 *  当访问一个数据元素时:
 *      1. 该数据元素在链表中, 则将该元素从链表中删除, 然后添加到链表头部
 *      2. 该数据元素不在链表中
            2.1 缓存已满, 删除链表尾部元素, 将新元素添加到链表头部
            2.2 缓存未满, 直接将新元素添加到链表头部
 */

#define kCacheSize 10

typedef int DataType;
typedef struct LinkNode {
    DataType e;
    int length;
    struct LinkNode * next;
}LinkNode, *LinkList;

/**
 *  初始化链表
 */
void init(LinkList *l);

/**
 *  判断缓存是否满
 *  缓存满:返回1, 不满:返回0
 */
int isFull(LinkList l);

/**
 *  向链表头部添加一个元素
 */
void addElementAtBegin(LinkList l, DataType e);

/**
 *  删除链表尾部的一个元素
 *  删除成功返回1, 否则返回0
 */
void deleteElementAtEnd(LinkList l);

/**
 *  删除链表中的一个元素
 *  删除成功返回1, 否则返回0
 */
int deleteElement(LinkList l, DataType e);

/**
 *  查询链表中的一个元素
 *  查找的元素查找返回1, 否则返回0
 */
int queryElemnt(LinkList l, DataType e);

/**
 *  打印链表中的所有元素
 */
void printAll(LinkList l);

/**
 *  添加缓存元素e到链表l
 */
void addCache(LinkList l, DataType e);

/**
 *  获取链表l中第一个节点值为e的节点指针
 */
LinkNode* getNodeByValue(LinkList l, DataType e);

/**
 *  获取链表l中最后一个节点的指针
 */
LinkNode* getNodeAtEnd(LinkList l);

/**
 *  反转链表l
 */
void reverseLinkList(LinkList l);

/**
 *  检测链表l中是否有环
 *  有环返回1, 否则返回0
 */
int checkCycleInLinkList(LinkList l);

/**
 *  将链表l2合并到链表l1上
 */
void mergeLinkList(LinkList l1, LinkList l2);

/**
 *  删除链表l上倒数第reverseIndex个节点
 */
void removeNodeAtReverseIndex(LinkList l, int reverseIndex);

/**
 *  获取链表的中间节点
 */
LinkNode* findMiddleNode(LinkList l);


#endif /* LinkList_h */
