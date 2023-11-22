#include<iostream>

void han(int count, int from, int to)
{
	if (count <= 0)
	{
		return;
	}
	else {
		int temp = 6 - from - to;
		if ((from == 1 && to == 3) || (from == 3 && to == 2) || (from == 2 && to == 1))
		{
			han(count - 1, from, to);
			std::cout << count << " " << from << " " << temp << std::endl;
			han(count - 1, to, from);
			std::cout << count << " " << temp << " " << to << std::endl;
			han(count - 1, from, to);
		}
		else
		{
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