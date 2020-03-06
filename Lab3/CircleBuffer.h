#pragma once
#include <iostream>
#include "../Common/Input.h"

struct CircleBuffer
{
	int *Array;
	int Length = 0;
	int Capacity;
	int InIndex = 0;
	int OutIndex = 0;
	bool *isFull;
	bool isDeleted = true;
};

CircleBuffer * CreateCircleBuffer();
int FreeSpace(CircleBuffer*);
int FilledSpce(CircleBuffer*);
void AddingElmentCircleBuffer(CircleBuffer*);
int GetCircleBuffer(CircleBuffer*);
void DeletingCircleBuffer(CircleBuffer*);
void InitializationBuffer(CircleBuffer*);