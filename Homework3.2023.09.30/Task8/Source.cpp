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
	if (n > a && n > b) {
		std::cout << "Impossible";
		return 0;
	}
	if (b > a) {
		std::swap(a, b);
		for (int i = 1; i <= a; i++) {
			if (a % i == 0 && b % i == 0) {
				g = i;
			}
		}
		if (n % g != 0) {
			std::cout << "Impossible";
			return 0;
		}
		while (b1 != n && a1 != n) {
			while (a1 < a) {
				while (b1 < b) {
					b1++;
					if (b1 == b) {
						std::cout << ">A" << std::endl;
					}
				}
				if (a1 == n || b1 == n) {
					return 0;
				}
				while (b1 > 0 && a1 < a) {
					a1++;
					b1--;
					if (b1 == 0 || a1 == a) {
						std::cout << "A>B" << std::endl;
					}
				}
				if (a1 == n || b1 == n) {
					return 0;
				}
			}

			if (a1 == n || b1 == n) {
				return 0;
			}
			while (a1 > 0) {
				a1--;
				if (a1 == 0) {
					std::cout << "B>" << std::endl;
				}
			}

			if (a1 == n || b1 == n) {
				return 0;
			}
			while (b1 > 0 && a1 < a) {
				a1 += 1;
				b1 -= 1;
				if (a1 == a || b1 == 0) {
					std::cout << "A>B" << std::endl;
				}
			}
			if (a1 == n || b1 == n) {
				return 0;
			}
		}
	}
	else {

		for (int i = 1; i <= a; i++) {
			if (a % i == 0 && b % i == 0) {
				g = i;
			}
		}
		if (n % g != 0) {
			std::cout << "Impossible";
			return 0;
		}
		while (b1 != n && a1 != n) {
			while (a1 < a) {
				while (b1 < b) {
					b1++;
					if (b1 == b) {
						std::cout << ">B" << std::endl;
					}
				}
				if (a1 == n || b1 == n) {
					return 0;
				}
				while (b1 > 0 && a1 < a) {
					a1++;
					b1--;
					if (b1 == 0 || a1 == a) {
						std::cout << "B>A" << std::endl;
					}
				}
				if (a1 == n || b1 == n) {
					return 0;
				}
			}

			if (a1 == n || b1 == n) {
				return 0;
			}
			while (a1 > 0) {
				a1--;
				if (a1 == 0) {
					std::cout << "A>" << std::endl;
				}
			}

			if (a1 == n || b1 == n) {
				return 0;
			}
			while (b1 > 0 && a1 < a) {
				a1 += 1;
				b1 -= 1;
				if (a1 == a || b1 == 0) {
					std::cout << "B>A" << std::endl;
				}
			}
			if (a1 == n || b1 == n) {
				return 0;
			}
		}
	}
	return 0;
}