#pragma once

#include <iostream>
#include <string>
#include "BinaryTreeNode.h"
#include "Treap.h"

using namespace std;

void TreePrinting(string, BinaryTreeNode*, bool);
void TreePrinting(BinaryTreeNode*);
void TreapPrinting(TreapNode *node);
void TreapPrinting(string prefix, TreapNode *node, bool isLeft);
void PrintMainMenuLab5();
void PrintTreeMenu();
void PrintTreapMenu();
void EnterValueMessage();
void SearchMessage(BinaryTreeNode*);
void SearchMessage(TreapNode*);