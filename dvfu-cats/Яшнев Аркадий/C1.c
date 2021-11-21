#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    int n, *in, res = 0;
    char c;
    fscanf(fin, "%d", &n);
    in = (int*) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) fscanf(fin, "%d", &in[i]);
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%c", &c);
        //Все просто если в пару числу идет плюс то мы его прибавляем
        //Если нет то чиллим
        if(c == '+')
            res += in[i];
        //Не обращайте внимания костыль
        else if(c == ' ' || c == '\n')
            i--;
    }
    fprintf(fout, "%d", res);

    free(in);
    fclose(fin); fclose(fout);
}
