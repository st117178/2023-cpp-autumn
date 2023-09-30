#include <iostream>

int main() {
	int i = 0;
	std::cin >> i;
	for (i; i % 10 == 0; i / 10) {
		i = i / 10;
	}
	for (i; i != 0; i = i / 10) {
		std::cout << i % 10;
	}
	return 0;
}