#include <iostream>
int main(int argc, char* argv[])
{
	int N;
	int n;
	int d;
	std::cin >> N;
	d = (abs(N - 1)) / (N - 1);
	n = 1 + ((N - 1) / d);
	std::cout << (1 + N)* n / 2;
	return 0;
}