#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;

	if (a >= 0)
	{
		for (int i = 0; i <= a; ++i)
		{
			std::cout << i << " ";
		}
	}

	else
	{
		for (int j = 0; j >= a; --j)
		{
			std::cout << j << " ";
		}
	}

	return EXIT_SUCCESS;
}