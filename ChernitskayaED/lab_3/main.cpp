#include <iostream>
using namespace std;

void sorting(char** c, int lot) 
{
	char* sorted;
	for (int i = 0; i < lot; i++)
	{
		for (int j = i + 1; j < lot; j++)
		{
			sorted = c[i];
			if (strlen(c[j]) < strlen(sorted))
			{
				c[i] = c[j];
				c[j] = sorted;
			}
		}
	}
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку:" << endl;
	char c[255];
	int lot = 1;
	for (int i = 0;;i++)
	{
		c[i] = getchar();
		if (c[i] == ' ')
		{
			lot += 1;
		}
		if (c[i] == '\n')
		{
			c[i] = '\0';
			break;
		}
	}
	char** str = new char* [lot];
	for (int i = 0; i < lot; ++i)
	{
		str[i] = new char[255];
	}

	int x = 0, count = 0;

	for (int i = 0; i <= strlen(c); ++i)
	{
		if (c[i] != ' ')
		{
			str[x][count] = c[i];
			count += 1;;
		}
		if (c[i] == ' ')
		{
			str[x][count] = '\0';
			x += 1;;
			count = 0;
		}
	}

	sorting(str, lot);

	cout << "Отсортированная строка:" << endl;
	for (int i = 0; i < lot; i++)
		cout << str[i] << " ";

	return 0;
}
