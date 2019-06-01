//
//  LinkList.c
//  LRU
//
//  Created by 肖仲文 on 2019/2/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "LinkList.h"
#include "stdlib.h"
#include "stdio.h"

/**
 *  初始化链表
 */
void init(LinkList *l) {
    *l = (LinkList)malloc(sizeof(LinkNode));
    (*l)->e = 0;
    (*l)->length = 0;
    (*l)->next = NULL;
}

/**
 *  判断缓存是否满
 *  缓存满:返回1, 不满:返回0
 */
int isFull(LinkList l) {
    LinkList p;
    p = l->next;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length >= kCacheSize;
}

/**
 *  向链表头部添加一个元素
 */
void addElementAtBegin(LinkList l, DataType e) {
    LinkList p = l;
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    node->e = e;
    node->next = NULL;
    if (p->next) {
        node->next = p->next;
    }
    p->next = node;
    l->length++;
}

/**
 *  删除链表尾部的一个元素
 *  删除成功返回1, 否则返回0
 */
void deleteElementAtEnd(LinkList l) {
    LinkList p = l->next;
    while (p->next != NULL) {
        p = p->next;
    }
    if (p) {
        l->length--;
        free(p);
    }
}

/**
 *  删除链表中的一个元素
 *  删除成功返回1, 否则返回0
 */
int deleteElement(LinkList l, DataType e) {
    LinkList q = l->next;
    LinkList p = l;
    while (q != NULL) {
        if (q->e == e) {
            p->next = q->next;
            l->length--;
            free(q);
            return 1;
        }
        p = p->next;
        q = q->next;
    }
    return 0;
}

/**
 *  查询链表中的一个元素
 *  查找的元素查找返回1, 否则返回0
 */
int queryElemnt(LinkList l, DataType e) {
    LinkList p = l->next;
    while (p != NULL && p->e != e) {
        p = p->next;
    }
    return p != NULL;
}

/**
 *  打印链表中的所有元素
 */
void printAll(LinkList l) {
    LinkList p = l->next;
    while (p) {
        printf("%d\n", p->e);
        p = p->next;
    }
}

/**
 *  添加缓存元素e到链表l
 */
void addCache(LinkList l, DataType e) {
    int isExist = queryElemnt(l, e);
    if (isExist) {
        deleteElement(l, e);
        addElementAtBegin(l, e);
    } else {
        if (isFull(l)) {
            deleteElementAtEnd(l);
            addElementAtBegin(l, e);
        } else {
            addElementAtBegin(l, e);
        }
    }
}

/**
 *  获取链表l中第一个节点值为e的节点指针
 */
LinkNode* getNodeByValue(LinkList l, DataType e) {
    LinkList p = l->next;
    while (p) {
        if (p->e == e) {
            break;
        } else {
            p = p->next;
        }
    }
    return p;
}

/**
 *  获取链表l中最后一个节点的指针
 */
LinkNode* getNodeAtEnd(LinkList l) {
    LinkList p = l->next;
    while (p->next) {
        p = p->next;
    }
    return p;
}

/**
 *  反转链表l
 */
void reverseLinkList(LinkList l) {
    if (l == NULL || l->next == NULL) {
        return;
    }
    LinkNode *p = l;
    LinkNode *q = l->next;
    LinkNode *r = q->next;
    while (r != NULL) {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    l->next->next = NULL;
    l->next = q;
}

/**
 *  检测链表l中是否有环
 *  有环返回1, 否则返回0
 */
int checkCycleInLinkList(LinkList l) {
    LinkNode *p = l->next;
    LinkNode *q = p;
    while (p && q) {
        printf("p-> %d -- q-> %d\n", p->e, q->e);
        q = q->next;
        if (q) {
            q = q->next;
        } else {
            break;
        }
        p = p->next;
        if (p == q) {
            return 1;
        }
    }
    return 0;
}

/**
 *  将链表l2合并到链表l1上
 */
void mergeLinkList(LinkList l1, LinkList l2) {
    LinkNode *p = l1;
    LinkNode *q = p->next;
    LinkNode *r = l2->next;
    while (q && r) {
        LinkNode *t = r->next;
        if (q->e > r->e) {
            r->next = q;
            p->next = r;
            p = r;
            r = t;
        } else {
            q = q->next;
            p = p->next;
        }
    }
    if (r) {
        p->next = r;
    }
}

/**
 *  删除链表l上倒数第reverseIndex个节点
 */
void removeNodeAtReverseIndex(LinkList l, int reverseIndex) {
    LinkNode *p = l;
    LinkNode *q = p->next;
    int count = 1;
    while (q && count < reverseIndex) {
        q = q->next;
        count++;
    }
    if (count == reverseIndex && q) {
        while (q->next) {
            q = q->next;
            p = p->next;
        }
        LinkNode *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}

/**
 *  获取链表的中间节点
 */
LinkNode* findMiddleNode(LinkList l) {
    LinkNode *p = l;
    LinkNode *q = l;
    while (p && q) {
        p = p->next;
        q = q->next;
        if (q) {
            q = q->next;
        }
        if (q && q->next == NULL) {
            break;
        }
    }
    return p;
}
