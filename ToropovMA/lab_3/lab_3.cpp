#include <iostream>

int countWords(char* string)
{
	int x = 1;
	for (int i = 0; i < strlen(string); i++)
		if (string[i] == ' ')
			x++;
	return x;
}

int getValue(char* str)
{
	int x = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		x += (int)str[i];
	}
	return x;
}

void sort(char** string, int words_count)
{
	char* temp;
	int x = 0;
	while (x < words_count)
	{
		for (int i = 0; i < words_count; i++)
		{
			if (getValue(string[x]) < getValue(string[i]))
			{
				temp = string[x];
				string[x] = string[i];
				string[i] = temp;
				x--;
				break;
			}
		}
		x++;
	}
}

int main()
{
	char str1[256];
	std::cout << "Enter ur string:\n";
	std::cin.getline(str1, 256);

	int words_count = countWords(str1);
	int length = strlen(str1);

	char** str2 = new char* [words_count];
	for (int i = 0; i < words_count; i++)
		str2[i] = new char[length]();

	int x = 0;
	int pos = 0;
	for (int i = 0; i < length; i++)
	{
		if (str1[i] != ' ')
		{
			str2[x][pos] = str1[i];
			pos++;
		}
		else
		{
			str2[x][pos] = '\0';
			x++;
			pos = 0;
		}
	}

	std::cout << "Sorted string:\n";
	sort(str2, words_count);
	for (int i = 0; i < words_count; i++)
		std::cout << str2[i] << ' ';

	for (int i = 0; i < words_count; i++)
		delete[] str2[i];
	delete[] str2;
}
