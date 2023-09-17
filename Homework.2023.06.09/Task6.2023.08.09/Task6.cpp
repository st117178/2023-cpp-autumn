#include <iostream>
int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    int x = a / b;
    int y = b / a;
    std::cout << (x * a + y * b) / (x + y);
    return 0;
}
