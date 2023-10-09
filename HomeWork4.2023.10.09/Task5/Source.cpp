#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	for (int j = 0; j < n; j++)
	{
		std::cout << *(a + n - j - 1) << " ";
	}
	free(a);

	return 0;
}