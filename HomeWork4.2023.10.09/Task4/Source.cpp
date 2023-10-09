#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	std::cin >> *(a);
	m = *(a);

	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);

		if (*(a) < *(a + i))
		{
			m = *(a + i);
		}
	}
	std::cout << m;
	free(a);

	return 0;
}