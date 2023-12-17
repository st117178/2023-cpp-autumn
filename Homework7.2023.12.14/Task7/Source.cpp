#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>

bool Fpol(std::string a);

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::string a = "";
	fin >> a;
	fin.close();

	std::ofstream fout("out.txt");
	fout << Fpol(a);
	fout.close();

	return EXIT_SUCCESS;
}

bool Fpol(std::string a)
{
	int len = a.length();
	std::string c(len, '\0');
	for (int i = 0; i < len; i++)
	{
		c[i] = a[len - i - 1];
	}

	if (c == a)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}