#include <stdio.h>
#include <stdlib.h>

//Так ору с этой задачи

typedef struct lamp {
    int dist;
    int radius;
} Lamp;

int max_intersections(Lamp *lamps, int size);

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");
    int n;

    fscanf(fin, "%d", &n);
    Lamp lamps[n];
    for(int i = 0; i < n; i++)
        fscanf(fin, "%d%d", &lamps[i].dist, &lamps[i].radius);

    fprintf(fout, "%d", max_intersections(lamps, n));
}

int max_intersections(Lamp *lamps, int size) {
    int max = INT_MIN;
    //По сути мы считаем пересечения треугольников
    //Но есть в этой задаче одна загвоздка
    //Если у нас два фонаря с дальностью в 1 стоят на соседних клетках программа это не засчитает
    //Поэтому единственным логичным решением в этой жизни остается удвоение точности улицы
    //Для максимально точного подсчета пересечения фонарей
    
    //Касательно самой функции мы просто для каждой клетки считаем сколько фонарей на нее светит
    //Все хаха фани кончилось идем к следующим задачам
    for(int i = 0; i <= 200; i++) {
        int cur = 0;
        for(int j = 0; j < size; j++)
            if(lamps[j].dist * 2 - lamps[j].radius * 2 < i &&
               lamps[j].dist * 2 + lamps[j].radius * 2 > i)
                cur++;
        if(cur > max) max = cur;
    }

    return max;
}
