#include "MainMenu.h"
#include "..\PrintMainMenu.h"
#include "..\Lab1\Lab1Main.h"
#include "..\Lab2\Lab2Main.h"
#include "..\Lab3\Lab3Main.h"
#include "..\Lab4\Lab4Main.h"
#include "..\Lab5\Lab5Main.h"
#include "..\Lab6\Lab6Main.h"

int MainMenu()
{
	const int EXIT_MENU_VALUE = 0;
	while (true)
	{
		PrintMainMenu();
		int menuValue = GetValue(0,6);
		switch (menuValue)
		{
			case 0:
			{
				return 0;
			}
			case 1:
			{
				Lab1Main();
				system("cls");
				break;
			}
			case 2:
			{
				Lab2Main();
				system("cls");
				break;
			}
			case 3:
			{
				Lab3Main();
				system("cls");
				break;
			}
			case 4:
			{
				Lab4Main();
				system("cls");
				break;
			}
			case 5:
			{
				Lab5Main();
				system("cls");
				break;
			}
			case 6:
			{
				Lab6Main();
				system("cls");
				break;
			}
			default:
			{
			break;
			}
		}
	}
}