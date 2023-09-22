#include <iostream>

int main(int argc, char* argv[]) {
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	int t;
	if (n <= k) {
		t = 2 * m;
	}
	else if (n * 2 % k == 0) {
		t = m * (n * 2 / k);
	}
	else {
		t = m * (1 + (n * 2 / k));
	}
	std::cout << t;
	return 0;
}