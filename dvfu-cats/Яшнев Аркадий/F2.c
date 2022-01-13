#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    char words[100][260], num[4];
    size_t counter[100] = {0}, size, max = 0;
    fgets(num, 5, fin); size = strtoull(num, NULL, 10);

    for(size_t i = 0; i != size; ++i) {
        fgets(words[i], 260, fin);
        size_t len = strlen(words[i]);

        for(size_t j = 0; j < len - 1; ++j) {
            if(is_vowel(words[i][j]) && is_vowel(words[i][j + 1]) &&
            (j == 0 || !is_vowel(words[i][j - 1])) && !is_vowel(words[i][j + 2])) {
                ++counter[i];
            }
        }

        if(counter[i] > max) max = counter[i];
    }

    for(size_t i = 0; i != size; ++i) {
        if(counter[i] == max) fprintf(fout, "%s", words[i]);
    }

    fclose(fin); fclose(fout);
}
