#include <stdio.h>

int bit(int a, int i) {
    return (a >> i) & 1;
}

int main(int argc, char *argv[]) {
    int A, B;
    scanf("%d%d", &A, &B);
    printf("%d", bit(A, B));
}
