#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    size_t size, counter1 = 0, counter2 = 0;
    fscanf(fin, "%llu", &size);

    int *wall = (int*) calloc(size + 2, sizeof(int)),
        *first = (int*) calloc(size, sizeof(int)),
        *second = (int*) calloc(size, sizeof(int));
    for(size_t i = 1; i != size + 1; ++i) {
        fscanf(fin, "%d", &wall[i]);
        first[i - 1] = wall[i]; second[i - 1] = wall[i];
    }

    wall[0] = wall[1] - 1;
    wall[size + 1] = wall[size] - 1;

    for (int i = 0; i < size; ++i) {
        if (i % 2) {
            first[i] = max(wall[i + 1], max(wall[i], wall[i + 2]) + 1);
        } else {
            second[i] = max(wall[i + 1], max(wall[i], wall[i + 2]) + 1);
        }
        
        counter1 += first[i];
        counter2 += second[i];
    }
    
    if (counter1 < counter2) {
        for (int i = 0; i < size; ++i) {
            fprintf(fout, "%d ", first[i]);
        }
    } else {
        for (int i = 0; i < size; ++i) {
            fprintf(fout, "%d ", second[i]);
        }
    }

    free(wall); free(first); free(second);
    fclose(fin); fclose(fout);
}
