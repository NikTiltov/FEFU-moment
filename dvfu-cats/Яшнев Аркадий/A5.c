#include <stdio.h>

//Нахуя? Видимо, эту тайну Аркадий из прошлого унес с собой в могилу
#define INPUT_OUTPUT_SETTING_UP \
    FILE *input  = fopen("input.txt", "r"), \
         *output = fopen("output.txt", "w");
#define CLOSING_FILES fclose(input); fclose(output);

int main(int argc, char** argv) {
    INPUT_OUTPUT_SETTING_UP

    unsigned int hours, minutes, res = 60 * 24;
    fscanf(input, "%u%u", &hours, &minutes);
    minutes += hours * 60; res -= minutes;
    fprintf(output, "%d %d", res / 60, res % 60);

    CLOSING_FILES
}
