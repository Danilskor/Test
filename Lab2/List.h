#pragma once

#include <string>
#include <iostream>
#include "..\Common\Input.h"

using namespace std;

struct Node
{
	int Data;
	Node *Next;
	Node *Prev;
};

struct List
{
	Node *Head;
	Node *Tail;
	size_t Size;
};

const int maxValue = 100;

List* CreateList();
void PrintList(List*);
void AddNode(List*);
Node* ListIterator(List*, size_t);
void DeleteNode(List*, size_t);
void InsertNode(List*, size_t, int);
void BubbleSort(List*);
int LinearSearch(List*, int);
void DeleteList(List*);
//int GetValue(int, int);
void PrintMenu();
struct Node * Swap(Node*, Node*, Node*, List*);
void BubbleSort(List*);
int RandomData(int, int);



