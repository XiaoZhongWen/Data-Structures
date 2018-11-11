//
//  BST.hpp
//  Binary Tree
//
//  Created by mye on 2018/9/15.
//  Copyright © 2018 mye. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <iostream>
#include "queue"
#include "stack"
#include "BSTNode.hpp"

typedef enum : int {
    BinaryTreeNormalNode = 0,
    BinaryTreeLeafNode,
    BinaryTreeRightNode
} BinaryTreeNodeType;

template <class T>
class BST {
public:
    BST();
    ~BST();

    // 清空树
    void clear();

    // 判空
    bool isEmpty();
    
    // 查找元素
    T* search(const T &el);
    
    // 插入元素
    void insert(const T &el);
    
    // 删除元素
    void deleteElement(const T el);
    
    void preorder() {
        this->preorder(this->root);
    }
    
    void inorder() {
        this->inorder(this->root);
    }
    
    void postorder() {
        this->postorder(this->root);
    }

    // 广度优先搜索遍历
    void breadth();
    
    /**
     *  树的遍历
     *  深度优先搜索遍历 - 非递归方式实现
     */
    void iterativePreorder();   // 先序遍历
    void iterativeInorder();    // 中序遍历
    void iterativePostorder();  // 后序遍历
    
    // 获取指定类型节点的个数
    int treeNodeCountWithNodeType(BinaryTreeNodeType nodeType);
    
    // 计算树的高度
    int heightOfBinaryTree();
    
    // 删除二叉树所有节点
    void deleteAllNode();
    
protected:
    /**
     *  树的遍历
     *  深度优先搜索遍历 - 递归方式实现
     */
    // 先序遍历
    void preorder(BSTNode<T> *node);

    // 中序遍历
    void inorder(BSTNode<T> *node);

    // 后序遍历
    void postorder(BSTNode<T> *node);
    
    // 删除元素
    void deleteByMerging(BSTNode<T>*&);
    void deleteByCoping(BSTNode<T>*&);
    
private:
    BSTNode<T> *root;
};


template <class T>
/**
 构造方法
 */
BST<T>::BST() {
    root = 0;
}

template <class T>
bool BST<T>::isEmpty() {
    return this->root == 0;
}

// 先序遍历 - 非递归方式
template <class T>
void BST<T>::iterativePreorder() {
    BSTNode<T> *p = this->root;
    stack<BSTNode<T> *> travStack;
    if (p) {
        travStack.push(p);
        while (!travStack.empty()) {
            p = travStack.top();
            travStack.pop();
            visit(p);
            if (p->right) {
                travStack.push(p->right);
            }
            if (p->left) {
                travStack.push(p->left);
            }
        }
    }
}

// 先序遍历 - 递归方式
template <class T>
void BST<T>::preorder(BSTNode<T> *node) {
    if (node) {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

template <class T>
void BST<T>::inorder(BSTNode<T> *node) {
    if (node) {
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
}

template <class T>
void BST<T>::postorder(BSTNode<T> *node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
}

// 广度优先搜索遍历
template <class T>
void BST<T>::breadth() {
    BSTNode<T> *p = this->root;
    queue<BSTNode<T> *> travQuene;
    if (p) {
        travQuene.push(p);
        while (!travQuene.empty()) {
            p = travQuene.front();
            visit(p);
            travQuene.pop();
            if (p->left != 0) {
                travQuene.push(p->left);
            }
            if (p->right != 0) {
                travQuene.push(p->right);
            }
            p = travQuene.front();
        }
    }
}

// 插入元素
template <class T>
void BST<T>::insert(const T &el) {
    if (root == 0) {
        root = new BSTNode<T>(el);
        return;
    }
    BSTNode<T> *p = root;
    BSTNode<T> *preNode = 0;
    while (p != 0) {
        preNode = p;
        if (el < p->el) {
            p = preNode->left;
        } else {
            p = preNode->right;
        }
    }
    BSTNode<T> *newNode = new BSTNode<T>(el);
    if (el < preNode->el) {
        preNode->left = newNode;
    } else {
        preNode->right = newNode;
    }
}

// 删除元素
template <class T>
void BST<T>::deleteElement(const T el) {
    BSTNode<T> *p = this->root;
    BSTNode<T> *prev = 0;
    while (p) {
        if (p->el == el) {
            break;
        }
        prev = p;
        if (el < p->el) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (p && p->el == el) {
        if (root->el == el) {
            this->deleteByCoping(root);
        } else if (prev->left == p) {
            this->deleteByCoping(prev->left);
        } else {
            this->deleteByCoping(prev->right);
        }
    } else if (this->root) {
        cout << "key: " << el << " not in this tree." << endl;
    } else {
        cout << "this tree is empty." << endl;
    }
}

template <class T>
void BST<T>::deleteByCoping(BSTNode<T> *&p) {
    if (p) {
        BSTNode<T> *temp = p;
        if (!p->left) {
            // 1. 待删除的元素没有左孩子
            p = p->right;
        } else if (!p->right) {
            // 2. 待删除的元素没有右孩子
            p = p->left;
        } else {
            // 3. 待删除的元素既有左孩子又有右孩子
            // 3.1 移动到待删除元素的左孩子的最右边节点
            temp = p->left;
            while (temp->right) {
                temp = temp->right;
            }
            // 3.2 待删除元素的右孩子成为待删除元素的左孩子的最右边节点的右孩子
            temp->right = p->right;
            temp = p;
            // 3.3 待删除元素的左孩子取代待删除元素的位置
            p = p->left;
        }
        delete temp;
    }
}

template <class T>
void visit(BSTNode<T> *node) {
    cout << node->el << endl;
}

template <class T>
int BST<T>::treeNodeCountWithNodeType(BinaryTreeNodeType nodeType) {
    BSTNode<T> *p = this->root;
    if (!p) {
        return 0;
    } else {
        int normalNodeCount = 0;
        int leafNodeCount = 0;
        int rightNodeCount = 0;
        
        queue<BSTNode<T> *> nodeQueue;
        nodeQueue.push(p);
        while (!nodeQueue.empty()) {
            p = nodeQueue.front();
            nodeQueue.pop();
            normalNodeCount++;
            if (p->left) {
                nodeQueue.push(p->left);
            }
            if (p->right) {
                nodeQueue.push(p->right);
                rightNodeCount++;
            }
            if (!p->left && !p->right) {
                leafNodeCount++;
            }
        }
        
        int count = 0;
        switch (nodeType) {
            case BinaryTreeNormalNode:
                count = normalNodeCount;
                break;
            case BinaryTreeLeafNode:
                count = leafNodeCount;
                break;
            case BinaryTreeRightNode:
                count = rightNodeCount;
                break;
            default:
                break;
        }
        return count;
    }
}

#warning logic error
// 计算树的高度
template <class T>
int BST<T>::heightOfBinaryTree() {
    if (!this->root) {
        return 0;
    } else {
        int height = 0;
        stack<BSTNode<T> *> binaryStack;
        BSTNode<T> *p = this->root;
        binaryStack.push(p);
        while (!binaryStack.empty()) {
            p = binaryStack.top();
            binaryStack.pop();
            if (p->right) {
                binaryStack.push(p->right);
            }
            if (p->left) {
                binaryStack.push(p->left);
            }
        }
        return height;
    }
}

// 删除二叉树所有节点
template <class T>
void BST<T>::deleteAllNode() {
}

#endif /* BST_hpp */
