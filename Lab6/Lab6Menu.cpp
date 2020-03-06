#include "Lab6Menu.h"

void Lab6Menu()
{
	
	while (true)
	{
		system("cls");
		PrintMainMenuLab6();
		int menuValue = GetValue(0, 2);
		switch (menuValue)
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				RedBlackTree();
				break;
			}
			case 2:
			{
				AVLMenu();
				break;
			}
		}
	}
	return;
}

void AVLMenu()
{
	system("cls");
	AVLTree* tree = InitialisationTree();
	while (true)
	{
		if (tree != nullptr)
		{
			AVLTreePrinting(tree->Root);
		}
		PrintAVLMenu();
		int menuValue = GetValue(0, 4);
		switch (menuValue)
		{
			case 0:
			{
				DeleteAVLTree(tree->Root);
				return;
			}
			case 1:
			{
				system("cls");
				cout << "Введите значение: ";
				int value = GetValue(INT_MIN, INT_MAX);
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				tree->Root = Insert(tree->Root, value, tree);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Время = " << 
					std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() 
					<< "[ns]" << std::endl;

				cout << "Поворотов: " << tree->NumberOfRotation;
				cout << endl;
				system("pause");
				cout << endl;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Введите значение: ";
				int value = GetValue(INT_MIN, INT_MAX);
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				tree->Root = DeleteNode(value, tree->Root, tree);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Время = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
					<< "[ns]" << std::endl;

				cout << "Поворотов: " << tree->NumberOfRotation;
				cout << endl;
				system("pause");
				cout << endl;
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Введите значение: ";
				int value = GetValue(INT_MIN, INT_MAX);
				if (FindNode(tree->Root, value) != nullptr)
				{
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
					Node* node = FindNode(tree->Root, value);
					cout << node->Data << endl;
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					std::cout << "Время = " <<
						std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
						<< "[ns]" << std::endl;
					system("pause");
					cout << endl;
				}
				else
				{
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
					cout << "Не найдено\n";
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					std::cout << "Время = " <<
						std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
						<< "[ns]" << std::endl;
					system("pause");
					cout << endl;
				}
				break;
			}
			case 4:
			{
				system("cls");
				cout << "ВВедите количество добавляемых значений: ";
				int numberOfNode = GetValue(INT_MIN, INT_MAX);
				for (int i = 0; i < numberOfNode; i++)
				{
					int value = rand() % 201 - 100;
					Insert(tree->Root, value, tree);
				}
				break;
			}
		}
	}
	return;
}

void RedBlackTree()
{
	system("cls");
	RBTree* tree = InitTree();
	while (true)
	{
		TreePrinting(tree->Root, tree);
		PrintRBTMenu();
		int menuValue = GetValue(0, 4);
		switch (menuValue)
		{
			case 0:
			{
				DeleteTree(tree, tree->Root);
				return;
			}
			case 1:
			{
				system("cls");
				cout << "Введите значение: ";
				int value = GetValue(INT_MIN, INT_MAX);
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

				InsertNode(value, tree->Root, tree);

				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Время = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
					<< "[ns]" << std::endl;

				cout << "Поворотов: " << tree->NumberOfRotation;
				cout << endl;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Введите значение: ";
				int value = GetValue(INT_MIN, INT_MAX);
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

				DeleteNodeByData(value, tree);

				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				std::cout << "Время = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
					<< "[ns]" << std::endl;

				cout << "Поворотов: " << tree->NumberOfRotation;
				cout << endl;
				cout << endl;
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Введите значение: ";
				int value = GetValue(INT_MIN, INT_MAX);
				if (SearchNode(tree->Root, value, tree->Nil) == tree->Nil)
				{
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

					cout << "Нет такого значения\n";

					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					std::cout << "Время = " <<
						std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
						<< "[ns]" << std::endl;
					cout << endl;
				}
				else
				{
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

					RBTreeNode* node = SearchNode(tree->Root, value, tree->Nil);
					cout << node->Data << endl;

					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					std::cout << "Время = " <<
						std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
						<< "[ns]" << std::endl;
					cout << endl;
				}
				break;
			}
			case 4:
			{
				system("cls");
				cout << "Введите количество элементов: ";
				int numberOfNode = GetValue(INT_MIN, INT_MAX);
				for (int i = 0; i < numberOfNode; i++)
				{
					int value = rand() % 201 - 100;
					InsertNode(value, tree->Root, tree);
				}
				break;
			}
		}
	}
	return;
}