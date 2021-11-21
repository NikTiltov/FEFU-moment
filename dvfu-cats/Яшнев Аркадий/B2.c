#include <stdio.h>
#include <stdlib.h>

//ЫЙЙЙЯЯ это будет долго....
//На самом-то деле задачка не особо сложная
//Просто долгая и унылая

#define MAX_SIZE 16
#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define INPUT_OUTPUT_SETTING_UP \
    FILE *input  = fopen("input.txt", "r"), \
         *output = fopen("output.txt", "w");
#define CLOSING_FILES fclose(input); fclose(output);

typedef struct ultra_long {
    unsigned short num[MAX_SIZE];
    size_t length;
} ulong;

ulong *ulong_constructor(unsigned long long num);
void print_to_file(FILE *out, ulong *unum);
void assign(ulong *a, ulong const *b);
void add(ulong *res, ulong *a, ulong *b);
unsigned long long int gcd(long long int a, long long int b);
ulong *fib(unsigned long long n);

int main(int argc, char** argv) {
    INPUT_OUTPUT_SETTING_UP

    int n, k;
    fscanf(input, "%d%d", &n, &k);
    unsigned long long gcd_ = gcd(n, k);
    ulong *res = fib(gcd_);
    print_to_file(output, res);
    free(res);

    CLOSING_FILES
}

ulong *ulong_constructor(unsigned long long num) {
    //Почему я тут использовал указатели?
    //Зато пофлексил
    ulong *unum = malloc(sizeof(ulong));
    
    if(num == 0) { unum->length = 1; unum->num[0] = 0; }
    else unum->length = 0;
    while(num != 0) {
        unum->num[unum->length] = num % 10000;
        unum->length++;
        num /= 10000;
    }
    for(size_t i = unum->length; i < MAX_SIZE; i++)
        unum->num[i] = 0;
    return unum;
}

void print_to_file(FILE *out, ulong *unum) {
    fprintf(out, "%d", unum->num[unum->length-1]);
    for(int i = unum->length-2; i >= 0; i--)
        fprintf(out, "%04d", unum->num[i]);
}

//Я почему-то почти полностью уверен, что стоковый оператор присваивания тут бы сработал
//Но ладно сделал так сделал
void assign(ulong *a, ulong const *b) {
    a->length = b->length;
    for(int i = 0; i < a->length; i++) {
        a->num[i] = b->num[i];
    }
}

void add(ulong *res, ulong *a, ulong *b) {
    res->length = (a->length > b->length) ? a->length : b->length;
    unsigned short next_value = 0;
    for(int i = 0; i < res->length; i++) {
        unsigned short sum = a->num[i] + b->num[i] + next_value;
        res->num[i] = sum % 10000;
        next_value = sum / 10000;
        if(next_value) {
            if(i + 1 >= res->length) res->length++;
            res->num[i + 1] = next_value;
        }
    }
}

unsigned long long int gcd(long long int a, long long int b) {
    if(a == b) return a;
    long long int diff = llabs(a - b);
    return gcd(MIN(a, b), diff);
}

ulong *fib(unsigned long long n) {
    if(n == 0) return ulong_constructor(0);
    if(n == 2 || n == 1) return ulong_constructor(1);
    if(n == 3) return ulong_constructor(2);
    ulong *a = ulong_constructor(1),
          *b = ulong_constructor(2),
          *c = ulong_constructor(0);
    for(int i = 3; i < n; i++) {
        add(c, a, b);
        assign(a, b);
        assign(b, c);
    }
    free(a); free(c);
    return b;
}

//Она чуть более, чем полностью упарывается в длинную арифметику
//Чтобы все это объяснить лучше чекнуть презентацию по асд чесслово
//Я это расписывать не буду
