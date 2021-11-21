#include <fstream>

int main() {
    std::fstream input("input.txt"),
    output("output.txt", std::ofstream::out | std::ofstream::trunc);
  
    double n, m, k, l, ms, res = 0;
    input >> n >> m >> k >> l;
    
    //Скорость с которой плывет пчел
    ms = n / m;
    //Переводим минуты в секунды
    l *= 60;
    while(l >= m + k) {
        //Пока хватает времени на проплыв бассейна в одну сторону мы это время отнимаем
        l -= (m + k);
        res += n;
    }
    
    //Если у нас все же остается время на преодолении дистанции еще одного бассейна, то мы это делаем
    //Если нет, то просто доплываем оставшиеся секунды и добавляем к общему количеству метров
    res += (l > m && l < m + k) ? n : ms * l;
    output << (long long) res;
}
