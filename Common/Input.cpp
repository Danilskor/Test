#include "Input.h"

bool CheckingForInteger(string value)
{
	int size = value.length();

	if (isdigit(value[0]) || value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit(value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int GetValue(int min, int max)
{
	const int MAX_INTEGER = 11;
	string inputValue;
	while (true)
	{
		getline(cin, inputValue);
		if (inputValue.length() <= MAX_INTEGER)
		{
			int outputValue;

			if (!CheckingForInteger(inputValue)
				|| stoll(inputValue) < min
				|| stoll(inputValue) > max)
			{
				cout << endl << "Ошибка! Попробуйте еще раз: ";
				inputValue.clear();
			}
			else
			{
				outputValue = stoll(inputValue);
				return outputValue;
			}
		}
		else
		{
			cout << endl << "Ошибка! Попробуйте еще раз: ";
			inputValue.clear();
		}
	}
}

string InputString()
{
	string inputValue;
	getline(cin, inputValue);
	return inputValue;
};