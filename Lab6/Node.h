#pragma once

struct Node
{
	int Data;
	int Height;
	Node* Left;
	Node* Right;
};

void FixHeight(Node*);
int BalanceFactor(Node*);