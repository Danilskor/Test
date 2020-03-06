#include "RedBlackTree.h"

RBTreeNode* CreationNode(RBTree* tree)
{
	RBTreeNode* node = new RBTreeNode;
	node->Left = node->Right = node->Parent = tree->Nil;
	return node;
}

RBTree* InitTree()
{
	RBTree* tree = new RBTree;
	tree->Nil = new RBTreeNode;
	tree->Nil->IsBlack = true;
	tree->Root = tree->Nil;
	return tree;
}

bool IsOnLeft(RBTreeNode* node)
{
	return node == node->Parent->Left;
}

RBTreeNode* GetBrother(RBTreeNode* node, RBTree* tree)
{
	RBTreeNode* nil = tree->Nil;
	if (node->Parent == nil)
	{
		return nullptr;
	}
	if (IsOnLeft(node))
	{
		return node->Parent->Right;
	}
	else
	{
		return node->Parent->Left;
	}
}

RBTreeNode* Uncle(RBTreeNode* node, RBTree* tree)
{
	if (node->Parent == tree->Nil or node->Parent->Parent == tree->Nil)
	{
		return tree->Nil;
	}
	if (IsOnLeft(node->Parent))
	{
		return node->Parent->Parent->Right;
	}
	else
	{
		return node->Parent->Parent->Left;
	}
}

void RotationRight(RBTreeNode*& node, RBTree* tree)
{
	tree->NumberOfRotation++;
	RBTreeNode *left = node->Left;
	node->Left = left->Right;
	if (node->Left != tree->Nil)
	{
		node->Left->Parent = node;
	}
	left->Parent = node->Parent;
	if (node->Parent == tree->Nil)
	{
		tree->Root = left;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = left;
	}
	else
	{
		node->Parent->Right = left;
	}
	left->Right = node;
	node->Parent = left;
}

void RotationLeft(RBTreeNode*& node, RBTree* tree)
{
	tree->NumberOfRotation++;
	RBTreeNode *right = node->Right;
	node->Right = right->Left;

	if (node->Right != tree->Nil)
	{
		node->Right->Parent = node;
	}
	right->Parent = node->Parent;
	if (node->Parent == tree->Nil)
	{
		tree->Root = right;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = right;
	}
	else
	{
		node->Parent->Right = right;
	}
	right->Left = node;
	node->Parent = right;
}

RBTreeNode* SearchNode(RBTreeNode *root, int data, RBTreeNode* nil)
{
	if (root == nil)
	{
		return nil;
	}
	if (root->Data == data)
	{
		return root;
	}
	if (root->Data > data)
	{
		SearchNode(root->Left, data, nil);
	}
	else
	{
		SearchNode(root->Right, data, nil);
	}
}

RBTreeNode* InsertBST(RBTreeNode *root, RBTreeNode *insertNode, RBTree* tree)
{
	if (tree->Root == tree->Nil)
	{
		root = insertNode;
		tree->Root = root;
		return insertNode;
	}
	if (root == tree->Nil)
	{
		return insertNode;
	}
	if (insertNode->Data < root->Data)
	{
		root->Left = InsertBST(root->Left, insertNode, tree);
		root->Left->Parent = root;
	}
	else
	{
		root->Right = InsertBST(root->Right, insertNode, tree);
		root->Right->Parent = root;
	}
	return root;
}

void InsertNode(int data, RBTreeNode* root, RBTree* tree)
{
	if (SearchNode(root, data, tree->Nil) != tree->Nil)
	{
		return;
	}
	RBTreeNode* toInsert = new RBTreeNode;
	toInsert->Data = data;
	toInsert->Left = tree->Nil;
	toInsert->Right = tree->Nil;
	toInsert->Parent = tree->Nil;
	toInsert->IsBlack = false;
	tree->NumberOfRotation = 0;
	root = InsertBST(tree->Root, toInsert, tree);
	FixInsert(toInsert, tree);
}

void FixInsert(RBTreeNode *&insertedNode, RBTree* tree)
{
	RBTreeNode* nil = tree->Nil;
	RBTreeNode* root = tree->Root;
	RBTreeNode* parent = nil;
	RBTreeNode* grandParent = nil;
	while (insertedNode != root && !insertedNode->IsBlack
		&& !insertedNode->Parent->IsBlack)
	{
		parent = insertedNode->Parent;
		grandParent = parent->Parent;
		if (parent == grandParent->Left)
		{
			RBTreeNode *uncle = grandParent->Right;
			if (!uncle->IsBlack)
			{
				uncle->IsBlack = true;
				parent->IsBlack = true;
				grandParent->IsBlack = false;
				insertedNode = grandParent;
			}
			else
			{
				if (insertedNode == parent->Right)
				{
					RotationLeft(parent, tree);
					insertedNode = parent;
					parent = insertedNode->Parent;
				}
				RotationRight(grandParent, tree);
				bool tempColor;
				tempColor = parent->IsBlack;
				parent->IsBlack = grandParent->IsBlack;
				grandParent->IsBlack = tempColor;
				insertedNode = parent;
			}
		}
		else
		{
			RBTreeNode *uncle = grandParent->Left;
			if (!uncle->IsBlack)
			{
				uncle->IsBlack = true;
				parent->IsBlack = true;
				grandParent->IsBlack = false;
				insertedNode = grandParent;
			}
			else
			{
				if (insertedNode == parent->Left)
				{
					RotationRight(parent, tree);
					insertedNode = parent;
					parent = insertedNode->Parent;
				}
				RotationLeft(grandParent, tree);
				bool tempColor;
				tempColor = parent->IsBlack;
				parent->IsBlack = grandParent->IsBlack;
				grandParent->IsBlack = tempColor;
				insertedNode = parent;
			}
		}
	}
	tree->Root->IsBlack = true;
}

RBTreeNode *MinimumDataNode (RBTreeNode *root, RBTreeNode* nil)
{
	RBTreeNode *minNode = root;
	while (minNode->Left != nil)
	{
		minNode = minNode->Left;
	}
	return minNode;
}

RBTreeNode* ReplaceBST(RBTreeNode *node, RBTreeNode* nil)
{
	if (node->Left != nil && node->Right != nil)
	{
		return MinimumDataNode(node->Right, nil);
	}
	if (node->Left == nil && node->Right == nil)
	{
		return nil;
	}
	if (node->Left != nil)
	{
		return node->Left;
	}
	else
	{
		return node->Right;
	}
}

void DeleteNode(RBTreeNode *&deleteNode, RBTree* tree)
{
	RBTreeNode* nil = tree->Nil;
	RBTreeNode* root = tree->Root;
	RBTreeNode *replacedNode = ReplaceBST(deleteNode, nil);
	bool doubleBlack = ((replacedNode == nil || replacedNode->IsBlack)
		&& (deleteNode->IsBlack));
	RBTreeNode *parent = deleteNode->Parent;
	if (replacedNode == nil)
	{
		if (deleteNode == root)
		{
			tree->Root = nil;
		}
		else
		{
			if (doubleBlack)
			{
				FixDoubleBlack(deleteNode, tree);
			}
			else
			{
				if (GetBrother(deleteNode, tree) != nil)
				{
					GetBrother(deleteNode, tree)->IsBlack = false;
				}
			}
			if (IsOnLeft(deleteNode))
			{
				parent->Left = nil;
			}
			else
			{
				parent->Right = nil;
			}
		}
		delete deleteNode;
		return;
	}
	if (deleteNode->Left == nil || deleteNode->Right == nil)
	{
		if (deleteNode == tree->Root)
		{
			deleteNode->Data = replacedNode->Data;
			deleteNode->Left = nil;
			deleteNode->Right = nil;
			delete replacedNode;
		}
		else
		{
			if (IsOnLeft(deleteNode))
			{
				parent->Left = replacedNode;
			}
			else
			{
				parent->Right = replacedNode;
			}
			replacedNode->Parent = parent;
			if (doubleBlack)
			{
				FixDoubleBlack(replacedNode, tree);
			}
			else
			{
				replacedNode->IsBlack = false;
			}
		}
		return;
	}
	int temp = replacedNode->Data;
	replacedNode->Data = deleteNode->Data;
	deleteNode->Data = temp;
	DeleteNode(replacedNode, tree);
}

void DeleteNodeByData(int data, RBTree* tree)
{
	RBTreeNode* root = tree->Root;
	RBTreeNode* nil = tree->Nil;
	if (root == nil)
	{
		return;
	}
	RBTreeNode *toDelete = SearchNode(root, data, tree->Nil);
	if (toDelete == nil)
	{
		return;
	}
	DeleteNode(toDelete, tree);
}

void FixDoubleBlack(RBTreeNode * node, RBTree* tree)
{
	RBTreeNode* nil = tree->Nil;
	if (node == tree->Root)
	{
		return;
	}
	RBTreeNode *brother = GetBrother(node, tree);
	RBTreeNode *parent = node->Parent;
	if (brother == nil)
	{
		FixDoubleBlack(parent, tree);
	}
	else
	{
		if (!brother->IsBlack)
		{
			parent->IsBlack = false;
			brother->IsBlack = true;
			if (IsOnLeft(brother))
			{
				RotationRight(parent,tree);
			}
			else
			{
				RotationLeft(parent, tree);
			}
			FixDoubleBlack(node, tree);
		}
		else
		{
			if (!brother->Left->IsBlack || !brother->Right->IsBlack)
			{
				if (brother->Left != nil && brother->Left->IsBlack == false)
				{
					if (IsOnLeft(brother))
					{
						brother->Left->IsBlack = parent->IsBlack;
						brother->IsBlack = parent->IsBlack;
						RotationRight(parent, tree);
					}
					else
					{
						brother->Left->IsBlack = parent->IsBlack;
						RotationRight(brother, tree);
						RotationLeft(parent, tree);
					}
				}
				else
				{
					if (IsOnLeft(brother))
					{
						brother->Right->IsBlack = parent->IsBlack;
						RotationLeft(brother, tree);
						RotationRight(parent, tree);
					}
					else
					{
						brother->Right->IsBlack = brother->IsBlack;
						brother->IsBlack = parent->IsBlack;
						RotationLeft(parent, tree);
					}
				}
				parent->IsBlack = true;
			}
			else
			{
				brother->IsBlack = false;
				if (parent->IsBlack == true)
				{
					FixDoubleBlack(parent, tree);
				}
				else
				{
					parent->IsBlack = true;
				}
			}
		}
	}
}

void DeleteTree(RBTree* tree, RBTreeNode* node)
{
	if (node == tree->Nil)
	{
		return;
	}
	DeleteTree(tree, node->Left);
	DeleteTree(tree, node->Right);
	delete node;
}