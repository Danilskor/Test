#pragma once

#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "StackQueue.h"

using namespace std;

void PrintMainMenu(int);
void PrintStackMenu(int, int);
void PrintStack(Stack*, string);
void PrintElement(int);
void PrintInput();
void PrintFreeSpase();
void PrintOccupedSpase();
void PrintCircleBufferMenu(int, int);
void PrintQueueMenu(int, int);
void PrintStackQueue(StackQueue*);
void PrintCreateCircleBuffer();
void PrintCreateStack();
void PrintBuffer(RingBuffer);
