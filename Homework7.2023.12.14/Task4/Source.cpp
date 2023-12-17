#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>

int Fstrcmp(char* a, char* b);

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";
	char b[255] = "";
	fscanf(f, "%s %s\n", &a, &b);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%d\n", Fstrcmp(a, b));
	fclose(f);
	return EXIT_SUCCESS;
}

int Fstrcmp(char* a, char* b)
{
	while (*a && (*a == *b))
	{
		a++;
		b++;
	}
	if (*(char*)a - *(char*)b < 0)
	{
		return -1;
	}
	if (*(char*)a - *(char*)b > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return EXIT_SUCCESS;
}