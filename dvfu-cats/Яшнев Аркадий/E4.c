#include <stdio.h>

int main() {
    FILE *fin  = fopen("input.txt", "r"),
            *fout = fopen("output.txt", "w");
    int max = -0x7fffffff, amount, cur;

    fscanf(fin, "%d", &amount);
    for(size_t i = 0; i != amount; ++i) {
        fscanf(fin, "%d", &cur);
        max = (cur > max) ? cur : max;
    }

    fprintf(fout, "%d", max);

    fclose(fin); fclose(fout);
}
