#include "Stack.h"

Stack * CreateStack()
{
	Stack *stack = new Stack;
	stack->Capacity = 0;
	stack->Length = 0;
	stack->IsDeleted = false;
	stack->Array = new int[stack->Capacity];
	return stack;
}

void InitializationStack(Stack *stack, int value)
{
	stack->Capacity = value;
	stack->Array = new int[stack->Capacity];
}

void Push(Stack *stack, int value)
{	
if (stack->Length < stack->Capacity)
	{
		stack->Array[stack->Length] = value;
		stack->Length++;
	}
}

int Pop(Stack *stack)
{
	stack->Length--;
	return stack->Array[stack->Length];
}

void DeletingStack(Stack *stack)
{
	if (stack->IsDeleted == false)
	{
		stack->IsDeleted = true;
		delete[] stack;
	}
}