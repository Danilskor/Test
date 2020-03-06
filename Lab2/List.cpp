#include "List.h"
#include <ctime>

bool CheckingForInteger(string);


List* CreateList()
{
	int nodeCount = 6;
	int randomValue = 0;
	List *list = new List;
	list->Head = new Node;
	list->Tail = new Node;
	list->Size = 2;
	
	list->Head->Next = list->Tail;
	list->Head->Prev = nullptr;

	list->Tail->Next = nullptr;
	list->Tail->Prev = list->Head;

	cout << "Введите первое значения списка [" << -maxValue <<';' << maxValue << "]\n";
	list->Head->Data = GetValue(-maxValue, maxValue);
	cout << "Введите второе значения списка [" << -maxValue << ';' << maxValue << "]\n";
	list->Tail->Data = GetValue(-maxValue, maxValue);

	cout << "Заполнить рандомно последующие " << nodeCount << " ячеек?\n";
	cout << "1-ДА\n0-Нет\n";
	randomValue = GetValue(0, 1);
	if (randomValue == 1)
	{
		for (int i = 0; i < nodeCount; ++i)
		{
			AddNode(list);
		}
	}
	return list;
}

void PrintList(List *list)
{
	Node *currentNode = list->Head;
	while (currentNode != nullptr)
	{
		cout << currentNode->Data << '\t';
		currentNode = currentNode->Next;
	}
	cout << endl;
}

void AddNode(List *list)
{
	if (list->Tail->Next == nullptr)
	{
		Node *newNode = new Node;
		list->Tail->Next = newNode;
		newNode->Next = nullptr;
		newNode->Prev = list->Tail;

		newNode->Data = RandomData(-maxValue, maxValue);

		list->Tail = newNode;
		list->Size++;
	}
}

Node* ListIterator(List *list, size_t nodeIndex)
{
	
	Node *currentNode = list->Head;
	if (nodeIndex < list->Size / 2)
	{
		size_t index = 0;
		currentNode = list->Head;
		while (index != nodeIndex && currentNode != nullptr
			&& currentNode->Next != nullptr)
		{
			currentNode = currentNode->Next;
			index++;
		}
	}
	else
	{
		size_t index = list->Size - 1;
		currentNode = list->Tail;
		while (index != nodeIndex && currentNode != nullptr
			&& currentNode->Prev != nullptr)
		{
			currentNode = currentNode->Prev;
			index--;
		}
	}
	return currentNode;
}

void DeleteNode(List *list, size_t indexNode)
{
	clock_t begin = clock();
	Node *currentNode = ListIterator(list, indexNode);

	if (currentNode == list->Head)
	{
		list->Head = currentNode->Next;
		list->Head->Prev = nullptr;
	}
	else if (currentNode == list->Tail)
	{
		list->Tail = currentNode->Prev;
		list->Tail->Next = nullptr;
	}
	else
	{
		currentNode->Prev->Next = currentNode->Next;
		currentNode->Next->Prev = currentNode->Prev;
	}
	list->Size--;
	delete currentNode;
	clock_t end = clock();
	cout << endl << "Time: " << double(end - begin) / CLOCKS_PER_SEC
		<< endl;
	system("pause");
}

void InsertNode(List *list, size_t nodeIndex, int value)
{
	list->Size++;
	Node *newNode = new Node;
	newNode->Data = value;
	if (nodeIndex == list->Size - 1)
	{
		newNode->Next = nullptr;
		newNode->Prev = list->Tail;		
		list->Tail->Next = newNode;
		list->Tail = newNode;
	} 
	else 
	{
		Node *currentNode = ListIterator(list, nodeIndex);
		newNode->Next = currentNode;
		if (currentNode == list->Head)
		{
			newNode->Prev = nullptr;
			list->Head->Prev = newNode;
			list->Head = newNode;
		} 
		else 
		{
			currentNode->Prev->Next = newNode;
			newNode->Prev = currentNode->Prev;
			currentNode->Prev = newNode;
		}
	}
}


int LinearSearch(List *list, int searchElement)
{
	Node *currentNode = list->Head;
	PrintList(list);
	while (currentNode != nullptr)
	{
		if (currentNode->Data == searchElement)
		{
			cout << "Да\t";
		}
		else
		{
			cout << "Нет\t";
		}
		currentNode = currentNode->Next;
	}
	return 0;
}

void DeleteList(List *list)
{
	
	Node *currentNode = list->Head;
	while (currentNode->Next != nullptr)
	{
		currentNode = currentNode->Next;
		delete list->Head->Prev;
	}
	delete list->Tail;
	delete list;
}


void PrintMenu()
{
	cout << "____________________MENU___________________\n";
	cout << "|1 Добавление элемента                    |\n";
	cout << "|2 Удаление элемента                      |\n";
	cout << "|3 Вставка элемента в начало              |\n";
	cout << "|4 Вставка элемента в конец               |\n";
	cout << "|5 Вставка после определенного элемента   |\n";
	cout << "|6 Вставка перед определенным элементом   |\n";
	cout << "|7 Сортировка                             |\n";
	cout << "|8 Линеный поиск элемента                 |\n";
	cout << "|0 Выход из программы                     |\n";
	cout << "|_________________________________________|\n";
}

void BubbleSort(struct List *list)
{
	Node *currentNode = list->Head;
	while (currentNode->Next)
	{
		if ((currentNode->Data) > (currentNode->Next->Data))
		{
			int temp = currentNode->Next->Data;
			currentNode->Next->Data = currentNode->Data;
			currentNode->Data = temp;

			currentNode = currentNode->Next;
			BubbleSort(list);
		}
		else 
		{ 
			currentNode = currentNode->Next; 
		}
	}
}

int RandomData(int min, int max)
{
	return rand() % (2 * max) + min - 1;
}

/*bool CheckingForInteger(string value)
{
	int size = value.length();
	if (isdigit(value[0]) || value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit(value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int GetValue(int min, int max)
{
	string inputValue;
	int outputValue;
	while (true)
	{
		getline(cin, inputValue);
		if (CheckingForInteger(inputValue) == false || stoi(inputValue) < min || stoi(inputValue) > max)
		{
			cout << endl <<"Ошибка!: попробуйте еще раз: ";
			inputValue.clear();
		}
		else
		{
			outputValue = stoi(inputValue);
			return outputValue;
		}
	}
}*/
