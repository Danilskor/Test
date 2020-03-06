#include "Lab4Output.h"

void MainMenuText()
{
	cout << " _________________MENU_______________\n";
	cout << " 0. Выход из программы\n";
	cout << " 1. Хеш-таблица\n";
	cout << " 2. Словарь\n";
	cout << " ___________________________________\n";
	cout << endl;
}

void MenuHashTableText()
{
	cout << " ______________________MENU____________________\n";
	cout << " 0. Выход из меню\n";
	cout << " 1. Добавить запись в таблицу\n";
	cout << " 2. Удалить запись из таблицы\n";
	cout << " 3. Найди запись по ключу\n";
	cout << " _____________________________________________\n";
	cout << endl;
}



void MenuDictionaryText()
{
	cout << " ______________________MENU____________________\n";
	cout << " 0. Выход из меню\n";
	cout << " 1. Добавить запись в словарь\n";
	cout << " 2. Удалить запись из словаря\n";
	cout << " 3. Найди запись по ключу\n";
	cout << " _____________________________________________\n";
	cout << endl;
}



void PrintTable(HashTable* hashTable)
{
	if (hashTable->Length != 0)
	{
		Node* currentNode;
		cout << "            HASHTABLE\n\n";

		for (int i = 0; i < hashTable->Size; i++)
		{
			currentNode = hashTable->Array[i]->Head;

			if (currentNode != nullptr)
			{
				PrintNode(currentNode);
				currentNode = currentNode->Next;

				while (currentNode != nullptr)
				{
					cout << ">>>>";
					PrintNode(currentNode);
					currentNode = currentNode->Next;
				}
			}
			else
			{
				cout << "Key:     Value:\n";
			}
		}
		cout << endl;
	}
}

void PrintHashTableSearchingElement(string key, string value)
{
	cout << "Запись найдена\nКлюч - " << key << " Значение - " <<
		value << endl;
}

void PrintDictonary(Dictionary* dictonary)
{
	if (dictonary->Table->Length != 0)
	{
		cout << "            Dictonary\n\n";
		Node* currentNode;
		for (int i = 0; i < dictonary->Table->Size; i++)
		{
			currentNode = dictonary->Table->Array[i]->Head;
			while (currentNode != nullptr)
			{
				PrintNode(currentNode);
				currentNode = currentNode->Next;
			}
	
		}
	}
}

void PrintDictionarySearchingElement(string key)
{
	cout << "По данному ключу найдено значение: " << 
		key<< endl;
}

void PrintEnterKey()
{
	cout << "Введите ключ\n>> ";
}

void PrintEnterValue()
{
	cout << "Введите значение\n>> ";
}

//TODO: 
void PrintNode(Node* node)
{
	cout << "Key: " << node->Key << '\t'
		<< "    Value: " << node->Value << endl;
}

void InsertErrorMessage()
{
	cout << "Элемент с таким ключем уже существует!\n";
}

void DeleteErrorMessage()
{
	cout <<"Такого элемента не существует!\n";
}

void OverwriteErrorMessage()
{
	cout << "Такой элемент уже существует!\n";
}

void FindErrorMessage()
{
	cout << "Не найдено!!\n";
}