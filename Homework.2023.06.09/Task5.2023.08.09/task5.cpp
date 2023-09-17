#include <iostream>
int main(int argc, char* argv[])
{
	int u = 0;
	int t = 0;
	std::cin >> u >> t;
	std::cout << ((u * t) % 109 + 109) % 109 + 1;
	return 0;
}