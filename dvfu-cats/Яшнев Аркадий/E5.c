#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    size_t size;
    fscanf(fin, "%lld", &size);

    int **snake = (int**) calloc(size, sizeof(int*));
    *snake = (int*) calloc(size * size, sizeof(int));
    for(size_t i = 1; i != size; ++i) snake[i] = snake[i - 1] + size;

    for(size_t i = 0; i != size; ++i) {
        for(size_t j = size - 1; j != SIZE_MAX; --j) {
            if(!(i % 2)) snake[i][j] = size * i + j + 1;
            else snake[i][j] = snake[i - 1][size - j - 1] + size;
        }
    }

    for(size_t i = 0; i != size; ++i) {
        for(size_t j = 0; j != size; ++j) {
            fprintf(fout, "%d ", snake[i][j]);
        }
        fprintf(fout, "\n");
    }

    free(*snake); free(snake);
    fclose(fin); fclose(fout);
}
