#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    char Z[1000000], num[10];
    int ascii[128] = {0}, counter = 0;
    for(int i = 0; i != 1000000; i++) { Z[i] = 'Z'; }

    int N; fgets(num, 10, fin);
    N = strtol(num, NULL, 10);

    for(int i = 0; i != N; ++i) {
        char c, buf[10];
        int start, end;
        fscanf(fin, "%c %d %d", &c, &start, &end); fgets(buf, 10, fin);
        for(int j = start - 1; j != end; Z[j++] = c);
    }

    for(int i = 0; i != 1000000; ++i) {
        ascii[Z[i]] = 1;
    }

    for(int i = 0; i != 128; ++i) {
        if(ascii[i]) ++counter;
    }

    fprintf(fout, "%d", counter);

    fclose(fin); fclose(fout);
}
