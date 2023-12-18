#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>

std::string findmword(std::string& text) {
	std::string words[255];
	int counts[255] = { 0 };

	std::string word;
	int wordc = 0;

	size_t start = 0, end = text.find(' ');

	while (end != std::string::npos) {
		word = text.substr(start, end - start);

		for (char& c : word) {
			c = std::tolower(c);
		}

		int in = -1;
		for (int i = 0; i < wordc; ++i) {
			if (words[i] == word) {
				in = i;
				break;
			}
		}

		if (in != -1) {
			counts[in]++;
		}
		else {
			words[wordc] = word;
			counts[wordc] = 1;
			wordc++;

			if (wordc >= 255) {
				std::cout << "Mnogo slov.\n";
				return "";
			}
		}

		start = end + 1;
		end = text.find(' ', start);
	}

	word = text.substr(start);

	for (char& c : word) {
		c = std::tolower(c);
	}

	int in = -1;
	for (int i = 0; i < wordc; ++i) {
		if (words[i] == word) {
			in = i;
			break;
		}
	}

	if (in != -1) {
		counts[in]++;
	}
	else {
		words[wordc] = word;
		counts[wordc] = 1;
		wordc++;

		if (wordc >= 255) {
			std::cout << "Mnogo slov\n";
			return "";
		}
	}

	std::string mword;
	int maxc = 0;

	for (int i = 0; i < wordc; ++i) {
		if (counts[i] > maxc) {
			mword = words[i];
			maxc = counts[i];
		}
	}

	return mword;
}

int main() {
	std::ifstream fin("in.txt");
	std::string a = "";
	std::getline(fin, a);
	fin.close();

	std::ofstream fout("out.txt");
	fout << "Samoe chasto vstrechayshee slovo: " << findmword(a) << std::endl;
	fout.close();


	return 0;
}