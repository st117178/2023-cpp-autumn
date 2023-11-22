#include<iostream>

void han(int count, int from, int to)
{
	if (count <= 0)
	{
		return;
	}
	else {
		if (from + to == 4)
		{
			han(count, from, 2);
			han(count, 2, to);
		}
		else{

		int temp = 6 - from - to;
		han(count - 1, from, temp);
		std::cout << count << " " << from << " " << to << std::endl;
		han(count - 1, temp, to);
		}
	}
}

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	han(a, 1, 3);
	return EXIT_SUCCESS;
}