#pragma once

#include "List.h"

struct HashTable
{
	int	Length;
	int Size;
	List** Array;
};

const int MIN_HASHTABLE_SIZE = 2;
const double GROWTH_FACTOR = 1.5;

HashTable* CreateTable(int size);
Node* CreateNewNode(string key, string value);
void InsertNode(HashTable*, Node* insrtedNode, int);
void DeleteNode(HashTable*, string key);
string FindNode(HashTable*, string key, string value);
int HashFunction(string, int);
void CollisionResolution(Node* chainBegin, Node* insertedNode);
HashTable* Rehashing(HashTable*);
void DeleteTable(HashTable*);