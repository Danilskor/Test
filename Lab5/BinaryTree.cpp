#include "BinaryTree.h"

BinaryTree* CreateBinaryTree()
{
	BinaryTree* binaryTree = new BinaryTree;
	binaryTree->Root = nullptr;
	return binaryTree;
}

BinaryTreeNode* CreateNode(BinaryTreeNode* node)
{
	node = new BinaryTreeNode;
	node->Left = nullptr;
	node->Rigth = nullptr;
	return node;
}

void Insert(BinaryTreeNode* node, BinaryTree* tree, int value)
{
	if (node == nullptr)
	{
		node = CreateNode(node);
		node->Data = value;
		if (tree->Root == nullptr)
		{
			tree->Root = node;
			tree->Root->Parent = nullptr;
		}
		return;
	}
	if (node->Data > value)
	{
		if (node->Left == nullptr)
		{
			node->Left = CreateNode(node->Left);
			node->Left->Data = value;
			node->Left->Parent = node;
		}
		else
		{
			Insert(node->Left, tree, value);
		}
	}
	else
	{
		if (node->Rigth == nullptr)
		{
			node->Rigth = CreateNode(node->Rigth);
			node->Rigth->Data = value;
			node->Rigth->Parent = node;
		}
		else
		{
			Insert(node->Rigth, tree, value);
		}
		
	}
}


BinaryTreeNode* FindMinMax(BinaryTreeNode* node, const char minMax[3])
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (!strcmp(minMax, "min"))
	{
		while (node->Left != nullptr)
		{
			node = node->Left;
		}
	}
	if (!strcmp(minMax, "max"))
	{
		while (node->Rigth != nullptr)
		{
			node = node->Rigth;
		}
	}
	return node;
}

BinaryTreeNode* FindElement(BinaryTreeNode* node, int value)
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
		return FindElement(node->Left, value);
	}
	else
	{
		return FindElement(node->Rigth, value);
	}
}

void DeleteNode(BinaryTree* tree, int value)
{
	BinaryTreeNode* deleteNode = tree->Root;
	deleteNode = FindElement(tree->Root, value);
	if (deleteNode->Left == nullptr && deleteNode->Rigth == nullptr)
	{
		ChooseDeleteNode(deleteNode, tree);
	}
	if (deleteNode->Left != nullptr)
	{
		deleteNode->Data = deleteNode->Left->Data;
		deleteNode = FindMinMax(deleteNode, "min");
		ChooseDeleteNode(deleteNode, tree);
	}
	else
	{
		deleteNode->Data = deleteNode->Rigth->Data;
		deleteNode = FindMinMax(deleteNode->Rigth, "min");
		ChooseDeleteNode(deleteNode, tree);
	}
}

void ChooseDeleteNode(BinaryTreeNode* deleteNode, BinaryTree* tree)
{
	if (deleteNode = tree->Root)
	{
		delete deleteNode;	
	}
	else if (deleteNode->Parent->Left == deleteNode)
	{
		deleteNode->Parent->Left = nullptr;
		delete deleteNode;
	}
	else
	{
		deleteNode->Parent->Rigth = nullptr;
		delete deleteNode;
	}
}

void DeleteTree(BinaryTreeNode* node)
{
	if (node != nullptr)
	{
		std::queue<BinaryTreeNode*> queue;
		std::queue<BinaryTreeNode*> deleteQueue;

		queue.push(node);
		deleteQueue.push(node);
		while (!queue.empty())
		{
			BinaryTreeNode*& queueNode = queue.front();
			queue.pop();
			if (queueNode->Left != nullptr)
			{
				queue.push(queueNode->Left);
				deleteQueue.push(node);
			}
			if (queueNode->Rigth != nullptr)
			{
				queue.push(queueNode->Rigth);
				deleteQueue.push(node);
			}
		}
		while (deleteQueue.empty())
		{
			BinaryTreeNode*& deleteNode = deleteQueue.front();
			deleteQueue.pop();
			delete deleteNode;
		}
	}
}

BinaryTreeNode* DeleteNode(BinaryTree* tree, int data, BinaryTreeNode *&toDelete)
{
	if (toDelete == nullptr)
	{
		return toDelete;
	}
	if (data < toDelete->Data)
	{
		toDelete->Left = DeleteNode(tree, data, toDelete->Left);
	}
	else if (data > toDelete->Data)
	{
		toDelete->Rigth = DeleteNode(tree, data, toDelete->Rigth);
	}
	else
	{
		if (toDelete->Left == nullptr)
		{
			BinaryTreeNode *toReplace = toDelete->Rigth;
			if (toDelete == tree->Root)
			{
				tree->Root = toReplace;
				return tree->Root;
			}
			delete toDelete;
			return toReplace;
		}
		else if (toDelete->Rigth == nullptr)
		{
			BinaryTreeNode *toReplace = toDelete->Left;
			if (toDelete == tree->Root)
			{
				tree->Root = toReplace;
				return tree->Root;
			}
			delete toDelete;
			return toReplace;
		}
		BinaryTreeNode *toReplace = FindMinMax(toDelete->Rigth, "min");
		toDelete->Data = toReplace->Data;
		toDelete->Rigth = DeleteNode(tree, toReplace->Data, toDelete->Rigth);
	}
	return toDelete;
}