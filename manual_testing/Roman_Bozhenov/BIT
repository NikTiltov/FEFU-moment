#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
  char a; int ch, t, int_a;
  ch = 0;
  cin >> a; int_a = int(a);
  for (int i = 1; i < 7; i++) {
    if (int_a % 2 == 1) {
      ch ++;
    }
    int_a = int(a) >> 1;
  }
  if (ch % 2 == 0) {
    t = int(a);
  }
  else t = int(a) + 128;
  cout << bitset<8>(t) << endl;
}

/*
вывод: восемь битов, т.к. мне было лень гуглить как заставить ide выводить символы из расширенной таблицы ascii
*/
