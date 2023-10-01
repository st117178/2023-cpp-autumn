#include<iostream>

int main() {
	int a = 0;
	int b = 0;
	int a1 = 0;
	int b1 = 0;
	int n = 0;
	int g = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	if (b > a) {
		std::swap(a, b);
		for (int i = 1; i <= a; i++) {
			if (a % i == 0 && b % i == 0) {
				g = i;
			}
		}
		if (g % n != 0) {
			std::cout << "Impossible";
			return 0;
		}
		while (b1 != n && a1 != n) {
			while (b1 < b) {
				while (a1 < a) {
					a1++;
					if (a1 == a) {
						std::cout << ">A" << std::endl;
					}
				}
				while (b1 < b && a1 != 0) {
					b1++;
					a1--;
					if (b1 == b || a1 == 0) {
						std::cout << "A>B" << std::endl;
					}
				}
			}

			if (a1 == n || b1 == n) {
				return 0;
			}
			while (b1 > 0) {
				b1--;
				if (b1 == 0) {
					std::cout << "B>" << std::endl;
				}
			}

			if (a1 == n || b1 == n) {
				return 0;
			}
			while (a1 > 0 && b1 != b) {
				b1 += 1;
				a1 -= 1;
				if (b1 == b || a1 == 0) {
					std::cout << "A>B" << std::endl;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= a; i++) {
			if (a % i == 0 && b % i == 0) {
				g = i;
			}
		}
		if (g % n != 0) {
			std::cout << "Impossible";
			return 0;
		}
		while (b1 != n && a1 != n) {
			while (b1 < b) {
				while (a1 < a) {
					a1++;
					if (a1 == a) {
						std::cout << ">B" << std::endl;
					}
				}
				while (b1 < b && a1 != 0) {
					b1++;
					a1--;
					if (b1 == b || a1 == 0) {
						std::cout << "B>A" << std::endl;
					}
				}
			}
			if (a1 == n || b1 == n) {
				return 0;
			}
			while (b1 > 0) {
				b1--;
				if (b1 == 0) {
					std::cout << "A>" << std::endl;
				}
			}
			if (a1 == n || b1 == n) {
				return 0;
			}
			while (a1 > 0 && b1 != b) {
				b1 += 1;
				a1 -= 1;
				if (b1 == b || a1 == 0) {
					std::cout << "B>A" << std::endl;
				}
			}
		}
	}
	return 0;
}