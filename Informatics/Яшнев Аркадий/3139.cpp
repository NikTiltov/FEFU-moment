#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int get_value(char ch);
char get_char(int n);
void generate_key(int sum);
int get_key(std::string const &key, int P);

int main() {
    int N, P; std::cin >> N >> P; getchar();

    std::vector<bool> keys(P, false);

    for(int i = 0; i < N; i++) {
        std::string key{}; std::cin >> key;
        keys[get_key(key, P)] = true;
    }

    for(int i = 0; i < P && i < 876; ++i) {
        if(!keys[i]) {
            generate_key(i);
            return 0;
        }
    }

    std::cout << "Impossible";
}

void generate_key(int sum) {
    for(int i = 1; i < 30; i++) {
        if(!(i % 6)) {
            std::cout << "-";
            continue;
        }

        if(sum > 34) {
            std::cout << 'Z';
            sum -= 35;
        } else {
            std::cout << get_char(sum);
            sum -= sum;
        }
    }
}

char get_char(int n) {
    if(n >= 0 && n <= 9) {
        return (char) ('0' + n);
    } else {
        return (char) ('A' + n - 10);
    }
}

int get_value(char ch) {
    if(ch >= '0' && ch <= '9') {
        return ch - '0';
    } else {
        return ch - 'A' + 10;
    }
}

int get_key(std::string const &key, int P) {
    int key_val = 0;
    for(auto &it : key) {
        if(it != '-' && it != ' ') key_val += get_value(it);
    }

    return key_val % P;
}
