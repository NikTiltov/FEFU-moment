#include <stdio.h>

typedef unsigned long long ull;

void fib(FILE *fout, int n) {
    //Тут все просто
    //Копируем функцию с тырнета/Б2 и вуаля
    //Надо только все это высрать в файл
    if(n == 0) return;
    ull a = 0, b = 1, c = 0;
    fprintf(fout, "%d", 0);
    for(int i = 1; i < n; i++) {
        fprintf(fout, " %llu", b);
        c = a + b;
        a = b; b = c;
    }
}

int main(int argc, char** argv) {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");
    int n;
    fscanf(fin, "%d", &n);
    fib(fout, n);
    fclose(fin); fclose(fout);
    return 0;
}
