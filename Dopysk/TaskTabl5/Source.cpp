#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << std::max(std::min(j + 1, n - j), std::min(i + 1, n - i));
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}