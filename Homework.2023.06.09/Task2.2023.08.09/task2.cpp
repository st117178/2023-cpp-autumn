#include <iostream>
int main(int argc, char* argv[])
{
	int m = 0;
	int n = 0;
	int d = 0;
	std::cin >> m;
	d = (abs(m - 1)) / (m - 1);
	n = 1 + ((m - 1) / d);
	std::cout << (1 + m) * n / 2;
	return 0;
}