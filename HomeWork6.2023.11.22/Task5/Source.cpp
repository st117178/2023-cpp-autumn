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
    char inputText[] = "ѕример текста. Ёто второе предложение с более чем трем€ словами. “ретье предложение.";
    char* result = findSentenceWithMostWords(inputText);
    printf("ѕредложение с наибольшим количеством слов: %s\n", result);
    return 0;
}