#pragma once

#include <cstdlib>
#include <ctime>
#include "TreapNode.h"

using namespace std;

struct Treap
{
	TreapNode* Root;
};

Treap* CreateTreap();
TreapNode* CreateNode();
void Split(TreapNode *node, int value, TreapNode *&left, TreapNode *&right);
TreapNode* Merge(TreapNode *left, TreapNode *right);
TreapNode* DeleteNode(Treap* treap, int value);
TreapNode* DeleteNodeOptimize(Treap* treap, int value, TreapNode*& node);
TreapNode* Search(int value, TreapNode *toCheck);
void DeleteTreap(Treap *toDelete);
TreapNode* Add(Treap* treap, int value);
void OptimisedAdd(Treap* treap, TreapNode *&current, TreapNode *newNode);
