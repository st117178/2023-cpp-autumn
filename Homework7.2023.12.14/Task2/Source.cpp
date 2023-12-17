#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>

char* Fstrstr(char* a, char* b);

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";
	char b[255] = "";
	fscanf(f, "%s %s\n", &a, &b);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%s\n", Fstrstr(a,b));
	fclose(f);
	return EXIT_SUCCESS;
}


int par(char* a, char* b);
char* Fstrstr(char* a, char* b)
{

	while (*a != '\0')
	{
		if ((*a == *b) && par(a, b))
		{
			return a;
		}
		a++;
	}

	return NULL;
}

int par(char* a, char* b)
{
	while (*a && *b)
	{
		if (*a != *b) {
			return 0;
		}

		a++;
		b++;
	}

	return (*b == '\0');
}