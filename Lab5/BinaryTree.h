#pragma once

#include <queue>
#include <cstring>
#include "BinaryTreeNode.h"

using namespace std;

struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
};

BinaryTree* CreateBinaryTree();
BinaryTreeNode* CreateNode(BinaryTreeNode*);
void Insert(BinaryTreeNode*, BinaryTree*, int);
void ChooseDeleteNode(BinaryTreeNode*, BinaryTree*);
BinaryTreeNode* FindMinMax(BinaryTreeNode*, const char [3]);
BinaryTreeNode* FindElement(BinaryTreeNode*, int);
void DeleteTree(BinaryTreeNode*);
BinaryTreeNode* DeleteNode(BinaryTree*, int, BinaryTreeNode *&);