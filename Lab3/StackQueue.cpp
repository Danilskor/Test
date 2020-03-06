#include "StackQueue.h"

StackQueue * CreateStackQueue()
{
	StackQueue *stackQueue = new StackQueue;
	stackQueue->InputStack = CreateStack();
	stackQueue->OutputStack = CreateStack();
	return stackQueue;
}

void InitializtionStackQueue(StackQueue *stackQueue, int value)
{
	InitializationStack(stackQueue->InputStack, value);
	InitializationStack(stackQueue->OutputStack, value);
	stackQueue->IsDeleted = false;
}

void RecreatingStackQueue(StackQueue *stackQueue)
{
	if (stackQueue->InputStack->Length == stackQueue->InputStack->Capacity 
		|| stackQueue->OutputStack->Length == 
		stackQueue->OutputStack->Capacity)
	{
		ShiftStack(stackQueue->InputStack, stackQueue->OutputStack);
		StackQueue *newStackQueue = new StackQueue;
		newStackQueue = CreateStackQueue();
		InitializtionStackQueue(newStackQueue, 
			stackQueue->InputStack->Capacity * 1.6);
		ShiftStack(newStackQueue->InputStack, stackQueue->InputStack);
		delete[] stackQueue->InputStack;
		delete[] stackQueue->OutputStack;
		stackQueue->InputStack = newStackQueue->OutputStack;
		stackQueue->OutputStack = newStackQueue->InputStack;
	}
}

void StackEnqueue(StackQueue *stackQueue)
{	
	RecreatingStackQueue(stackQueue);
	ShiftStack(stackQueue->InputStack, stackQueue->OutputStack);
	Push(stackQueue->InputStack, GetValue(INT_MIN, INT_MAX));
};

int StackDequeue(StackQueue *stackQueue)
{
	if (stackQueue->InputStack->Length != 0 || 
		stackQueue->OutputStack->Length != 0)
	{
		ShiftStack(stackQueue->OutputStack, stackQueue->InputStack);
		return Pop(stackQueue->OutputStack);
	}
};

void ShiftStack(Stack *stack1, Stack *stack2 )
{
	for (int i = 0; stack2->Length != 0; i++)
	{
		Push(stack1, Pop(stack2));
	}
};

void  DeleteStackQueue(StackQueue *stackQueue)
{
	if (!stackQueue->IsDeleted)
	{
		DeletingStack(stackQueue->InputStack);
		DeletingStack(stackQueue->OutputStack);
		stackQueue->IsDeleted = true;
	}
};