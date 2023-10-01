#include <iostream>

int main(int argc(), char* argv[]) {
	int n = 0;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0;
	}
	else {
		int a = 0, b = 1;
		for (int i = 2; i <= n; i++) {
			int t = a;
			a = b;
			b = t + b;
		}
		std::cout << b;
	}
	return 0;
}