#include <stdio.h>

int main() {
    int a, b, l, N, res = 0;
    scanf("%d%d%d%d", &a, &b, &l, &N);
    printf("%d", ((a * (N-1) + (b * (N-1) + l))) * 2 + a);
}
