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

int InitSLList::count() {
    if (isEmpty()) {
        return 0;
    } else {
        int count = 1;
        InitSLLNode *tmp = this->header;
        while (tmp->next != 0) {
            tmp = tmp->next;
            count++;
        }
        return count;
    }
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
    assert(!isEmpty());
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

int InitSLList::deleteFromTail() {
    assert(!isEmpty());
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

int InitSLList::deleteNodeAt(int index) {
    int size = this->count();
    assert(index <= size && index > 0);
    int value;
    if (size == 1) {
        value = this->header->info;
        delete this->header;
        this->header = this->tail = 0;
    } else {
        if (index == 1) {
            value = this->header->info;
            InitSLLNode *tmp = this->header;
            this->header = this->header->next;
            delete tmp;
            tmp = 0;
        } else if (index == size) {
            value = this->tail->info;
            InitSLLNode *tmp = this->header;
            while (tmp->next != this->tail) {
                tmp = tmp->next;
            }
            tmp->next = 0;
            delete this->tail;
            this->tail = tmp;
        } else {
            int i = 2;
            InitSLLNode *p = this->header;
            InitSLLNode *q = this->header->next;
            while (i != index) {
                p = p->next;
                q = q->next;
                i++;
            }
            value = q->info;
            p->next = q->next;
            delete q;
            q = 0;
        }
    }
    
    return value;
}

bool InitSLList::isEqual(InitSLList *list) {
    if (this->count() != list->count()) {
        return false;
    } else if (this->isEmpty() && list->isEmpty()) {
        return true;
    } else {
        InitSLLNode *p = this->header;
        InitSLLNode *q = list->header;
        bool result = true;
        while (p != 0) {
            if (p->info != q->info) {
                result = false;
                break;
            }
            p = p->next;
            q = q->next;
        }
        return result;
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

void InitSLList::reverse() {
    int size = this->count();
    if (this->isEmpty() || size == 1) {
        return;
    } else if(size == 2) {
        InitSLLNode *tmp = this->header;
        this->tail->next = this->header;
        this->header->next = 0;
        this->header = tail;
        this->tail = tmp;
    } else {
        InitSLLNode *p = this->header;
        InitSLLNode *q = p->next;
        InitSLLNode *k = q->next;
        p->next = 0;
        while (k != this->tail) {
            q->next = p;
            p = q;
            q = k;
            k = k->next;
        }
        q->next = p;
        k->next = q;
        this->tail = this->header;
        this->header = k;
        p = 0;
        q = 0;
        k = 0;
    }
}
