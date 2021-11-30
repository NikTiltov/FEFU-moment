#include <stdio.h>

int main() {
    int seconds;
    scanf("%d", &seconds);
    int hours = (seconds / (60 * 60)) % 24, minutes = (seconds / 60) % 60;
    printf("%d:%02d:%02d", hours, minutes, seconds % 60);
}
