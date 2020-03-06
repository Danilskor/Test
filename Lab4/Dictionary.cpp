#include "Dictionary.h"
#include "Lab4Output.h"

Dictionary* CreateDictionary()
{
	Dictionary* dictionary = new Dictionary;
	dictionary->Table = CreateTable(START_DICTIONARY_SIZE);
	return dictionary;
}

string FindEntry(Dictionary* dictionary, string key)
{
	if (dictionary->Table->Length != 0)
	{
		int searchNodeIndex = HashFunction(key, dictionary->Table->Size);
		Node* currentNode = dictionary->Table->Array[searchNodeIndex]->Head;
		if (currentNode != nullptr)
		{
			while (currentNode->Key != key)
			{
				currentNode = currentNode->Next;
			}
		}
		else
		{
			return "ме мюидемн";
		}
		if (currentNode->Key == key)
		{
			return currentNode->Value;
		}
		else
		{
			return "ме мюидемн";
		}
	}
}

bool InsertEntry(Dictionary* dictionary, Node* insertedNode, string key)
{
	int newNodeListIndex = HashFunction(key, dictionary->Table->Size);
	Node* current = dictionary->Table->Array[newNodeListIndex]->Head;

	while (current != nullptr)
	{
		if (current->Key == insertedNode->Key)
		{
			InsertErrorMessage();
			return false;
		}
		current = current->Next;
	}
	InsertNode(dictionary->Table, insertedNode, newNodeListIndex);
	return true;
}

void DeleteEntry(Dictionary* dictionary, string key)
{
	DeleteNode(dictionary->Table, key);
}

void DeleteDictionary(Dictionary* dictionary)
{
	DeleteTable(dictionary->Table);
	delete dictionary;
}