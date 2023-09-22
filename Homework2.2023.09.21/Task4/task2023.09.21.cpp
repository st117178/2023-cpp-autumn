#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int a1 = 0;
	int a5 = 0;
	int a10 = 0;
	int a20 = 0;
	int a60 = 0;
	std::cin >> a;
	a60 = a / 60;
	a20 = (a % 60) / 20;
	a10 = (a % 60 % 20) / 10;
	a5 = (a % 60 % 20 % 10) / 5;
	a1 = a % 5;
	if (a1 * 15 >= 70) {
		a5 += 1;
		a1 = 0;
	}
	if (a1 * 15 + a5 * 70 >= 125) {
		a1 = 0;
		a5 = 0;
		a10 += 1;
	}
	if (a1 * 15 + a5 * 70 + a10 * 125 >= 230) {
		a1 = 0;
		a5 = 0;
		a10 = 0;
		a20 += 1;
	}
	if (a1 * 15 + a5 * 70 + a10 * 125 + a20 * 230 >= 440) {
		a1 = 0;
		a5 = 0;
		a10 = 0;
		a20 = 0;
		a60 += 1;
	}
	std::cout << a1 << " " << a5 << " " << a10 << " " << a20 << " " << a60;
	return 0;
}