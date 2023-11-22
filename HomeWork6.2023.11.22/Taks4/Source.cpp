#include<iostream>

void han(int count, int from, int to)
{
	if (count <= 0)
	{
		return;
	}
	else {
		if (count == 1)
		{
			std::cout << count << " " << from << " " << to << std::endl;
		}
		else
		{
			int temp = 6 - from - to;
			han(count - 1, from, to);
			std::cout << count << " " << from << " " << temp << std::endl;
			han(count - 1, to, from);
			std::cout << count << " " << temp << " " << to << std::endl;
			han(count - 1, from, to);

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