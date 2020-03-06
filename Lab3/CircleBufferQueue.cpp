#include "CircleBufferQueue.h"

void DeleteCircleBufferQueue(CircleBuffer *queueCircleBuffer)
{
	if (queueCircleBuffer->isDeleted == false)
	{
		queueCircleBuffer->isDeleted = true;
		delete[] queueCircleBuffer;
	}
}
