#include "Node.h"


int Height(Node* node)
{
	if (node != nullptr)
	{
		return node->Height;
	}
	else
	{
		return 0;
	}
}
int BalanceFactor(Node* node)
{
	return Height(node->Right) - Height(node->Left);

}

void FixHeight(Node* node)
{
	node->Height = (Height(node->Left) > Height(node->Right)
		? Height(node->Left)
		: Height(node->Right)
		) + 1;
}