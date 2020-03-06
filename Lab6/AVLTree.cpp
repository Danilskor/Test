#include "AVLtree.h"

AVLTree* InitialisationTree()
{
	AVLTree* tree = new AVLTree;
	tree->Root = nullptr;
	return tree;
}

Node* RotationRightSmall(Node* node)
{
	Node* left = node->Left;
	node->Left = left->Right;
	left->Left = node;
	FixHeight(node);
	FixHeight(left);
	return left;
}

Node* RotationLeftSmall(Node* node)
{
	Node* right = node->Right;
	node->Right = right->Left;
	right->Left = node;
	FixHeight(node);
	FixHeight(right);
	return right;
}

Node* Rotation(Node* node, AVLTree* tree)
{
	tree->NumberOfRotation++;
	FixHeight(node);
	if (BalanceFactor(node) == 2)
	{
		if (BalanceFactor(node->Right) < 0)
		{
			node->Right = RotationRightSmall(node->Right);
		}
		return RotationLeftSmall(node);
	}
	if (BalanceFactor(node) == -2)
	{
		if (BalanceFactor(node->Left) > 0)
		{
			node->Left = RotationLeftSmall(node->Left);
		}
		return RotationRightSmall(node);
	}
	return node;
}

Node* Insert(Node*& node, int value, AVLTree* tree) 
{
	if (node == nullptr)
	{
		node = new Node;
		node->Data = value;
		node->Height = 1;
		node->Left = nullptr;
		node->Right = nullptr;
		tree->NumberOfRotation = 0;
		return node;
	}
	if (value < node->Data)
	{
		node->Left = Insert(node->Left, value, tree);
	}	
	else
	{
		node->Right = Insert(node->Right, value, tree);
	}
	return Rotation(node, tree);
}

Node* FindMin(Node* node)
{
	return node->Left != nullptr
		? FindMin(node)
		: node;
}

Node* RemoveMin(Node* node, AVLTree* tree)
{
	if (node->Left == nullptr)
	{
		return node->Right;
	}
	node->Left = RemoveMin(node->Left, tree);
	return Rotation(node, tree);
}

Node* DeleteNode(int value, Node* node, AVLTree* tree)
{
	Node *tempAVLNode;
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (value < node->Data)
	{
		node->Left = DeleteNode(value, node->Left, tree);
	}
	else if (value > node->Data)
	{
		node->Right = DeleteNode(value, node->Right, tree);
	}
	else if (node->Left && node->Right)
	{
		tempAVLNode = FindMin(node->Right);
		node->Data = tempAVLNode->Data;
		node->Right = DeleteNode(node->Data, node->Right, tree);
	}
	else
	{
		tempAVLNode = node;
		if (node->Left == nullptr)
		{
			node = node->Right;
		}
		else if (node->Right == nullptr)
		{
			node = node->Left;
		}
		delete tempAVLNode;
	}
	if (node == nullptr)
	{
		return node;
	}
	Rotation(node, tree);
	return node;
}

Node* FindNode(Node* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Data == value)
	{
		return node;
	}
	if (node->Data > value)
	{
		FindNode(node->Left, value);
	}
	else
	{
		FindNode(node->Right, value);
	}
}

void DeleteAVLTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
		DeleteAVLTree(node->Left);
		DeleteAVLTree(node->Right);
		delete node;
}