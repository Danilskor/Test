#include "RingBufferQueue.h"

void AddNewElement(RingBuffer *ringBuffer)
{
	if (ringBuffer->IndexIn->NextBufferNode == ringBuffer->IndexOut)
	{
		BufferNode *node = ringBuffer->IndexIn;
		BufferNode *addedNode = new BufferNode;
		BufferNode *tempNode = node->NextBufferNode;
		node->NextBufferNode = addedNode;
		addedNode->NextBufferNode = tempNode;
		node = addedNode;
		ringBuffer->IndexIn->Full = true;
		ringBuffer->BufferSize++;
	}
}