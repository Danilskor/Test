#include "ArrayHeader.h"

void MenuOutput()
{
	cout << "_____________________________Menu_____________________________\n";
	cout << "|To find out length and capacity of array press 1             |\n";
	cout << "|To add new element press 2                                   |\n";
	cout << "|To delete element press 3                                    |\n";
	cout << "|To insert element to left end press 4                        |\n";
	cout << "|To insert element to rigtht end press 5                      |\n";
	cout << "|To past after a sertain element press 6                      |\n";
	cout << "|To sort array press 7                                        |\n";
	cout << "|To liner search press 8                                      |\n";
	cout << "|To buinary search press 9                                    |\n";
	cout << "|To end session press 0                                       |\n";
	cout << "|_____________________________________________________________|\n";
	cout << "                   Enter numeral from 0 to 9\n\n";
};

void Length(ArrayStucture * Array)
{
	cout << "Array Length " << Array->Length << '\n';
};

void Capacity(ArrayStucture * Array)
{
	cout << "Array Capacity " << Array->Capacity << '\n';
};

void ArrayOutput(ArrayStucture * StructureArray)
{
	cout << "\n\nArray: ";
	for (int i = 0; i < StructureArray->Length; i++)
	{
		cout << StructureArray->Array[i] << ' ';
	}
	cout << "\n\n";
};

void ValidInputText()
{
	cout << "Please enter a valid integer" << '\n';
};
void ElementText()
{
	cout << "Enter Value ";
};

void ElementNumberText()
{
	cout << "Enter element number\n";
}; 

void SortText()
{
	cout << "Enter 1 to buble sort\nEnter 2 to Insertion sort\n";
};

void SortErrorText()
{
	cout << "Hey, only 1 or 2!!\n";
};

void LineSearchValueText()
{
	cout << "Enter the value you want to find \n";
};
void LineSearchErrorText()
{
	cout << "Searched value not found!";
};

