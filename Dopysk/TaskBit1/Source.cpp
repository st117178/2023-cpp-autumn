#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int c = 0;
	std::cin >> n;

	for (int i = 0; n >> i != 0; i++) {
		if ((n >> i & 1) == 1) {
			c++;
		}
	}
	std::cout << c;

	return EXIT_SUCCESS;
}