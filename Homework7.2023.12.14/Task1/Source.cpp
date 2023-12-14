#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

void Fstrcat(char* a, char* b);

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");
	
	char a[255] = "";
	char b[255] = "";
	fscanf(f, "%s %s\n", &a, &b);
	fclose(f);
	
	Fstrcat(a, b);
	f = fopen("out.txt", "w");
	fprintf(f, "%s\n", a);
	fclose(f);
	printf("%s", a);
	return EXIT_SUCCESS;
}

void Fstrcat(char* a, char* b)
{
	while (*a != '\0')
	{
		*a++;
	}
	while (*b != '\0')
	{
		*a = *b;
		*a++;
		*b++;
	}
}