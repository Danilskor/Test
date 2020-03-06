#include "Lab5Output.h"

void TreePrinting(string prefix, BinaryTreeNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->Data << endl;
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->Left, true);
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->Rigth, false);
	}
}

void TreePrinting(BinaryTreeNode * node)
{
	TreePrinting("", node, false);
}

void TreapPrinting(TreapNode *node)
{
	TreapPrinting("", node, false);
}

void TreapPrinting(string prefix, TreapNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->Value << " ; " << node->Priority << endl;
		TreapPrinting(prefix + (isLeft ? "|   " : "    "),
			node->Left, true);
		TreapPrinting(prefix + (isLeft ? "|   " : "    "),
			node->Rigth, false);
	}
}

void PrintMainMenuLab5()
{
	cout << "0. Выход из программы\n";
	cout << "1. Бинарное дерево поиска\n";
	cout << "2. Декартово дерево\n";
}

void PrintTreeMenu()
{
	cout << "_____________________________\n";
	cout << "0. Выход из меню\n";
	cout << "1. Добавление элемента\n";
	cout << "2. Поиск элемента\n";
	cout << "3. Нахождение минимального\n";
	cout << "4. Нахождение максимального\n";
	cout << "5. Удаление элемента\n";
	cout << "_____________________________\n";
}

void PrintTreapMenu()
{
	cout << "_______________________________________\n";
	cout << "0. Выход из меню\n";
	cout << "1. Добавление элемента\n";
	cout << "2. Оптимизированное добавление элемента\n";
	cout << "3. Поиск элемента\n";
	cout << "4. Удаление элемента\n";
	cout << "5. Оптимизированное удаление элемента\n";
	cout << "_______________________________________\n";
}

void EnterValueMessage()
{
	cout << "Введите значение: ";
}

void SearchMessage(BinaryTreeNode* node)
{
	if (node != nullptr)
	{
		cout << "Элемент найден: " << node->Data << endl;
	}
	else
	{
		cout << "Не найдено!";
	}
}

void SearchMessage(TreapNode* node)
{
	if (node != nullptr)
	{
		cout << "Элемент найден: " << node->Value << endl;
	}
	else
	{
		cout << "Не найдено!";
	}
}