#include <stdio.h>

int main(int argc, char** argv) {
    long long n, counter = 0;
    scanf("%lld", &n);
    for(long long a = 1; a < n/3 + 1; a++) {
        counter += ((n-a)/2 + 1 - a);
    }
    printf("%lld", counter);
}
