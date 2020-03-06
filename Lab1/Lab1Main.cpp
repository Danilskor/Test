#include "ArrayHeader.h"
#include "Lab1Main.h"

int Lab1Main()
{
	ArrayStucture structureArray;
	structureArray.Capacity = 8;
	structureArray.Length = 8;
	structureArray.Array = ArrayCreation(&structureArray);

	FillArray(&structureArray);
	ArrayOutput(&structureArray);

	Menu(&structureArray);
	delete[] structureArray.Array;
	return 0;
}