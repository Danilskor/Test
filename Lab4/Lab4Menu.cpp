#include "Lab4Menu.h"

int MenuHashTable(HashTable* hashTable)
{
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		PrintTable(hashTable);
		MenuHashTableText();
		int button = GetValue(0, 3);

		switch (button)
		{
			case ExitButton:
			{
				DeleteTable(hashTable);
				system("cls");
				return 0;
			}
			case 1:
			{
				int coefFullnes = (hashTable->Size * 4) / 3;
				if (hashTable->Length >= coefFullnes)
				{
					hashTable = Rehashing(hashTable);
				}
				PrintEnterKey();
				string key = InputString();
				PrintEnterValue();
				string value = InputString();
				Node* newNode = CreateNewNode(key, value);
				int newNodeIndex = HashFunction(key, hashTable->Size);
				system("cls");
				InsertNode(hashTable, newNode, newNodeIndex);
				break;
			}
			case 2:
			{
				PrintEnterKey();
				string key = InputString();
				system("cls");
				DeleteNode(hashTable, key);
				break;
			}
			case 3:
			{
				PrintEnterKey();
				string key = InputString();
				PrintEnterValue();
				string value = InputString();
				system("cls");
				if (hashTable->Length != 0)
				{
					PrintEnterKey();
					if (FindNode(hashTable, key, value) == "ме мюидемн")
					{
						FindErrorMessage();
					}
					else
					{
						PrintHashTableSearchingElement(key, value);
					}
				}
				break;
			}
		}
	}
}

int MenuDictionary(Dictionary* dictionary)
{
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{

		PrintDictonary(dictionary);
		MenuDictionaryText();
		int button = GetValue(0, 3);

		switch (button)
		{
			case ExitButton:
			{
				DeleteDictionary(dictionary);
				system("cls");
				return 0;
			}
			case 1:
			{
				int coefFullnes = (dictionary->Table->Size * 4) / 3;
				if (dictionary->Table->Length >= coefFullnes)
				{
					dictionary->Table = Rehashing(dictionary->Table);
				}
				PrintEnterKey();
				string key = InputString();
				PrintEnterValue();
				string value = InputString();
				Node* newNode = CreateNewNode(key, value);
				system("cls");
				InsertEntry(dictionary, newNode, key);
				break;
			}
			case 2:
			{
				PrintEnterKey();
				string key = InputString();
				system("cls");
				DeleteEntry(dictionary, key);
				break;
			}
			case 3:
			{
				system("cls");
				if (dictionary->Table->Length != 0)
				{
					PrintEnterKey();
					string key = InputString();
					if (FindEntry(dictionary, key) == "ме мюидемн")
					{
						FindErrorMessage();
					}
					else
					{
						PrintDictionarySearchingElement(key);
					}
				}
				break;
			}
		}
	}
}