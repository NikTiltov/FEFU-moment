#include <stdio.h>

int arr_sum(int const *start, int const *end);
int calculate_bday(int b_day, int b_month, int d_day, int d_month, int d_year);
int is_leap(int year);

int main(int argc, char** argv) {
    int b_days, b_month, d_day, d_month, d_year;
    scanf("%u%u%u%u%u", &b_days, &b_month, &d_day, &d_month, &d_year);
    printf("%d", calculate_bday(b_days, b_month, d_day, d_month, d_year));
}

int arr_sum(int const *start, int const *end) {
    int res = 0;
    for(int const *i = start; i != end; res += *i, i++);
    return res;
}

int is_leap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int calculate_bday(int b_day, int b_month, int d_day, int d_month, int d_year) {
    int const month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int const * const m_begin = month;
    //Для удобного обращения к элементам массива/указателям
    int b_ptr = b_month - 1, d_ptr = d_month - 1;
    //Количество дней прошедших с начала года
    int b_day_offset = arr_sum(m_begin, m_begin + b_ptr) + b_day;
        b_day_offset += (is_leap(d_year) && b_month > 2) ? 1 : 0;
    int d_day_offset = arr_sum(m_begin, m_begin + d_ptr) + d_day;
        //d_day_offset += (is_leap(d_year) && d_month > 2) ? 1 : 0;

    if(b_month == 2 && b_day == 29) {
        //Следующий високосный год
        int next_leap_year = d_year;
        while(!is_leap(next_leap_year)) next_leap_year++;
        //Если текущий год не високосный нам нужно все это обработать по умному
        //К сожалению мозгов у меня нет поэтому я произведу кучу операций которые
        //Сам не понимаю
        if(next_leap_year != d_year) {
            b_day_offset += 365 * (next_leap_year - d_year); //Разница между текущим и високосным годом в днях
            return b_day_offset - d_day_offset;
        } else if(next_leap_year == d_year) {
            if((b_month == d_month && b_day < d_day) || b_month < d_month) {
                while(!is_leap(++next_leap_year));
                b_day_offset += 365 * (next_leap_year - d_year);
                return b_day_offset - d_day_offset;
            }
            else return b_day_offset - d_day_offset;
        }
    }

    //Если дата уже больше чем дата дня рождения
    //то нужно переместить оффсет на год
    if((b_month == d_month && b_day < d_day) || b_month < d_month) {
        b_day_offset += 365;
        if((is_leap(d_year) && d_month <= 2) || (is_leap(d_year + 1) && b_month > 2))
            b_day_offset += 1;
    }

    //Возвращаем разницу между количеством дней от начала года для дня рождения
    //и количеством дней от начала года для даты
    return b_day_offset - d_day_offset;
}
