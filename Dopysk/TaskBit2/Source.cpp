#include<iostream>

int main(int argc, char* argv[])
{
	unsigned int a = 0;
	std::cin >> a;

	int minb = 1;
	for (int i = 0; (a >> i & 1) != 1 && a != 0; i++)
	{
		minb++;
	}

	int maxb = 0;
	for (int j = 0; a >> j != 0; j++)
	{
		maxb++;
	}

	int mask = 0;
	for (int k = maxb - 2; k >= minb; --k)
	{
		mask += 1 << k;
	}

	std::cout << (a ^ mask);

	return EXIT_SUCCESS;
}