#include "Lab3Output.h"

void PrintMainMenu(int exitMenuValue)
{
	cout << "________________Menu_________________\n";
	cout << "1. Меню стека\n";
	cout << "2. Меню циклического буфера\n";
	cout << "3. Меню очереди из стеков\n";
	cout << "4. Меню очереди из циклического буфера\n";
	cout << exitMenuValue <<". Выход из программы\n";
	cout << "_____________________________________\n";
};

void PrintStackMenu(int exitMenuValue, int deleteMenuValue)
{
	cout << "__________________Menu___________________\n";
	cout << deleteMenuValue <<". Выход в главное меню и удаление стека\n";
	cout << "1. Push\n";
	cout << "2. Pop\n";
	cout << exitMenuValue <<". Выход в главное меню без удаления стека\n";
	cout << "_________________________________________\n";
};

void PrintStack(Stack *stack, string outputText)
{
	if (!stack->IsDeleted && stack->Length !=0)
	{	
		cout << outputText;
		for (int i = 0; i < stack->Length; i++)
		{

			cout << stack->Array[i] << ' ';
		}
		cout << endl;
	}
};

void PrintElement(int withdrawalElementValue)
{
	cout << ">>" << withdrawalElementValue << endl;
};

void PrintInput()
{
	cout << "Введите значение\n>";
};

void PrintFreeSpase()
{
	cout << "Свободного места:\n";
};

void PrintOccupedSpase()
{
	cout << "Занятого места:\n";
};

void PrintCircleBufferMenu( int deleteMenuValue, int exitMenuValue)
{
	cout << "_________________________Menu__________________________\n";
	cout << deleteMenuValue << 
		". Выход в главное меню и удаление циклического буфера\n";
	cout << "1. Вывод свободного и заполненого места\n";
	cout << "2. Добавление элемента в буфер\n";
	cout << "3. Извлечение элемента из буфера\n";
	cout << exitMenuValue <<
		". Выход в главное меню без удаления циклического буфера\n";
	cout << "_______________________________________________________\n";
};

void PrintQueueMenu(int deleteMenuValue, int exitMenuValue)
{
	cout << "_________________________Menu__________________________\n";
	cout << deleteMenuValue <<
		". Выход в главное меню и удаление очереди \n";
	cout << "1. Извлечение элемента из очереди\n";
	cout << "2. Добавление элемента в очередь\n";
	cout << exitMenuValue <<
		". Выход в главное меню без удаления очереди\n";
	cout << "_______________________________________________________\n";
};

void PrintStackQueue(StackQueue *stackQueue)
{
	if (!stackQueue->IsDeleted)
	{
		ShiftStack(stackQueue->OutputStack, stackQueue->InputStack);
		PrintStack(stackQueue->OutputStack, "Очередь на стэках: ");
	}
};

void PrintCreateCircleBuffer()
{
	cout << "Введите размер буфера: ";
};

void PrintCreateStack()
{
	cout << "Введите размер стэка: ";
};

void PrintBuffer(RingBuffer ringBuffer)
{
	if (!ringBuffer.IsDeleted && ringBuffer.OccupiedSpace != 0)
	{
		cout << "Circle buffer: ";
		BufferNode *nodeToPrint = ringBuffer.Head;
		for (int i = 0; i < ringBuffer.BufferSize; i++)
		{
			if (nodeToPrint->Full)
			{
				cout << ' ' << nodeToPrint->Data << ' ';
			}
			nodeToPrint = nodeToPrint->NextBufferNode;
		}
		cout << endl;
	}
};