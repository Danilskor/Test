#pragma once

#include <iostream>
#include "..\Common\Input.h"

struct Stack
{
	int *Array;
	int Length = 0;
	int Capacity;

	bool IsDeleted = false;
};

Stack* CreateStack();
void DeletingStack(Stack*);
int Pop(Stack*);
void Push(Stack*, int);
void InitializationStack(Stack*, int);