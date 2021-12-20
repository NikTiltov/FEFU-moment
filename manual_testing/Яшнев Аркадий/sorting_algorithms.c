#include <stdio.h>
#include <windows.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

#define SIZE 100

// ----------UTILITY----------

#define SWAP(a, b) do { \
    typeof(a) tmp = a;  \
    a = b;              \
    b = tmp;            \
} while(0)

int64_t GetTicks();
int *copy_array(int *arr, size_t size);

#define FILL_ARRAY_WITH(arr, size, val) do {                \
    for(size_t i = 0; i != (size); (arr)[i++] = (val));     \
} while(0)

// ----------SORTING ALGORITHMS----------

void bubble_sort(int *arr, size_t size);
void selection_sort(int *arr, size_t size);
void quick_sort(int *arr, int size);
void merge_sort(int *arr, int left, int right);

// ----------TIME MEASURING CONVENIENCE----------

#define MEASURE_TIME(arr, size, sort) do {                          \
    int *copy = copy_array(arr, size);                              \
    int64_t start = GetTicks();                                     \
    sort(copy, size);                                               \
    int64_t end = GetTicks();                                       \
                                                                    \
    printf("MEASURED TIME OF %s: %lluns\n", #sort, end - start);    \
    for(size_t i = 0; i != (size); printf("%d ", copy[i++]));       \
    printf("\n");                                                   \
    free(copy);                                                     \
} while(0)

#define MEASURE_TIME_2(arr, size, sort) do {                        \
    int *copy = copy_array(arr, size);                              \
    int64_t start = GetTicks();                                     \
    sort(copy, 0, (size) - 1);                                      \
    int64_t end = GetTicks();                                       \
                                                                    \
    printf("MEASURED TIME OF %s: %lluns\n", #sort, end - start);    \
    for(size_t i = 0; i != (size); printf("%d ", copy[i++]));       \
    printf("\n");                                                   \
    free(copy);                                                     \
} while(0)

int main() {
    srand(time(NULL));
    FILE *fin  = fopen("input.txt", "r");

    size_t size;
    fscanf(fin, "%llu", &size);

    int *arr = (int*) calloc(size, sizeof(int));
    for(size_t i = 0; i != size; fscanf(fin, "%d ", &arr[i++]));

    MEASURE_TIME(arr, size, bubble_sort);
    MEASURE_TIME(arr, size, selection_sort);
    MEASURE_TIME(arr, size, quick_sort);
    MEASURE_TIME_2(arr, size, merge_sort);
    free(arr); fclose(fin);

    arr = (int*) calloc(SIZE, sizeof(int));

    FILL_ARRAY_WITH(arr, SIZE, rand() - 16000);
    MEASURE_TIME(arr, SIZE, bubble_sort);
    FILL_ARRAY_WITH(arr, SIZE, rand() - 16000);
    MEASURE_TIME(arr, SIZE, selection_sort);
    FILL_ARRAY_WITH(arr, SIZE, rand() - 16000);
    MEASURE_TIME(arr, SIZE, quick_sort);
    FILL_ARRAY_WITH(arr, SIZE, rand() - 16000);
    MEASURE_TIME_2(arr, SIZE, merge_sort);

    free(arr);
}

void bubble_sort(int *arr, size_t size) {
    int changed = 1;
    while(changed) {
        changed = 0;
        for(size_t i = 0; i != size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                SWAP(arr[i], arr[i + 1]);
                changed = 1;
            }
        }
    }
}

void selection_sort(int *arr, size_t size) {
    for(size_t i = 0; i < size - 1; ++i) {
        size_t min_pos = i, max_pos = i;
        for(size_t j = i + 1; j < size - i; ++j) {
            if(arr[j] < arr[min_pos]) min_pos = j;
            if(arr[j] > arr[max_pos]) max_pos = j;
        }

        if(i >= size - i) break;

        if(arr[i] > arr[min_pos]) SWAP(arr[i], arr[min_pos]);
        if(arr[size - i - 1] < arr[max_pos]) SWAP(arr[size - i - 1], arr[max_pos]);
    }
}

void quick_sort(int *arr, int size) {
    if(size < 2) return;

    int pivot = arr[size / 2];

    int l_cur, r_cur;
    for(l_cur = 0, r_cur = size - 1; ; l_cur++, r_cur--) {
        while(arr[l_cur] < pivot) l_cur++;
        while(arr[r_cur] > pivot) r_cur--;

        if(l_cur >= r_cur) break;

        SWAP(arr[l_cur], arr[r_cur]);
    }

    quick_sort(arr, l_cur);
    quick_sort(arr + l_cur, size - l_cur);
}

void merge_sort(int *arr, int left, int right) {
    if(left == right) return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    int *sorted = (int*) calloc(right + 1, sizeof(int));
    int l_cur = left, r_cur = mid + 1;
    for(int i = 0; i < right - left + 1; i++) {
        if(l_cur <= mid && r_cur <= right) {
            if(arr[l_cur] <= arr[r_cur]) sorted[i] = arr[l_cur++];
            else sorted[i] = arr[r_cur++];
        } else if(l_cur <= mid) sorted[i] = arr[l_cur++];
        else sorted[i] = arr[r_cur++];
    }
    for(int i = 0; i < right - left + 1; i++) arr[left + i] = sorted[i];

    free(sorted);
}

int64_t GetTicks() {
    LARGE_INTEGER ticks;
    QueryPerformanceCounter(&ticks);
    return ticks.QuadPart;
}

int *copy_array(int *arr, size_t size) {
    int *copy = (int*) calloc(size, sizeof(int));
    memcpy(copy, arr, size * sizeof(int));
    return copy;
}
