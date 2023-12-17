#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>

char* Fstrmult(char* a, int b);

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";
	int b = 0;

	fscanf(f, "%s %d\n", &a, &b);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%s\n", Fstrmult(a, b));
	fclose(f);
	return EXIT_SUCCESS;

}

char* Fstrmult(char* a, int b)
{
	int const len = strlen(a);
	int l = len;
	for (int i = 1; i < b; i++)
	{
		for (int j = 0; j < len; j++)
		{
			a[l] = a[j];
			l++;
		}
	}
	return a;
}