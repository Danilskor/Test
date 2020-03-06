#include "CircleBuffer.h"
#include "Lab3Output.h"

CircleBuffer * CreateCircleBuffer()
{
	CircleBuffer *circleBuffer = new CircleBuffer;
	circleBuffer->isDeleted = false;
	circleBuffer->Capacity = 0;
	return circleBuffer;
};

void InitializationBuffer(CircleBuffer * circleBuffer)
{
	circleBuffer->InIndex = 0;
	circleBuffer->OutIndex = 0;

	PrintCreateCircleBuffer();

	circleBuffer->Capacity = GetValue(INT_MIN, INT_MAX);
	circleBuffer->Array = new int[circleBuffer->Capacity];
	circleBuffer->isFull = new bool[circleBuffer->Capacity];
	for (int i = 0; i < circleBuffer->Capacity; i++)
	{
		circleBuffer->isFull[i] = false;
	}
	circleBuffer->isDeleted = false;
}

int FreeSpace(CircleBuffer *circlebuffer)
{
	return circlebuffer->Capacity - circlebuffer->Length;
}

int FilledSpce(CircleBuffer *circlebuffer)
{
	return circlebuffer->Length;
}

void AddingElmentCircleBuffer(CircleBuffer *circlebuffer)
{
	if (circlebuffer->Capacity != 0)
	{
		circlebuffer->Array[circlebuffer->InIndex] = GetValue(INT_MIN, INT_MAX);
		if (circlebuffer->isFull[circlebuffer->InIndex])
		{
			circlebuffer->OutIndex++;
			circlebuffer->OutIndex = circlebuffer->OutIndex % circlebuffer->Capacity;
		}
		circlebuffer->isFull[circlebuffer->InIndex] = true;
		circlebuffer->InIndex++;
		circlebuffer->InIndex = circlebuffer->InIndex % circlebuffer->Capacity;
		if (circlebuffer->Length < circlebuffer->Capacity)
		{
			circlebuffer->Length++;
		}
	}
}

int GetCircleBuffer(CircleBuffer *circlebuffer)
{
	int temporaryIndex = circlebuffer->OutIndex;
	circlebuffer->isFull[circlebuffer->OutIndex] = false;
	circlebuffer->OutIndex++;
	circlebuffer->OutIndex = circlebuffer->OutIndex % circlebuffer->Capacity;
	if (circlebuffer->Length >= 0)
	{
	circlebuffer->Length--;
	}
	return circlebuffer->Array[temporaryIndex];
}

void DeletingCircleBuffer(CircleBuffer *circleBuffer)
{
	if (circleBuffer->isDeleted == false)
	{
		circleBuffer->isDeleted = true;
		delete[] circleBuffer;
	}
}