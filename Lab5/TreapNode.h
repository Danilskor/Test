#pragma once

struct TreapNode
{
	int Value;
	int Priority;
	TreapNode* Left;
	TreapNode* Rigth;
	TreapNode* Parent;
};