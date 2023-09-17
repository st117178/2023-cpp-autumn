#include <iostream>
int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    int A = a / b;
    int B = b / a;
    std::cout << (A * a + B * b) / (A + B);
    return 0;
}
