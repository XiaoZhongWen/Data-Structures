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
    int heightOfBinaryTree_iterativePostorder(); // 后序遍历过程中, 最大栈长即为树高
    int heightOfBinaryTree_iterativeBreadth();   // 层序遍历, 最大层次即为树高
    int heightOfBinaryTree_recursion();          // 通过递归的方式求树高
    
    // 删除二叉树所有节点
    void deleteAllNode();
    
    // 判断二叉树是否是二叉查找树
    bool isBinarySearchTree();
    
    // 创建二叉树的镜像
    void createBinaryTreeMirror();
    
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
    
    // 判断二叉树是否是二叉查找树
    bool isBinarySearchTree(BSTNode<T> *node);
    
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

template <class T>
void BST<T>::iterativeInorder() {
    stack<BSTNode<T> *> travStack;
    BSTNode<T> *p = this->root;
    while (p != NULL || !travStack.empty()) {
        while (p != NULL) {
            travStack.push(p);
            p = p->left;
        }
        if (!travStack.empty()) {
            p = travStack.top();
            travStack.pop();
            visit(p);
            p = p->right;
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

template <class T>
bool BST<T>::isBinarySearchTree() {
    return isBinarySearchTree(this->root);
}

template <class T>
bool BST<T>::isBinarySearchTree(BSTNode<T> *node) {
    if (node != NULL) {
        // 1. 该节点为叶子节点
        if (node->left == NULL && node->right == NULL) {
            return true;
        }
        // 2. 该节点有左子树, 没有右子树
        if (node->left != NULL && node->right == NULL) {
            return
            node->el > node->left->el
            && isBinarySearchTree(node->left);
        }
        // 3. 该节点有右子树, 没有左子树
        if (node->right != NULL && node->left == NULL) {
            return
            node->el < node->right->el
            && isBinarySearchTree(node->right);
        }
        // 4. 该节点既有左子树也有右子树
        if (node->left != NULL && node->right != NULL) {
            return
            node->el > node->left->el
            && node->el < node->right->el
            && isBinarySearchTree(node->left)
            && isBinarySearchTree(node->right);
        }
        return false;
    } else {
        return false;
    }
}

template <class T>
void BST<T>::createBinaryTreeMirror() {
    if (root == NULL) {
        return;
    } else {
        BSTNode<T> *p = root;
        queue<BSTNode<T> *> travQuene;
        travQuene.push(p);
        while (p != NULL && (p->left != NULL || p->right != NULL)) {
            travQuene.pop();
            if (p->left != NULL && p->right == NULL) {
                // 1. p只有左子树
                travQuene.push(p->left);
                p->right = p->left;
                p->left = NULL;
            } else if (p->right != NULL && p->left == NULL) {
                // 2. p只有右子树
                travQuene.push(p->right);
                p->left = p->right;
                p->right = NULL;
            } else if (p->left != NULL && p->right != NULL) {
                // 3. p既有左子树又有右子树
                travQuene.push(p->left);
                travQuene.push(p->right);
                BSTNode<T> *node = p->left;
                p->left = p->right;
                p->right = node;
            }
            p = travQuene.front();
        }
    }
}

// 计算树的高度
// 1. 后序遍历, 记录最大栈长
template <class T>
int BST<T>::heightOfBinaryTree_iterativePostorder() {
    return 0;
}

// 2. 层序遍历, 记录层数
template <class T>
int BST<T>::heightOfBinaryTree_iterativeBreadth() {
    return 0;
}

// 3. 递归方式
template <class T>
int BST<T>::heightOfBinaryTree_recursion() {
    return 0;
}

// 删除二叉树所有节点
template <class T>
void BST<T>::deleteAllNode() {
}

#endif /* BST_hpp */
