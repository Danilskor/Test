#include "HashTable.h"
#include "Lab4Output.h"

HashTable* CreateTable(int size)
{
	HashTable* hashTable = new HashTable;
	hashTable->Size = size;
	hashTable->Length = 0;	
	hashTable->Array = new List*[hashTable->Size];

	for (int i = 0; i < hashTable->Size; i++)
	{
		List* newList = new List;
		hashTable->Array[i] = newList;
		hashTable->Array[i]->Size = 0;
		hashTable->Array[i]->Head = nullptr;
	}
	return hashTable;
}

Node* CreateNewNode(string key, string value)
{
	Node* newNode = new Node;
	newNode->Key = key;
	newNode->Value = value;
	newNode->Next = nullptr;
	return newNode;
}

void InsertNode(HashTable* hashTable, Node* newNode, int newNodeListIndex)
{
	Node* currentNode = hashTable->Array[newNodeListIndex]->Head;

	while (currentNode != nullptr)
	{
		if (currentNode->Key == newNode->Key
			&& currentNode->Value == newNode->Value)
		{
			OverwriteErrorMessage();
			return;
		}
		currentNode = currentNode->Next;
	}

	if (hashTable->Array[newNodeListIndex]->Head == nullptr)
	{
		hashTable->Array[newNodeListIndex]->Head = newNode;
	}
	else
	{
		CollisionResolution(hashTable->Array[newNodeListIndex]->Head,
			newNode);
	}
	hashTable->Array[newNodeListIndex]->Size++;
	hashTable->Length++;
}
	
void DeleteNode(HashTable* hashTable, string key)
{
	int removeIndex = HashFunction(key, hashTable->Size);
	if (hashTable->Array[removeIndex]->Size != 0)
	{
		Node* deleteNode = hashTable->Array[removeIndex]->Head;
		int size = hashTable->Array[removeIndex]->Size;
		while (size >= 1)
		{
			for (int i = 0; i < size - 1; i++)
			{
				deleteNode = deleteNode->Next;
			}
			delete deleteNode;
			size--;
			hashTable->Array[removeIndex]->Size--;
		}
		hashTable->Array[removeIndex]->Size--;
		hashTable->Array[removeIndex]->Head = nullptr;
	}
}

string FindNode(HashTable* hashTable, string key, string value)
{
	int desiredNodeIndex = HashFunction(key, hashTable->Size);
	Node* currentNode = hashTable->Array[desiredNodeIndex]->Head;

	if (currentNode != nullptr)
	{
		while (currentNode->Key != key && currentNode->Value != value)
		{
			currentNode = currentNode->Next;
		}
	}
	else
	{
		return "ме мюидемн";
	}
	if (currentNode->Key == key && currentNode->Value == value)
	{
		return currentNode->Value;
	}
	else
	{
		return "ме мюидемн";
	}
}

int HashFunction(string key, int twoPrimeNumber)
{
	size_t size = key.length();
	int hash = 0;

	for (int i = 0; i < size; i++)
	{
		hash = (hash * (twoPrimeNumber - 1) + key[i]) % twoPrimeNumber;
	}
	return abs(hash);
}

void CollisionResolution(Node* chainBegin, Node* insertedNode)
{
	Node* current = chainBegin;

	while (current->Next != nullptr)
	{
		current = current->Next;
	}
	current->Next = insertedNode;
}

HashTable* Rehashing(HashTable* hashTable)
{
	int Size = hashTable->Size;
	int newSize = int(Size * GROWTH_FACTOR);
	if (newSize == Size)
	{
		newSize = Size++;
	}
	HashTable* newTable = CreateTable(newSize);
	Node* currentNode;
	newTable->Size = newSize;
	for (int i = 0; i < hashTable->Size; i++)
	{
		currentNode = hashTable->Array[i]->Head;

		while (currentNode != nullptr)
		{
			int index = HashFunction(currentNode->Key, newTable->Size);
			InsertNode(newTable, currentNode, index);
			hashTable->Array[i]->Head = currentNode->Next;
			currentNode->Next = nullptr;
			currentNode = hashTable->Array[i]->Head;
		}
	}

	for (int i = 0; i < hashTable->Size; i++)
	{
		delete hashTable->Array[i];
	}
	delete[] hashTable->Array;
	delete hashTable;
	return newTable;
}

void DeleteTable(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->Size; i++)
	{
		for (int j = 0; j < hashTable->Array[i]->Size; j++)
		{
			Node* removeNode = hashTable->Array[i]->Head;

			if (hashTable->Array[i]->Head->Next != nullptr)
			{
				hashTable->Array[i]->Head 
					= hashTable->Array[i]->Head->Next;
			}
			delete removeNode;
		}
		delete hashTable->Array[i];
	}
	delete[] hashTable->Array;
	delete hashTable;
}