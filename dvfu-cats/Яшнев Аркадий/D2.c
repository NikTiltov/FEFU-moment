#include <stdio.h>

//Функции стл для простых чисел умерли возвращаемся в си

int is_simple(int n) {
    if(n == 2) return 1;
    for(int i = 2; i <= n / 2 + 1; i++)
        if(!(n % i)) return 0;
    return 1;
}

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    int n, i = 1;
    fscanf(fin, "%d", &n);
    
    //Почему тут вайл???
    //Господи что я пишу иногда
    //
    //upd: попробовал без вайла оно почему-то сломалось
    //надо значит надо
    while(n != 0) {
        if(is_simple(++i)) {
            n--;
            fprintf(fout, "%d ", i);
        }
    }
    
    fclose(fin); fclose(fout);
}
