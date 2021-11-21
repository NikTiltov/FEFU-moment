#include <stdio.h>

int main() {
    int a, b, c;
    FILE *input_file  = fopen("input.txt", "r"),
         *output_file = fopen("output.txt", "w");
    fscanf(input_file, "%d%d%d", &a, &b, &c);
    fclose(input_file);
  
    //Ну и срань
    //Кто вообще это говно писал?
    fprintf(output_file, "%d", (((((a >> 2) << 4) ^ b) << 1) | c) & 1073741823);
    fclose(output_file);
}
