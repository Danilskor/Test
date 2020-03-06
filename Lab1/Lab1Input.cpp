#include "ArrayHeader.h"

int ValidInput()
{
	int taxableIncome = 0;

	while(true) {
		if (cin >> taxableIncome) {
			break;
		}
		else {
			ValidInputText();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return taxableIncome;
};

int *ArrayCreation(ArrayStucture *strutureArray)
{
	int *Array = new int[strutureArray->Capacity];
	return Array;
};

void FillArray(ArrayStucture * structureArray)
{
	srand(time(0));
	for (int i = 0; i < structureArray->Length; i++)
	{
		structureArray->Array[i] = -100 + rand() % 201;
	}
}

void DynamicArray(ArrayStucture *structureArray)
{
	if (structureArray->Length > structureArray->Capacity)
	{
		structureArray->Capacity += 8;
		int *NewArray = new int[structureArray->Capacity];
		for (int i = 0; i < structureArray->Capacity - 8; i++)
		{
			NewArray[i] = structureArray->Array[i];
		}
		delete[] structureArray->Array;
		structureArray->Array = NewArray;
	}
};

//This menu should not be here
void Menu(ArrayStucture * structureArray)
{
	int index = 0;
	int number = 0;
	do
	{
		MenuOutput();
		
		number = ValidInput();
		switch (number)
		{
			case 1: {system("CLS");
				Length(structureArray);
				Capacity(structureArray);
				break; }
			case 2: {system("CLS");
				InsertionElement(structureArray, structureArray->Length);
				break; }
			case 3: { system("CLS"); 
				DeletingElement(structureArray);
				break; }
			case 4: {system("CLS");
				InsertionElement(structureArray, 0);
				break; }
			case 5: { system("CLS");
				InsertionElement(structureArray, structureArray->Length);
				break; }
			case 6: { system("CLS");
				ElementNumberText();
				do
				{
					cout << "Enter value from 0 to " << structureArray->Length << '\n';
					index = ValidInput();
				} while (index < 0 && index > structureArray->Length); 
				InsertionElement(structureArray, ValidInput() + 1);
				break; }
			case 7: {system("CLS");
				ArraySort(structureArray);
				break; }
			case 8: {system("CLS");
				LineSearch(structureArray);
				break; }
			case 9: {system("CLS");
				BubbleSort(structureArray);
				BinarySearch(structureArray);
				break; }
			default:
			{ 
			break; }
		}
		ArrayOutput(structureArray);
	} while (number != 0);
	
};

void InsertionElement(ArrayStucture * structureArray, int index)
{
	structureArray->Length++;
	DynamicArray(structureArray);
	for (int i = structureArray->Length; i > index; i--)
	{
		structureArray->Array[i] = structureArray->Array[i - 1];
	}
	ElementText();
	structureArray->Array[index] = ValidInput();
}

void DeletingElement(ArrayStucture * structureArray)
{
	int index = 0;
	if (structureArray->Length != 0)
	{
		ElementNumberText();
		index = ValidInput();
		for (int i = index; i < structureArray->Length - 2; i++)
		{
			structureArray->Array[i] = structureArray->Array[i + 1];
		}
		structureArray->Length--;
	}
	else {
		cout << "There is not elements in Array";
	}
};

void BubbleSort(ArrayStucture * structureArray)
{
	for (int i = 0; i < structureArray->Length - 1; i++)
		for (int j = 0; j < structureArray->Length - i - 1; j++)
		{
			if (structureArray->Array[j] > structureArray->Array[j + 1])
				swap(structureArray->Array[j], structureArray->Array[j + 1]);
		}
	for (int i = structureArray->Capacity; i < structureArray->Length; i++)
	{
		structureArray->Array[i - structureArray->Capacity] = 
			structureArray->Array[i];
		structureArray->Array[i] = 0;
	}
}
void InsertionSort(ArrayStucture * structureArray)
{
	int  temp;
	int j = 0;
	for (int i = 1; i < structureArray->Length; i++)
	{
		temp = structureArray->Array[i];
		j = i - 1;
		while (j >= 0 && structureArray->Array[j] > temp)
		{
			structureArray->Array[j + 1] = structureArray->Array[j];
			j = j - 1;
		}
		structureArray->Array[j + 1] = temp;
	}
	for (int i = structureArray->Capacity; i < structureArray->Length; i++)
	{
		structureArray->Array[i - structureArray->Capacity] =
			structureArray->Array[i];
		structureArray->Array[i] = 0;
	}
}

void ArraySort(ArrayStucture * structureArray)
{
	int number = 0;
	int check = -1;
	SortText();
	while (check == -1)
	{
		number = ValidInput();
		if (number == 1 || number == 2)
		{
			switch (number)
			{
			case 1: {BubbleSort(structureArray); break; }
			case 2: {InsertionSort(structureArray); break; }
			default:
				break;
			}
			check = 0;
		}
		else {
			SortErrorText();
		}
	}
}

void LineSearch(ArrayStucture * structureArray)
{
	int value = 0;
	bool check = false;
	ArrayOutput(structureArray);
	LineSearchValueText();
	value = ValidInput();
	for (int i = 0; i < structureArray->Length; i++)
	{
		if (structureArray->Array[i] == value)
		{
			cout << "Index = "<< i << '\n';
			check = true;
			break;
		}
	}
	if (check == false)
	{
		LineSearchErrorText();
	}
}

void BinarySearch(ArrayStucture * structureArray)
{
	ArrayOutput(structureArray);
	cout << "\n";
	cout << "What value you want to find?\n";
	int valueToSearch = ValidInput();
	int leftEnd = 0;
	int rightEnd = structureArray->Length;
	int middleOfArray;
	bool flag = false;
	while (flag == false && leftEnd <= rightEnd)
	{
		middleOfArray = (leftEnd + rightEnd) / 2;

		if (structureArray->Array[middleOfArray] == valueToSearch)
		{
			flag = true;
		}
		if (structureArray->Array[middleOfArray] > valueToSearch)
		{
			rightEnd = middleOfArray - 1;
		} else {
			leftEnd = middleOfArray + 1;
		}
	}
	if (flag)
	{
		cout << "\n";
		cout << "There is at least 1 element ";
		cout << valueToSearch;
		cout << " in array. Index = ";
		cout << middleOfArray;
	} else {
		cout << "\n" << "There is no " << valueToSearch;
		cout << " in current Array.";
	}
};