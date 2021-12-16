#include <stdio.h>

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");
    char word[16], guess; size_t i, len; int guessed[15] = { 0 };

    for(i = 0; (word[i] = (char) getc(fin)) != '\n'; ++i);
    word[i] = '\0'; len = i;
    while((guess = (char) getc(fin)) != EOF) {
        for(i = 0; i != len; ++i) {
            if(guess == word[i]) guessed[i] = !guessed[i];
        }
    }

    for(i = 0; i != len; ++i) {
        fprintf(fout, "%c", guessed[i] ? word[i] : '.');
    }

    fclose(fin); fclose(fout);
}
