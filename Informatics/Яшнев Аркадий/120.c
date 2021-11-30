#include <stdio.h>

#define INPUT_OUTPUT_SETTING_UP \
    FILE *input  = fopen("input.txt", "r"), \
         *output = fopen("output.txt", "w");
#define CLOSING_FILES fclose(input); fclose(output);

int main(int argc, char** argv) {
    int N;
    scanf("%d", &N);
    double res = 1, fact = 1;
    for(int i = 1; i <= N; i++) {
        fact *= i;
        res += (1./fact);
    }
    printf("%.5lf", res);
}
