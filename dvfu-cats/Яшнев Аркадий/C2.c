#include <stdio.h>
#include <math.h>

double min(double x, double y) {
    return (x < y) ? x : y;
}

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    double x1, y1, x2, y2, x, y, centX, centY;
    double OM, MA, MB, MC, MD, r;

    fscanf(fin, "%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x, &y);

    centX = (x2 + x1) / 2;
    centY = (y2 + y1) / 2;

    OM = sqrt((pow((x - centX) / 2, 2) + (pow((y - centY) / 2, 2))));

    MA = sqrt((pow((x - x1) / 2, 2)) + (pow((y - y1) / 2, 2)));
    MB = sqrt((pow((x - x2) / 2, 2)) + (pow((y - y1) / 2, 2)));
    MC = sqrt((pow((x - x1) / 2, 2)) + (pow((y - y2) / 2, 2)));
    MD = sqrt((pow((x - x2) / 2, 2)) + (pow((y - y2) / 2, 2)));

    r = min(min(MA, MB), min(MC, MD));

    if(r < OM) {
        fprintf(fout, "CORNER");
    } else {
        fprintf(fout, "CENTER");
    }

    fclose(fout); fclose(fin);
    return 0;
}
