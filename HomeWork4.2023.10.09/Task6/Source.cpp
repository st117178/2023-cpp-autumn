#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int min = 0;
	int max = 0;
	int min_p = 0;
	int max_p = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	std::cin >> *(a);
	min = *(a);
	max = *(a);

	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);

		if (max <= *(a + i))
		{
			max = *(a + i);
			max_p = i;
		}
		if (min > *(a + i))
		{
			min = *(a + i);
			min_p = i;
		}
	}
	*(a + min_p) = max;
	*(a + max_p) = min;

	for (int j = 0; j < n; j++)
	{
		std::cout << *(a + j) << " ";
	}
	free(a);

	return 0;
}