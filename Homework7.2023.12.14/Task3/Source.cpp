#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>

char* Fsubstr(char* a, int st, int end);

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";
	int b = 0;
	int c = 0;
	fscanf(f, "%s %d %d\n", &a, &b, &c);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%s\n", Fsubstr(a, b, c));
	fclose(f);
	return EXIT_SUCCESS;
}

char* Fsubstr(char* a, int st, int end)
{	
	for (int i = 0; i <= end - 1; i++)
	{
		a[i] = a[st + i];
	}
	a[end] = NULL;
	return a;
}