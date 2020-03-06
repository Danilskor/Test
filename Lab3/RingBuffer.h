#pragma once

#include "BufferNode.h"
#include "..\Common\Input.h"

struct RingBuffer
{
	BufferNode *IndexIn;
	BufferNode *IndexOut;
	int BufferSize;
	BufferNode *Head;
	int FreeSpace;
	int OccupiedSpace;
	bool IsDeleted = true;
};

void RingBufferCreation(RingBuffer *);
void BufferInitialisation(RingBuffer *);
void RingBufferPut(RingBuffer *, int);
int RingBufferGet(RingBuffer *);
void RingBufferDeleting(RingBuffer *);