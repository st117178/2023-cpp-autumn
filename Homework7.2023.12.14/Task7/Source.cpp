#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

bool Fpol(std::string a, std::string b);

int main(int argc, char* argv[])
{
	std::string a = "abs";
	std::string b = "sba";
	std::cout << Fpol(a, b);
	return EXIT_SUCCESS;
}

bool Fpol(std::string a, std::string b)
{
	if (a.length() == b.length())
	{
		int len = a.length();
		std::string c (len, '\0');
		for (int i = 0; i < len; i++)
		{
			c[i] = a[len - i - 1];
		}
		
		if (c == b)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		return 0;
	}
}