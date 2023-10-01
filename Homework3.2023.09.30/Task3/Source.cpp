#include <iostream>

int main(int argc(), char* argv[]) {
	int n = 0;
	int c = 0;
	int i = 1;
	std::cin >> n;
	for (i; i * i < n; i++) {
		if (n % i == 0) {
			c += 2;
		}
	}
	if (i * i == n) {
		c += 1;
	}
	std::cout << c;
	return 0;
}