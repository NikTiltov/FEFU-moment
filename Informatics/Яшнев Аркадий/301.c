#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double D, x1, x2;
    D = sqrt((b * b) - (4 * a * c));
    x1 = ((-b + D) / (2 * a));
    x2 = ((-b - D) / (2 * a));
    if(D > 0)
        printf("%lf %lf", x1, x2);
    else if(D == 0)
        printf("%lf", (-b / (2 * a)));
}
