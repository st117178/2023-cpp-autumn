#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	if (a == 0 && b == 0) {
		std::cout << "INF";
	}
	else if (a == 0 || (a * d) == (b * c)) {
		std::cout << "NO";
	}
	else if (b % a == 0) {
		int x = -b / a;
		std::cout << x << std::endl;
	}
	else {
		std::cout << "NO";
	}

	return 0;
}
