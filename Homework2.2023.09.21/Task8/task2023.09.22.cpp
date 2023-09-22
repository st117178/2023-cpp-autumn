#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	int m1 = 0;
	int m2 = 0;
	int m3 = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a <= b && a <= c && b <= c) {
		m1 = a;
		m2 = b;
		m3 = c;
	}
	else {
		if (a <= b && a <= c && b >= c) {
			m1 = a;
			m3 = b;
			m2 = c;
		}
		else {
			if (b <= a && b <= c && a <= c) {
				m1 = b;
				m2 = a;
				m3 = c;
			}
			else {
				if (b <= a && b <= c && a >= c) {
					m1 = b;
					m2 = c;
					m3 = a;
				}
				else {
					if (c <= a && c <= b && a <= b) {
						m1 = c;
						m2 = a;
						m3 = b;
					}
					else {
						if (c <= a && c <= b && a >= b) {
							m1 = c;
							m2 = b;
							m3 = a;
						}
					}
				}
			}
		}
	}
	std::cout << m1 << " " << m2 << " " << m3;
	return 0;
}