#include <iostream>
int main(int argc, char* argv[]) {
	long n = 0;
	std::cin >> n;
	long long a = n / 10;
	long long b = a + 1;
	std::cout << a * b * 100 + 25;
	return 0;
}