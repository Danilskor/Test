#include "Lab3Main.h"

int Lab3Main()
{
	StackQueue* stackQueue = CreateStackQueue();
	Stack* stack = CreateStack();
	RingBuffer ringBuffer;
	RingBuffer ringBufferQueue;

	const int EXIT_MENU_VALUE = 0;
	while (true)
	{
		PrintStack(stack,"Stack: ");
		PrintBuffer(ringBuffer);
		PrintStackQueue(stackQueue);
		PrintBuffer(ringBufferQueue);
		PrintMainMenu(EXIT_MENU_VALUE);
		int menuValue = GetValue(0, 4);
		switch (menuValue)
		{
			case EXIT_MENU_VALUE:
			{
				DeletingStack(stack);
				PrintBuffer(ringBuffer);
				DeleteStackQueue(stackQueue);
				PrintBuffer(ringBufferQueue);
				return 0;
			}
			case 1:
			{
				system("cls");
				MenuStack(stack);
				break;
			}
			case 2:
			{
				system("cls");
				MenuCircleBuffer(&ringBuffer);
				break;
			}
			case 3:
			{
				system("cls");
				StackMenuQueue(stackQueue);
				break;
			}
			case 4:
			{
				system("cls");
				RingBufferMenuQueue(&ringBufferQueue);
				break;
			}
		}
	}
	return 0;
};

int MenuStack(Stack *stack)
{
	if (stack->IsDeleted)
	{
		stack = CreateStack();
	}
	if (stack->IsDeleted || stack->Length == 0)
	{
		PrintCreateStack();
		int value = GetValue(0, INT_MAX);
		InitializationStack(stack, value);
	}
	bool isContinueCycle = true;
	while (isContinueCycle)
	{
		const int EXIT_MENU_VALUE = 3;
		const int DELETE_STACK_VALUE = 0;
		PrintStack(stack, "Stack: ");
		PrintStackMenu(EXIT_MENU_VALUE,DELETE_STACK_VALUE);
		int stackMenuValue = GetValue(0, 3);

		switch (stackMenuValue)
		{
			case DELETE_STACK_VALUE:
			{
				system("cls");
				DeletingStack(stack);
				return 0;
			}
			case 1:
			{
				system("cls");
				PrintInput();
				Push(stack, GetValue(INT_MIN, INT_MAX));
				break;
			}
			case 2:
			{
				system("cls");
				if (stack->Length != 0)
				{
					PrintElement(Pop(stack));
				}
				break;
			}
			case EXIT_MENU_VALUE:
			{
				system("cls");
				return 0;
			}
		}
	}
	return 0;
};

int MenuCircleBuffer(RingBuffer *ringBuffer)
{
	if (ringBuffer->IsDeleted)
	{
		PrintCreateCircleBuffer();

		RingBufferCreation(ringBuffer);
	}
	bool isContinueCycle = true;
	while (isContinueCycle)
	{
		const int DELETE_BUFFER_VALUE = 0;
		const int EXIT_MENU_VALUE = 4;
		PrintBuffer(*ringBuffer);
		PrintCircleBufferMenu(DELETE_BUFFER_VALUE,EXIT_MENU_VALUE);
		int menuValue = GetValue(0, 4);

		switch (menuValue)
		{
			case DELETE_BUFFER_VALUE:
			{
				system("cls");
				RingBufferDeleting(ringBuffer);
				return 0;
			}
			case 1:
			{
				system("cls");
				PrintFreeSpase();
				cout << ringBuffer->FreeSpace << endl;
				PrintOccupedSpase();
				cout << ringBuffer->OccupiedSpace << endl;
				break;
			}
			case 2:
			{
				system("cls");
				PrintInput();
				RingBufferPut(ringBuffer, GetValue(INT_MIN, INT_MAX));
				break;
			}
			case 3:
			{
				system("cls");
				if (ringBuffer->OccupiedSpace != 0)
				{
					PrintElement(
						RingBufferGet(ringBuffer));
				} 
				break;
			}
			case EXIT_MENU_VALUE:
			{
				system("cls");
				return 0;
			}
		}
	}
	return 0;
};

int StackMenuQueue(StackQueue *stackQueue)
{
	if (stackQueue->InputStack->IsDeleted)
	{
		stackQueue->InputStack = CreateStack();
		stackQueue->OutputStack = CreateStack();
	}
	if (stackQueue->InputStack->IsDeleted || 
		(stackQueue->InputStack->Length == 0 && 
			stackQueue->OutputStack->Length == 0))
	{
		InitializtionStackQueue(stackQueue, START_CAPACITY);
	}

	bool isContinueCycle = true;
	while (isContinueCycle)
	{
		const int DELETE_QUEUE_VALUE = 0;
		const int EXIT_MENU_VALUE = 3;
		PrintStackQueue(stackQueue);
		PrintQueueMenu(DELETE_QUEUE_VALUE, EXIT_MENU_VALUE);
		int menuValue = GetValue(0, 3);

		switch (menuValue)
		{
			case DELETE_QUEUE_VALUE:
			{
				system("cls");
				DeleteStackQueue(stackQueue);
				return 0;
			}
			case 1:
			{
				system("cls");
				if (stackQueue->InputStack->Length > 0 || 
					stackQueue->OutputStack->Length > 0)
				{
					PrintElement(StackDequeue(stackQueue));
				}
				break;
			}
			case 2:
			{
				system("cls");
				PrintInput();
				StackEnqueue(stackQueue);
				break;
			}
			case EXIT_MENU_VALUE:
			{
				system("cls");
				return 0;
			}
		}
	}
	return 0;
};

int RingBufferMenuQueue(RingBuffer* ringBufferQueue)
{
	if (ringBufferQueue->IsDeleted)
	{
		PrintCreateCircleBuffer();

		RingBufferCreation(ringBufferQueue);
	}
	bool isContinueCycle = true;
	while (isContinueCycle)
	{
		const int DELETE_BUFFER_VALUE = 0;
		const int EXIT_MENU_VALUE = 4;
		PrintBuffer(*ringBufferQueue);
		PrintCircleBufferMenu(DELETE_BUFFER_VALUE, EXIT_MENU_VALUE);
		int menuValue = GetValue(0, 4);

		switch (menuValue)
		{
			case DELETE_BUFFER_VALUE:
			{
				system("cls");
				RingBufferDeleting(ringBufferQueue);
				return 0;
			}
			case 1:
			{
				system("cls");
				PrintFreeSpase();
				cout << ringBufferQueue->FreeSpace << endl;
				PrintOccupedSpase();
				cout << ringBufferQueue->OccupiedSpace << endl;
				break;
			}
			case 2:
			{
				system("cls");
				AddNewElement(ringBufferQueue);
				PrintInput();
				RingBufferPut(ringBufferQueue, GetValue(INT_MIN, INT_MAX));
				break;
			}
			case 3:
			{
				system("cls");
				if (ringBufferQueue->OccupiedSpace != 0)
				{
					PrintElement(
						RingBufferGet(ringBufferQueue));
				}
				break;
			}
			case EXIT_MENU_VALUE:
			{
				system("cls");
				return 0;
			}
		}
	}
	return 0;
};