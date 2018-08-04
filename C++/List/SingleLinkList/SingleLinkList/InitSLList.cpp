//
//  InitSLList.cpp
//  SingleLinkList
//
//  Created by mye on 2018/8/4.
//  Copyright © 2018 mye. All rights reserved.
//

#include "InitSLList.hpp"
#include <iostream>
using namespace std;

InitSLList::InitSLList() {
    // 初始化成员变量
    this->header = this->tail = 0;
}

InitSLList::~InitSLList() {
    while (this->header != 0) {
        InitSLLNode *tmp = this->header;
        this->header = this->header->next;
        delete tmp;
        tmp = 0;
    }
    cout << "dealloc InitSLList " << this << endl;
}

bool InitSLList::isEmpty() {
    return this->header == 0;
}

void InitSLList::addToHead(int el) {
    InitSLLNode *newNode = new InitSLLNode(el, this->header);
    this->header = newNode;
    if (this->tail == 0) {
        this->tail = this->header;
    }
}

void InitSLList::addToTail(int el) {
    if (this->isEmpty()) {
        this->header = this->tail = new InitSLLNode(el);
    } else {
        InitSLLNode *newNode = new InitSLLNode(el, 0);
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

int InitSLList::deleteFromHead() {
    if (this->isEmpty()) {
        return 0;
    } else {
        int el = this->header->info;
        InitSLLNode *tmp = this->header;
        if (this->header == this->tail) {
            this->header = this->tail = 0;
        } else {
            this->header = this->header->next;
        }
        delete tmp;
        tmp = 0;
        return el;
    }
}

int InitSLList::deleteFromTail() {
    if (this->isEmpty()) {
        return 0;
    } else {
        int el = this->tail->info;
        if (this->header == this->tail) {
            InitSLLNode *tmp = this->header;
            this->header = this->tail = 0;
            delete tmp;
            tmp = 0;
        } else {
            InitSLLNode *tmp = this->header;
            while (tmp->next != this->tail) {
                tmp = tmp->next;
            }
            tmp->next = 0;
            delete this->tail;
            this->tail = tmp;
        }
        return el;
    }
}

void InitSLList::deleteNode(int el) {
    if (!isEmpty()) {
        if (this->header == this->tail && this->header->info == el) {
            delete this->header;
            this->header = this->tail = 0;
        } else if (this->header->info == el) {
            this->deleteFromHead();
        } else {
            InitSLLNode *p = this->header;
            InitSLLNode *q = p->next;
            while (q != 0 && q->info != el) {
                p = p->next;
                q = q->next;
            }
            if (q != 0 && q->info == el) {
                p->next = q->next;
                if (this->tail == q) {
                    this->tail = p;
                }
                delete q;
                q = 0;
            }
        }
    }
}

bool InitSLList::isInList(int el) const {
    if (this->header == 0) {
        return false;
    } else {
        InitSLLNode *tmp = this->header;
        while (tmp != 0) {
            if (tmp->info == el) {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
}

void InitSLList::traverse() const {
    InitSLLNode *tmp = this->header;
    while (tmp != 0) {
        cout << tmp->info << endl;
        tmp = tmp->next;
    }
}
