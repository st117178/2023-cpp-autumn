#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int b = 0;
	int c = 0;
	c = a % 100;
	b = a % 10;
	if (c >= 11 && c <= 14) {
		std::cout << a << " " << "bochek";
	}
	else {
		if (b == 1) {
			std::cout << a << " " << "bochka";
		}
		else {
			if (b >= 2 && b <= 4) {
				std::cout << a << " " << "bochki";
			}
			else {
				if ((b >= 2 && b <= 9) || (b == 0)) {
					std::cout << a << " " << "bochek";
				}
			}
		}
	}
	return 0;
}