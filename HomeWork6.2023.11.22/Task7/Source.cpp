#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	d[to][n[to]++] = d[from][--n[from]];
}

void hanoy(int count, int from = 1, int to = 3)
{
	if (count <= 0)
	{
		return;
	}

	int temp = 6 - from - to;

	hanoy(count - 1, from, temp);
	shift(from, to);
	hanoy(count - 1, temp, to);
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int top(int a)
{
	if (n[a] > 0)
	{
		return d[a][n[a] - 1];
	}
	else
	{
		return 777;
	}
}

void sort(int a = 1)
{
	int b = 0;
	if (a == 3)
	{
		b = 2;
	}
	else
	{
		b = a + 1;
	}

	int c = 6 - a - b;

	while (n[a] > 0)
	{
		int t = top(a);
		while (top(c) < t)
		{
			int temp = 0;
			for (int i = 0; i < n[b]; ++i)
			{
				if (d[b][i] > top(c))
				{
					temp++;
				}
			}
			hanoy(n[b] - temp, b, c);
			swap(b, c);
		}
		shift(a, c);
	}
	while (n[c] > 0)
	{
		int temp = 0;
		for (int i = 0; i < n[b]; ++i)
		{
			if (d[b][i] > top(c))
			{
				temp++;
			}
		}
		hanoy(n[b] - temp, b, c);
		swap(b, c);
	}
}

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i)
	{
		std::cin >> d[1][i];
	}
	sort();
	return 0;
}
