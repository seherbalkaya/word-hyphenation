#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int isVowel(char);

int main() {
    char word[50] = "", wordHyp[100] = "";
    int i = 0;
    int count = 0;
    printf("Enter a word for hyphenation:\n");
    scanf("%s", word);

    for (i = 0; word[i] != '\0'; i++) {
        if (wordHyp[i] == '\0') {
            wordHyp[i] = word[i];
            count += 1;
        } else {
            wordHyp[count] = word[i];
            count += 1;
        }
        if (isVowel(word[i]) == 1) {
            if (isVowel(word[i + 1]) == 1) {
                wordHyp[count] = '-';
                count += 1;
            } else if (isVowel(word[i + 2]) == 1) {
                wordHyp[count] = '-';
                count += 1;
            } else if (isVowel(word[i + 3]) == 1) {
                wordHyp[count] = word[i + 1];
                count += 1;
                wordHyp[count] = '-';
                count += 1;
                i++;
            } else if (isVowel(word[i + 4]) == 1) {
                wordHyp[count] = word[i + 1];
                wordHyp[count + 1] = word[i + 2];
                wordHyp[count + 2] = '-';
                count += 3;
                i += 2;
            }
        }
    }
    printf("%s\n", wordHyp);
    return 0;
}


int isVowel(char c) {

    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
    return 0;
}
