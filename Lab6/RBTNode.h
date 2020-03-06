#pragma once

struct RBTreeNode
{
	int Data;
	bool IsBlack;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
};