#include<iostream>

void han(int count, int from, int to)
{
	if (count <= 0)
	{
		return;
	}

	int temp = 6 - from - to;
	han(count - 1, from, temp);
	std::cout << count << " " << from << " " << to << std::endl;
	han(count - 1, temp, to);
}

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int to = 0;
	if (a % 2 == 0)
	{
		to = 3;
	}
	else
	{
		to = 2;
	}
	int from = 1;
	han(a, from, to);
	int temp = 5 - to;
	for (int i = a; i > 0; i--)
	{
		han(i - 1, to, temp);
		std::swap(to, temp);
	}
	return EXIT_SUCCESS;
}