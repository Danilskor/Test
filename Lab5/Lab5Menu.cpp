#include "Lab5Menu.h"

void Lab5Menu()
{
	while (true)
	{
		PrintMainMenuLab5();
		int menuValue = GetValue(0, 3);
		switch (menuValue)
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				BinaryTreeMenu();
				break;
			}
			case 2:
			{
				TreapMenu();
				break;
			}
		}
	}
}

void BinaryTreeMenu()
{
	system("cls");
	BinaryTree* binaryTree = CreateBinaryTree();
	while (true)
	{
		TreePrinting(binaryTree->Root);
		PrintTreeMenu();
		int menuValue = GetValue(0, 5);
		switch (menuValue)
		{
			case 0:
			{
				DeleteTree(binaryTree->Root);
				system("cls");
				return;
			}
			case 1:
			{
				system("cls");
				EnterValueMessage();
				Insert(binaryTree->Root, binaryTree,
					GetValue(INT_MIN, INT_MAX));
				break;
			}
			case 2:
			{
				system("cls");
				EnterValueMessage();
				SearchMessage(FindElement(binaryTree->Root, GetValue(INT_MIN, INT_MAX)));
				break;
			}
			case 3:
			{
				system("cls");
				SearchMessage((FindMinMax(binaryTree->Root, "min")));
				break;
			}
			case 4:
			{
				system("cls");
				SearchMessage(FindMinMax(binaryTree->Root, "max"));
				break;
			}
			case 5:
			{
				system("cls");
				EnterValueMessage();
				DeleteNode(binaryTree, GetValue(INT_MIN, INT_MAX), binaryTree->Root);
				break;
			}
		}
	}
}

void TreapMenu()
{
	system("cls");
	Treap* treap = CreateTreap();
	while (true)
	{
		TreapPrinting(treap->Root);
		PrintTreapMenu();
		int menuValue = GetValue(0, 5);

		switch (menuValue)
		{
			case 0:
			{
				system("cls");
				DeleteTreap(treap);
				return;
			}
			case 1:
			{
				system("cls");
				EnterValueMessage();
				Add(treap, GetValue(INT_MIN,INT_MAX));
				break;
			}
			case 2:
			{
				system("cls");
				TreapNode *newNode = CreateNode();
				newNode->Priority = rand() % 100;
				EnterValueMessage();
				newNode->Value = GetValue(INT_MIN, INT_MAX);
				OptimisedAdd(treap, treap->Root, newNode);
				break;
			}
			case 3:
			{
				EnterValueMessage();
				SearchMessage(Search(GetValue(INT_MIN, INT_MAX), treap->Root));
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				EnterValueMessage();
				DeleteNode(treap, GetValue(INT_MIN, INT_MAX));
				system("cls");
				break;
			}
			case 5: 
			{
				EnterValueMessage();
				DeleteNodeOptimize(treap, GetValue(INT_MIN, INT_MAX), treap->Root);
				system("cls");
				break;
			}
		}
	}
}