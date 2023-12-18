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
	fprintf(f, "Count words:%d\n", slova(a));

	char* sen = strtok(a, ".!?");
	int maxWords = 0;
	char* maxsen = nullptr;

	while (sen != nullptr) {
		int words = slova(sen);
		if (words > maxWords) {
			maxWords = words;
			maxsen = sen;
		}

		sen = strtok(nullptr, ".!?");
	}

	if (maxsen != nullptr) {
		fprintf(f, "Sentence with max words: %s\n", maxsen);
	}
	else {
		fprintf(f, "Pysto\n");
	}

	fclose(f);

	return EXIT_SUCCESS;
}

int slova(char* a) {
	int count = 0;
	int i = 0;
	int len = strlen(a);

	while (i < len && a[i] == ' ') {
		i++;
	}

	while (i < len) {
		if (a[i] == ' ') {
			count++;
			while (i < len && a[i] == ' ') {
				i++;
			}
		}
		else {
			i++;
		}
	}

	if (i > 0 && a[i - 1] != ' ') {
		count++;
	}

	return count;
}