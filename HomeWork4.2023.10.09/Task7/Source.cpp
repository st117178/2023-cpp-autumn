#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	int c = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
		if (*(a + i) <= 0)
		{
			*(a + i) = 0;
		}
		else {
			c++;
		}
	}

	int* b = (int*)malloc(sizeof(int) * c);

	int p = 0;
	for (int j = 0; j < n; j++)
	{
		if (*(a + j) > 0)
		{
			*(b + p) = *(a + j);
			std::cout << *(b + p) << " ";
			p++;
		}
	}
	free(a);
	free(b);

	return 0;
}
