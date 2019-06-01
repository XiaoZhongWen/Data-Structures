//
//  BinaryTree.h
//  BinaryTree
//
//  Created by 肖仲文 on 2019/4/6.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <stdio.h>

typedef int DataType;

typedef struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    DataType data;
} BinaryTreeNode;


/**
 创建二叉树

 @param data 元素值
 @return root 根节点
 */
BinaryTreeNode* createBinaryTree(DataType data);

/**
 判断树是否为空

 @param root 根节点
 @return 1 树为空
 */
int isEmpty(BinaryTreeNode *root);

/**
 清除二叉树

 @param root 根节点
 */
void clearBinaryTre(BinaryTreeNode *root);

/**
 插入元素

 @param root 根节点
 @param data 元素值
 */
void insertElement(BinaryTreeNode *root, DataType data);

/**
 中序遍历二叉树
 
 @param treeNode 二叉树节点
 */
void inOrder(BinaryTreeNode *treeNode);

/**
 层序遍历二叉树

 @param treeNode 二叉树节点
 */
void tierOrder(BinaryTreeNode *treeNode);

#endif /* BinaryTree_h */
