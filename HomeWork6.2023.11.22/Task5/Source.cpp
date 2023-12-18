#include <stdio.h>
#include <string.h>

char* findSentenceWithMostWords(const char* text) {
    char* sentence;
    int maxWordCount = 0;
    char* result = NULL;
    sentence = strtok(text, ".");
    while (sentence != NULL) {
        char* word;
        int wordCount = 0;
        word = strtok(sentence, " ");
        while (word != NULL) {
            wordCount++;
            word = strtok(NULL, " ");
        }
        if (wordCount > maxWordCount) {
            maxWordCount = wordCount;
            result = sentence;
        }
        sentence = strtok(NULL, ".");
    }
    return result;
}

int main() {
    char inputText[] = "������ ������. ��� ������ ����������� � ����� ��� ����� �������. ������ �����������.";
    char* result = findSentenceWithMostWords(inputText);
    printf("����������� � ���������� ����������� ����: %s\n", result);
    return 0;
}