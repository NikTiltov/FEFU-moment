#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

typedef struct pair {
    long long int X, Y;
} Pair;

Pair find_xy(ull A, ull B);
void function_for_testing();

int main(int argc, char *argv[]) {
    if(argc == 2 && !strcmp("TEST_BUILD", argv[1])) {
        function_for_testing();
    } else {
        FILE *input = fopen("input.txt", "r"), *output = fopen("output.txt", "w");
        ull A, B;
        fscanf(input, "%llu%llu", &A, &B);
        Pair out = find_xy(A, B);
        if(out.X != -1) fprintf(output, "%lld %lld", out.X, out.Y);
        else fprintf(output, "-1");
        fclose(input);
        fclose(output);
    }
}

Pair find_xy(ull A, ull B) {
    Pair out;
    ull x = (A - B) / 2;
    if(B == (x ^ (A - x))) { out.X = x; out.Y = A - x; }
    else { out.X = -1; out.Y = -1; }
    return out;
}

void function_for_testing() {
    FILE *input           = fopen("input.txt", "r"),
            *output          = fopen("output.txt", "w"),
            *expected_output = fopen("expected_output.txt", "r");

    int NUMBER_OF_TESTS = 1;
    fscanf(input, "%d", &NUMBER_OF_TESTS);
    for(int i = 0; i < NUMBER_OF_TESTS; i++) {
        ull A, B;
        ull expected;
        fscanf(input, "%llu%llu", &A, &B);
        Pair out = find_xy(A, B);
        if(out.X != -1) fprintf(output, "%llu %llu\n", out.X, out.Y);
        else fprintf(output, "-1\n");
        fscanf(expected_output, "%llu", &expected);
        if(expected == -1) {
            if(out.X == expected) {
                fprintf(output, "%d test passed. Output: %lld. Expected: %lld.\n",
                        i+1, out.X, expected);
            } else {
                fprintf(output, "%d test failed. Output: %lld %lld. Expected: %lld.\n",
                        i+1, out.X, out.Y, expected);
            }
        } else {
            ull tmp = expected;
            fscanf(expected_output, "%llu", &expected);
            if(out.X == tmp && out.Y == expected) {
                fprintf(output, "%d test passed. Output: %lld %lld. Expected: %lld %lld.\n",
                        i+1, out.X, out.Y, tmp, expected);
            } else {
                fprintf(output, "%d test failed. Output: %lld %lld. Expected: %lld %lld.\n",
                        i+1, out.X, out.Y, tmp, expected);
            }
        }

    }

    fclose(input); fclose(output); fclose(expected_output);
}
