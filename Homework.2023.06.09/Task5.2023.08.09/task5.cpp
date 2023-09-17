#include <iostream>
int main(int argc, char* argv[])
{
	int U = 0;
	int T = 0;
	std::cin >> U >> T;
	std::cout << ((U * T) % 109 + 109) % 109 + 1;
	return 0;
}