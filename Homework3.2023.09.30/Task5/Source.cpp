#include <iostream>

int main(int argc(), char* argv[]) {
	int a = 0;
	int c = 0;
	std::cin >> a;
	for (int i = 1; i <= a; i++) {
		int b = 0;
		for (int c = i; c; c = c / 10) {
			b = b * 10 + i % 10;
		}
		if (i == b) {
			c++;
		}
	}
	std::cout << c;
	return 0;
}