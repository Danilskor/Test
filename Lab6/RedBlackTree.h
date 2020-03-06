#pragma once
#include "RBTNode.h"


struct RBTree
{
	int NumberOfRotation;
	RBTreeNode* Root;
	RBTreeNode* Nil;
};

RBTree* InitTree();
RBTreeNode* CreationNode(RBTree* );
bool IsOnLeft(RBTreeNode* );
RBTreeNode* GetBrother(RBTreeNode* , RBTree* );
RBTreeNode* Uncle(RBTreeNode* , RBTree* );
void RotationLeft(RBTreeNode*& , RBTree* );
void RotationRight(RBTreeNode*& , RBTree* );
RBTreeNode* SearchNode(RBTreeNode *, int , RBTreeNode* );
RBTreeNode* InsertBST(RBTreeNode *, RBTreeNode *, RBTree* );
void InsertNode(int , RBTreeNode *, RBTree* );
void FixInsert(RBTreeNode *&, RBTree* );
RBTreeNode* MinimumDataNode(RBTreeNode *, RBTreeNode* );
RBTreeNode* ReplaceBST(RBTreeNode *, RBTreeNode* );
void DeleteNode(RBTreeNode *&, RBTree* );
void DeleteNodeByData(int , RBTree* );
void FixDoubleBlack(RBTreeNode * , RBTree* );
void DeleteTree(RBTree* , RBTreeNode* );