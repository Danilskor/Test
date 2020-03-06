#pragma once

#include <iostream>
#include "Stack.h"
#include "..\Common\Input.h"

using namespace std;

struct StackQueue
{
	Stack *InputStack;
	Stack *OutputStack;
	bool IsDeleted = false;
};

const int START_CAPACITY = 8;

StackQueue * CreateStackQueue();
void InitializtionStackQueue(StackQueue*, int);
void StackEnqueue(StackQueue*);
int StackDequeue(StackQueue*);
void ShiftStack(Stack*, Stack*);
void DeleteStackQueue(StackQueue*);
void RecreatingStackQueue(StackQueue*);