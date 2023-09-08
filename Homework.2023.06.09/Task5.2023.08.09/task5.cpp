#include <iostream>
int main(int argc, char* argv[])
{
	int U;
	int T;
	std::cin >> U >> T;
	std::cout << ((U * T) % 109 + 109) % 109 + 1;
	return 0;
}