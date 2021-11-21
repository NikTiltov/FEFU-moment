#include <stdio.h>

#define INPUT_OUTPUT_SETTING_UP \
    FILE *input  = fopen("input.txt", "r"), \
         *output = fopen("output.txt", "w"); 
#define CLOSING_FILES fclose(input); fclose(output);

int main(int argc, char** argv) {
    INPUT_OUTPUT_SETTING_UP

    int n; double res = 0;
    fscanf(input, "%d", &n);
    for(int i = 0; i < n; i++) {
        double in;
        fscanf(input, "%lf", &in);
        res += in; 
    }
    fprintf(output, "%lf", res / n);

    CLOSING_FILES
}
