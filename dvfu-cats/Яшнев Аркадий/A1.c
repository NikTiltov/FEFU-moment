#include <stdio.h>

int main() {
    int n = 0, i = 0;
    scanf("%d%d", &n, &i);
    printf("%d", n | (1 << i));
}
