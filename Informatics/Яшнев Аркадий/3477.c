#include <stdio.h>

#define INPUT_OUTPUT_SETTING_UP \
    FILE *input  = fopen("input.txt", "r"), \
         *output = fopen("output.txt", "w");
#define CLOSING_FILES fclose(input); fclose(output);

int main(int argc, char** argv) {
    int h, a, b, counter = 1;
    scanf("%d%d%d", &h, &a, &b);
    for(int i = a; i < h; i += a, counter++) {
        i -= b;
    }
    printf("%d", counter);
}
