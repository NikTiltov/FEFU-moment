#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll inverse_count(int const *arr, ll size);

int main() {
    FILE    *fin  = fopen("input.txt", "r"),
            *fout = fopen("output.txt", "w");
    int length, *input;

    fscanf(fin, "%d", &length);
    input = (int*) calloc(length, sizeof(int));
    for(int i = 0; i < length; i++) fscanf(fin, "%d", &input[i]);
    fprintf(fout, "%lld", inverse_count(input, length));

    free(input); fclose(fin); fclose(fout);
}

//Функция не видна в мэине, ибо вне контекста подсчета инверсий смысла имеет немного
void util_merge_sort(int *arr, ll left, ll right, ll *counter) {
    //Окей нужно немного объяснить идею мердж сорта
    //Мы рекурсивно разделяем массив напополам, пока получаемые массивы не имеют длину 1
    //Такой массив из одного элемента считаем отсортированным
    //
    //После этого мы собираем полученные массивы в некоем буфере следуя нехитрым шагам:
    //1. Если левый элемент меньше правого, то мы добавляем его в буфер, переключаясь на следующий
    //Элемент левой части массива
    //2. Если правый элемент меньше левого, то мы делаем с ним то же самое, но в этой функции есть небольшой твист
    //  2.5 Т.к. мы получили уже отсортированные массивы, то значит, что все элементы левого массива
    //      Встретившиеся до текущего и сам текущий элемент больше правого элемента
    //      И таким образом все они являются инверсиями
    //3. Копируем все остоавшиеся элементы массивов в буфер
    //4. Копируем буфер в оригинальынй массив
    
    if(left == right) return;

    ll mid = (left + right) / 2;
    util_merge_sort(arr, left, mid, counter);
    util_merge_sort(arr, mid + 1, right, counter);

    int *sorted = (int*) calloc(right + 1, sizeof(int));
    ll l_cur = left, r_cur = mid + 1;
    for(ll i = 0; i < right - left + 1; i++) {
        if(l_cur <= mid && r_cur <= right) {
            if(arr[l_cur] <= arr[r_cur]) 
                sorted[i] = arr[l_cur++];
            else {
                //По сути единственная строчка, что отличает эту функцию от нормального мердж сорта
                *counter += mid - l_cur + 1;
                sorted[i] = arr[r_cur++];
            }
        } else if(l_cur <= mid) 
            sorted[i] = arr[l_cur++];
        else 
            sorted[i] = arr[r_cur++];
    }
    for(ll i = 0; i < right - left + 1; i++) arr[left + i] = sorted[i];

    free(sorted);
}

//В этой функции я копирую весь массив
//Это необязательно, но мы же не хотим сортировать весь свой массив при подсчете инверсий, верно?
ll inverse_count(int const *arr, ll size) {
    int *tmp = (int*) calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) tmp[i] = arr[i];
    ll counter = 0;
    util_merge_sort(tmp, 0, size - 1, &counter);
    free(tmp);
    return counter;
}
