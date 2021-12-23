#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

#define v(c) is_vowel((c))

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    char words[100][300], num[4];
    size_t counter[100] = {0}, size, max = 0;
    fgets(num, 4, fin); size = strtoull(num, NULL, 10);

    for(size_t i = 0; i != size; ++i) {
        fgets(words[i], 300, fin);
        size_t len = strlen(words[i]);
        char tmp[260]; for(size_t j = 0; j != 260; tmp[j++] = 'b');
        memcpy(tmp + 1, words[i], sizeof(char) * len);
        if(tmp[len] == '\n') tmp[len] = 'b'; tmp[259] = '\0';
        for(size_t j = 0; j < len - 1; ++j) {
            if(v(words[i][j]) && v(words[i][j + 1])
            && (j == 0 || !v(words[i][j - 1])) && !v(words[i][j + 2])) {
                ++counter[i];
            }
        }
        if(counter[i] > max) max = counter[i];
    }

    for(size_t i = 0; i != size; ++i) {
        if(counter[i] == max) fprintf(fout, "%s", words[i]);
    }

    fclose(fin);
    fclose(fout);
}
