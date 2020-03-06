#include "Lab6Output.h"

void PrintMainMenuLab6()
{
	cout << "0. Выход\n";
	cout << "1. Красно Черное Дерево\n";
	cout << "2. АВЛ дерево\n";
}

void PrintAVLMenu()
{
	cout << "0. Выход\n";
	cout << "1. Вставка элемента\n";
	cout << "2. Удаление элемента\n";
	cout << "3. Поиск элемента\n";
	cout << "4. Вставка нескольких элементов\n";
}

void PrintRBTMenu()
{
	cout << "0. Выход\n";
	cout << "1. Вставка элемента\n";
	cout << "2. Удаление элемента\n";
	cout << "3. Поиск элемента\n";
	cout << "4. Вставка нескольких элементов\n";
}

void TreePrinting(string prefix, RBTreeNode *node, RBTree* tree,  bool isLeft)
{
	if (node != tree->Nil)
	{
		cout << prefix;
		cout << (isLeft ? "|-- " : "\\-- ");
		cout << node->Data << (node->IsBlack ? ": Black" : ": Red") << endl;
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->Left, tree,  true);
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->Right, tree,  false);
	}
}

void TreePrinting(RBTreeNode * node, RBTree* tree)
{
	TreePrinting("", node, tree, false);
}

void AVLTreePrinting(string prefix, Node* node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->Data << endl;
		AVLTreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->Left, true);
		AVLTreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->Right, false);
	}
}

void AVLTreePrinting(Node* node)
{
	AVLTreePrinting("", node, false);
}