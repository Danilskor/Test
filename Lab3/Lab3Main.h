#pragma once

#include "Stack.h"
#include "../Common/Input.h"
#include "Lab3Output.h"
#include "RingBuffer.h"
#include "StackQueue.h"
#include "RingBufferQueue.h"
#include "Windows.h"

int MenuStack(Stack*);
int MenuCircleBuffer(RingBuffer*);
int StackMenuQueue(StackQueue*);
int RingBufferMenuQueue(RingBuffer*);
int Lab3Main();