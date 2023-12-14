#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

char* Fstrstr(char* a, char* b);

int main(int argc, char* argv[])
{
	char a[255] = "dasAarArAR";
	char b[255] = "ar";
	std::cout << Fstrstr(a, b);
	return EXIT_SUCCESS;
}

char* Fstrstr(char* a, char* b)
{

	while (*a != '\0')
	{
		if ((*a == *b))
		{
			return a;
		}
		a++;
	}

	return 0;
}