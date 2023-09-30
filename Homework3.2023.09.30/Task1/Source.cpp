#include<iostream>

int main() {
	int a = 1;
	int n = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i && a <= n; j++) {
			std::cout << i << " ";
			a++;
		}
	}
	return 0;
}