#include <stdio.h>

void shenanigans_with_cube(FILE *fout, int n);

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");
    int n; 
    
    fscanf(fin, "%d", &n);
    shenanigans_with_cube(fout, n);

    fclose(fin); fclose(fout);
}

void shenanigans_with_cube(FILE *fout, int n) {
    //Честно я даже пытаться не буду это объяснить
    //https://imcs.dvfu.ru/cats/main.pl?f=problem_text;cid=608541;cpid=613920;explain=1;sid=
    //Вот ссыль ковыряйтесь сами
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int l = 1; l <= n; ++l) {
                fprintf(fout, "%d ", 1 + (i + j + l) % n);
            }
            fprintf(fout, "\n");
        }
    }
}
