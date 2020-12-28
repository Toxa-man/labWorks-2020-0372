#include <iostream>
#include <ctime>

void sort(int* auf, int size)
{
	int x = 0;
	int temp;
	while (x < size)
	{
		for (int i = 0; i < size; i++)
		{
			if (auf[x] < auf[i])
			{
				temp = auf[x];
				auf[x] = auf[i];
				auf[i] = temp;
				x--;
				break;
			}
		}
		x++;
	}
}

int main()
{
	srand(time(0));
	const int size = 10;
	int auf[size];
	float avg_value = 0;
	int count_odd = 0;

	std::cout << "Unsorted array:\n";
	for (int i = 0; i < size; i++)
	{
		auf[i] = rand() % 21 - 10;
		if (auf[i] % 2 != 0)
			count_odd++;

		avg_value += auf[i];

		std::cout << auf[i] << ' ';
	}

	int* odd_auf = new int[count_odd];

	sort(auf, size);

	std::cout << "\n\nSorted array:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << auf[i] << ' ';
		int bruh = 0;
		if (auf[i] % 2 != 0)
		{
			odd_auf[bruh] = auf[i];
			bruh++;
		}
	}
	std::cout << '\n';
	std::cout << "\nMin. value: " << auf[0];
	std::cout << "\nMax. value: " << auf[size - 1];
	std::cout << "\nAvg. value: " << avg_value / size << std::endl;
}
