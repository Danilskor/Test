#include "List.h"
#include <ctime>
#include "Lab2Main.h"

int Lab2Main()
{
	srand(unsigned(time(NULL)));

	
	List *list = CreateList();
	
	while (true)
	{
		int value = 0;
		int index = 0;
		const int exitValue = 0;
		system("cls");
		PrintList(list);
		PrintMenu();
		cout << "\n������� ����� ����: ";
		switch (GetValue(0, 8))
		{
			case 1: 
			{
				AddNode(list); 
				break; 
			}
			case 2:
			{
				if (list->Size > 2)
				{
					cout << "������� ������: ";
					DeleteNode(list, GetValue(0, list->Size - 1));
				}
				else
				{
					cout << "���������� ������ ������ 2.\n";
					system("pause");
				}
				break;
			}
			case 3:
			{
				cout << "������� ��������: ";
				value = GetValue(INT_MIN, INT_MAX);

				clock_t begin = clock();
				InsertNode(list, 0, value);
				clock_t end = clock();

				cout << endl << "Time: " << 
					double(end - begin) / CLOCKS_PER_SEC << endl;
				system("pause");
				break;
			}
			case 4:
			{
				cout << "������� ��������: ";
				value = GetValue(INT_MIN, INT_MAX);
				InsertNode(list, list->Size, value);
				break;
			}
			case 5:
			{
				cout << "������� ������ ��������: ";
				index = GetValue(0, list->Size - 1) + 1;
				cout << "������� ��������: ";
				value = GetValue(INT_MIN, INT_MAX);

				clock_t begin = clock();
				InsertNode(list, index, value);
				clock_t end = clock();

				cout << endl << "Time: " << 
					double(end - begin) / CLOCKS_PER_SEC << endl;
				system("pause");
				break;
			}
			case 6:
			{
				cout << "������� ������ ��������: ";
				index = GetValue(0, list->Size - 1);
				cout << "������� ��������: ";
				value = GetValue(INT_MIN, INT_MAX);
				InsertNode(list, index, value);
				break;
			}
			case 7: 
			{
				BubbleSort(list);
				break;
			}
			case 8: 
			{
				cout << "������� �������� ��������: ";
				LinearSearch(list, GetValue(INT_MIN, INT_MAX));
				cout << endl;
				system("pause");
				break;
			}
			case exitValue:
			{
				DeleteList(list);
				return 0;
				break;
			}
		}
	}
}