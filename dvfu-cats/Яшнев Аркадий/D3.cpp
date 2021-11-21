#include <fstream>
#include <iomanip>
#include <cmath>

#define prec(n) setprecision(n)
typedef std::pair<double, double> pdd;

using namespace std;

pdd quad_equation(double a, double b, double c);

//Ой вот эта задачка мне тоже понравилась
//Я как раз тут закончил со своей библой по линалу
//И решил не совершая тех же горьких ошибок сделать функцию
//Если бы я ее на следующий день в библу запихивал

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double a, b, c;
    fin >> a >> b >> c;
    
    //Трай/Кеч тут неспроста
    //У нас при вычислении этого уравнения может бы две ошибки
    //Вывести -1 я считаю просто отвратительным тоном
    //Т.к. это технически валидный вывод для этой функции
    //Просто конкретно в данном использовании его не перепутаешь но если выйти за его рамки то мама родная....
    //
    //Да мне интересна эта задача ибо тут поднимается хуевая обработка ошибок в плюсах
    //Я дебажил некоторые свои проекты часамии из-за отсутствия нормального обработчика ошибок имею право
    try {
        auto res = quad_equation(a, b, c);
        fout << prec(4) << res.first << " " << prec(4) << res.second;
    } catch(domain_error &de) {
        fout << -1;
    }
    
    fin.close();
    fout.close();
}

pdd quad_equation(double a, double b, double c) {
    if(a == 0) {
        if (b == 0) throw domain_error("Do you even have an equation?");
        else return make_pair(-c / b, -c / b);
    }

    double D = b * b - 4 * a * c;

    if(D < 0)       throw domain_error("Discriminant is less than 0!");
    else if(D == 0) return make_pair(-b/(2*a), -b/(2*a));
    else {
        double x1 = (-b + sqrt(D)) / (2 * a), x2 = (-b - sqrt(D)) / (2 * a);
        return make_pair(max(x1, x2), min(x1, x2));
    }
}
