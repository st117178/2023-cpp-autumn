#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;

	int sum = 0;
	while (a / 10 != 0)
	{
		sum += a % 10;
		a = a / 10;
	}

	std::cout << (sum + a);

	return EXIT_SUCCESS;
}