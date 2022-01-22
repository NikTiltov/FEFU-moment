#include <stdio.h>

//По какой-то причине тесты на gcc и g++ валятся с RE
//На msvsc таких проблем нет
//Я не знаю как это фиксить

int to_num(char ch) {
    if(('0' <= ch && ch <= '9') || ch == 0) {
        return ch - '0';
    } else {
        return ch - 'A' + 10;
    }
}

char to_char(int num) {
    if(0 <= num && num <= 9) {
        return (char) ('0' + num);
    } else {
        return (char) ('A' + num - 10);
    }
}

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");
    int p, q; fscanf(fin, "%d %d", &p, &q);
    size_t cur_size = 1;
    while(fgetc(fin) != '\n');
    char num[6000] = { 0 }, in; for(size_t i = 0; i != 6000; num[i++] = '0');
    while((in = (char) fgetc(fin)) != EOF && in != '\n' && in != ' ') {
        for(size_t i = cur_size - 1; i != -1 (size_t); --i) {
            num[i + 1] = to_char(to_num(num[i + 1]) + to_num(num[i]) * p / q);
            num[i] = to_char((to_num(num[i]) * p) % q);
        }

        num[0] = to_char(to_num(num[0]) + to_num(in));
        for(size_t i = 0; i != cur_size; ++i) {
            num[i + 1] = to_char(to_num(num[i + 1]) + (to_num(num[i]) / q));
            num[i] = to_char(to_num(num[i]) % q);
            if(to_num(num[cur_size])) {
                ++cur_size;
            }
        }
    }

    num[cur_size] = '\0';
    for(size_t i = cur_size - 1; i != -1llu; --i) {
        fprintf(fout, "%c", num[i]);
    }

    fclose(fin); fclose(fout);
}
