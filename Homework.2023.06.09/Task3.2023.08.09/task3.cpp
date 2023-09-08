#include <iostream>
int main() {
	long n;
	std::cin >> n;
	long long a = n / 10;
	long long b = a + 1;
	std::cout << a * b * 100 + 25;
	return 0;
}