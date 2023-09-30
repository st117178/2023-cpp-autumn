#include <iostream>

int main() {
	int a = 0;
	int c = 0;
	std::cin >> a;
	for (int i = 1; i < a; i = i * 2) {
		c++;
	}
	std::cout << c;
	return 0;
}