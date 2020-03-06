#include "RingBuffer.h"

void BufferInitialisation(RingBuffer *ringBuffer)
{
	BufferNode *rootNode = new BufferNode;
	ringBuffer->Head = rootNode;
	ringBuffer->Head->NextBufferNode = ringBuffer->Head;
	ringBuffer->IndexIn = ringBuffer->Head;
	ringBuffer->IndexOut = ringBuffer->Head;
}

void RingBufferCreation(RingBuffer *ringBuffer)
{
	int userBufferSize;
	ringBuffer->IsDeleted = false;
	BufferInitialisation(ringBuffer);
	do
	{
		userBufferSize = GetValue(1, INT_MAX);
	} 
	while (userBufferSize <= 0);

	ringBuffer->BufferSize = userBufferSize;
	ringBuffer->FreeSpace = userBufferSize;
	ringBuffer->OccupiedSpace = 0;

	BufferNode *node = ringBuffer->Head;
	for (int i = 0; i < userBufferSize - 1; i++)
	{
		BufferNode *addedNode = new BufferNode;
		BufferNode *tempNode = node->NextBufferNode;
		node->NextBufferNode = addedNode;
		addedNode->NextBufferNode = tempNode;
		node = addedNode;
	}
}

void RingBufferPut(RingBuffer *ringBuffer, int value)
{
	ringBuffer->IndexIn->Data = value;
	ringBuffer->IndexIn->Full = true;
	ringBuffer->IndexIn = ringBuffer->IndexIn->NextBufferNode;
	ringBuffer->FreeSpace--;
	ringBuffer->OccupiedSpace++;
	if (ringBuffer->OccupiedSpace > ringBuffer->BufferSize)
	{
		ringBuffer->FreeSpace = 0;
		ringBuffer->OccupiedSpace = ringBuffer->BufferSize;
		ringBuffer->IndexOut = ringBuffer->IndexOut->NextBufferNode;
	}
}

int RingBufferGet(RingBuffer *ringBuffer)
{
	BufferNode *tempNode = ringBuffer->IndexOut;
	ringBuffer->IndexOut->Full = false;
	ringBuffer->IndexOut = ringBuffer->IndexOut->NextBufferNode;
	ringBuffer->FreeSpace++;
	ringBuffer->OccupiedSpace--;
	return tempNode->Data;
}

void RingBufferDeleting(RingBuffer *ringBuffer)
{
	BufferNode *nodeToDelete = ringBuffer->Head;
	ringBuffer->IsDeleted = true;
	for (int i = 0; i < ringBuffer->BufferSize; i++)
	{
		nodeToDelete = nodeToDelete->NextBufferNode;
		delete ringBuffer->Head;
		ringBuffer->Head = nodeToDelete;
	}
}
