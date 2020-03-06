#pragma once

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct ArrayStucture
{
	int *Array;
	int Capacity;
	int Length;
};

void Menu(ArrayStucture * structureArray);
void Length(ArrayStucture * array);
void Capacity(ArrayStucture * array);
int ValidInput();
void FillArray(ArrayStucture * stuctureArray);
void ArrayOutput(ArrayStucture * structureArray);
int *ArrayCreation(ArrayStucture *strutureArray);
void DynamicArray(ArrayStucture *structureArray);
void InsertionElement(ArrayStucture * structureArray, int index); 
void DeletingElement(ArrayStucture * structureArray);
void BubbleSort(ArrayStucture * structureArray);
void InsertionSort(ArrayStucture * structureArray);
void ArraySort(ArrayStucture * structureArray);
void LineSearch(ArrayStucture * structureArray);
void BinarySearch(ArrayStucture * structureArray);

void MenuOutput();
void ValidInputText();
void ElementNumberText();
void SortText();
void SortErrorText();
void LineSearchValueText();
void LineSearchErrorText();
void ElementText();