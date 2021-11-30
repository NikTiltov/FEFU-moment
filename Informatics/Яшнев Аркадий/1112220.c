#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

typedef struct pair {
    int X, Y;
} Pair;

Pair better_euclid_gcd(int a, int b);
void function_for_testing();

int main(int argc, char *argv[]) {
    if(argc == 2 && !strcmp("TEST_BUILD", argv[1])) {
        function_for_testing();
    } else {
        int A, B;
        scanf("%d%d", &A, &B);
        Pair out = better_euclid_gcd(A, B);
        if(out.X != -1) printf("%d %d", out.X, out.Y);
        else printf("-1");
    }
}

Pair better_euclid_gcd(int a, int b) {
    int counter = 0;
    Pair out;
    while(a != 0 && b != 0) {
        counter++;
        if(a > b) {
            a %= b;
            out.X = b;
        } else {
            b %= a;
            out.X = a;
        }
    }
    out.Y = counter;
    return out;
}

void function_for_testing() {
    FILE *input           = fopen("input.txt", "r"),
         *output          = fopen("output.txt", "w"),
         *expected_output = fopen("expected_output.txt", "r");

    int NUMBER_OF_TESTS = 1;
    fscanf(input, "%d", &NUMBER_OF_TESTS);
    for(int i = 0; i < NUMBER_OF_TESTS; i++) {
        int A, B;
        Pair expected;
        fscanf(input, "%d%d", &A, &B);
        Pair out = better_euclid_gcd(A, B);
        fscanf(expected_output, "%d%d", &expected.X, &expected.Y);
            if(out.X == expected.X && out.Y == expected.Y) {
                fprintf(output, "%d test passed. Output: %d %d. Expected: %d %d.\n",
                        i+1, out.X, out.Y, expected.X, expected.Y);
            } else {
                fprintf(output, "%d test failed. Output: %d %d. Expected: %d %d.\n",
                        i+1, out.X, out.Y, expected.X, expected.Y);
            }
    }
    fclose(input); fclose(output); fclose(expected_output);
}
