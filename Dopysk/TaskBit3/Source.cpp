#include<iostream>

int main(int argc, char* argv[])
{
	short a = 0;
	std::cin >> a;
	short b = 0;
	std::cin >> b;

	bool vu = 0;
	int s = 0;

	for (int i = 0; a >> i != 0 || b >> i != 0; i++)
	{
		vu = (a & b) | (a & vu) | (b & vu);
		s |= ((a >> i & 1) ^ (b >> i & 1) ^ vu) << i;

	}

	std::cout << s;

	return EXIT_SUCCESS;
}
