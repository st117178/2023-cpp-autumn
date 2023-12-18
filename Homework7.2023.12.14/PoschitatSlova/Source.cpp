#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <locale.h>

int slova(char* a);

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";

	fgets(a, 255, f);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "Count world: %d\n", slova(a));
	fclose(f);

	return EXIT_SUCCESS;
}

int slova(char* a)
{
	int len = strlen(a);
	int c = 0;

	for (int i = 0; i < len; i++)
	{
		if (a[i] == ' ')
		{
			c++;
		}
	}

	return (c+1);
}






/*
* 
* 
* 
FILE* f = fopen("in.txt", "r");

	fscanf(f, "%s\n", &a);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%s\n", a);
	fclose(f);
	*/