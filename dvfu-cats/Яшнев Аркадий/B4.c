#include <stdio.h>

#define INPUT_OUTPUT_SETTING_UP \
    FILE *input  = fopen("input.txt", "r"), \
    *output = fopen("output.txt", "w");
#define CLOSING_FILES fclose(input); fclose(output);

int main(int argc, char** argv) {
    INPUT_OUTPUT_SETTING_UP
    
    int n, sum = 0, in;
    fscanf(input, "%d", &n);
    for(int i = 0; i < n; i++) {
        fscanf(input, "%d", &in);
        sum += in;
    }
    fprintf(output, "%d", sum);

    CLOSING_FILES
}
