#include <iostream>
 
using std::cin;
using std::cout;
 
int main(int argc, char** argv) {
    float i_want_to_die;
    cin >> i_want_to_die;
    
    //Стандарт указывает, что при нуле двоичный порядок должен быть равен нулю
    //Что на практике, конечно же, не так
    if(i_want_to_die == 0) { cout << 0; return 0; }
    
    //Обработка денормализованных чисел
    //Их нельзя высчитать вместе с остальными из-за их представления
    else if(i_want_to_die < 1e-38 && i_want_to_die > -1e-38) { cout << -126; return 0; }
    
    //Тут я беру адрес памяти по которому находится наше число и привожу его явно в инт
    //Т.к. битовые операции с числами с плавающей точкой запрещены
    int a = *(int*)&i_want_to_die;
    a >>= 23;
    a &= 0xff;
    cout << a - 127;
}
