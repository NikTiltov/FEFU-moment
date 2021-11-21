#include <stdio.h>

int main(int argc, char** argv) {
    unsigned int x, k;
    FILE *input  = fopen("input.txt", "r"),
         *output = fopen("output.txt", "w");
    fscanf(input, "%u%u", &x, &k);
    fclose(input);
    
    //Мини костыль по причине неопределенного поведения
    if(k > 32) x = 0;
  
    fprintf(output, "%u", ((x >> k) & 1));
    fclose(output);
}
