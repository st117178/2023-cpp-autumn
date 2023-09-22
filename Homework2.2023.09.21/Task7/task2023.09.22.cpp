#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int e = 0;
	int d = 0;
	std::cin >> a;
	e = a % 10;
	d = (a / 10);
	d = d - ((d / 10) * 10);
	if (a == 100) {
		std::cout << "C";
		return 0;
	}
	if (d == 0) {
		std::cout << "";
	}
	if (d == 1) {
		std::cout << "X";
	}
	if (d == 2) {
		std::cout << "XX";
	}
	if (d == 3) {
		std::cout << "XXX";
	}
	if (d == 4) {
		std::cout << "XL";
	}
	if (d == 5) {
		std::cout << "L";
	}
	if (d == 6) {
		std::cout << "LX";
	}
	if (d == 7) {
		std::cout << "LXX";
	}
	if (d == 8) {
		std::cout << "LXXX";
	}
	if (d == 9) {
		std::cout << "XC";
	}
	if (e == 1) {
		std::cout << "I";
	}
	if (e == 2) {
		std::cout << "II";
	}
	if (e == 3) {
		std::cout << "III";
	}
	if (e == 4) {
		std::cout << "IV";
	}
	if (e == 5) {
		std::cout << "V";
	}
	if (e == 6) {
		std::cout << "VI";
	}
	if (e == 7) {
		std::cout << "VII";
	}
	if (e == 8) {
		std::cout << "VIII";
	}
	if (e == 9) {
		std::cout << "IX";
	}
	return 0;
}