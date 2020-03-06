#pragma once

#include <iostream>
#include "Node.h"

struct AVLTree
{
	int NumberOfRotation;
	Node* Root;
};

AVLTree* InitialisationTree();
Node* RotationRightSmall(Node*);
Node* RotationLeftSmall(Node*);
Node* Rotation(Node*, AVLTree* tree);
Node* Insert(Node*&, int, AVLTree* tree);
Node* FindMin(Node*);
Node* RemoveMin(Node*, AVLTree* tree);
Node* DeleteNode(int, Node*, AVLTree* tree);
Node* FindNode(Node*, int);
void DeleteAVLTree(Node*);