#include <stdio.h>
#include <ctype.h>
int main() {
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0; // Flag to indicate whether we are inside a word
    printf("Enter text (Ctrl+D to end on Unix/Linux, Ctrl+Z on Windows):\n");
    while ((ch = getchar()) != EOF) {
        charCount++;
        if (ch == '\n') {
            lineCount++;
        }
        if (isspace(ch)) {
            inWord = 0;
        } else {
            if (!inWord) {
                wordCount++;
                inWord = 1; // Set the flag to indicate that we are inside a word
            }
        }
    }
    printf("\nCharacter count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);
    printf("Line count: %d\n", lineCount);
    return 0;
}
