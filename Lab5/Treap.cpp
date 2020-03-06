#include "Treap.h"

Treap* CreateTreap()
{
	Treap *treap = new Treap;
	treap->Root = nullptr;
	return treap;
}

TreapNode* CreateNode()
{
	TreapNode* node = new TreapNode;
	node->Left = nullptr;
	node->Rigth = nullptr;
	return node;
}

void Split(TreapNode* node, int value, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = nullptr;
		right = nullptr;
	}
	else if (node->Value <= value)
	{
		Split(node->Rigth, value, node->Rigth, right);
		left = node;
	}
	else if (node->Value > value)
	{
		Split(node->Left, value, left, node->Left);
		right = node;
	}
}

TreapNode* Merge(TreapNode *left, TreapNode *right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->Rigth = Merge(left->Rigth, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

TreapNode* DeleteNode(Treap* treap, int value)
{
	TreapNode* left = CreateNode();
	TreapNode* right = CreateNode();
	TreapNode* midle = CreateNode();
	Split(treap->Root, value - 1, left, right);
	Split(right,value, midle, right);
	return treap->Root = Merge(left, right);
}

TreapNode* DeleteNodeOptimize(Treap* treap, int value, TreapNode*& node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (node->Value == value)
	{
		node = Merge(node->Left, node->Rigth);
		if (treap->Root != nullptr)
		{
			if (treap->Root->Value == value)
			{
				treap->Root = node;
			}
		}
		return treap->Root;
	}
	else
	{
		DeleteNodeOptimize(treap, value, value < node->Value
			? node->Left 
			: node->Rigth);
	}
}

TreapNode* Search(int value, TreapNode *toCheck)
{
	if (toCheck == nullptr)
	{
		return nullptr;
	}

	if (toCheck->Value == value)
	{
		return toCheck;
	}

	if (value > toCheck->Value)
	{
		Search(value, toCheck->Rigth);
	}
	else
	{
		Search(value, toCheck->Rigth);
	}
}

void DeleteTreap(Treap *toDelete)
{
	delete toDelete->Root;
	toDelete->Root = nullptr;
}

TreapNode* Add(Treap* treap, int value)
{
	TreapNode *newNode = CreateNode();
	newNode->Value = value;
	newNode->Priority = rand() % 100;
	TreapNode *left = nullptr;
	TreapNode *right = nullptr;
	Split(treap->Root, value, left, right);
	return treap->Root = Merge(Merge(left, newNode), right);
}

void OptimisedAdd(Treap* treap, TreapNode *&current, TreapNode *newNode)
{
	srand(time(nullptr));
	if (treap->Root == nullptr)
	{
		treap->Root = newNode;
		return;
	}
	if (current == nullptr)
	{
		current = newNode;
	}
	else if (newNode->Priority > current->Priority)
	{
		Split(current, newNode->Value, newNode->Left, newNode->Rigth);
		if (current == treap->Root)
		{
			treap->Root = newNode;
		}
		else
		{
			current = newNode;
		}
	}
	else
	{
		OptimisedAdd(treap, newNode->Value < current->Value
			? current->Left 
			: current->Rigth, newNode);
	}
}