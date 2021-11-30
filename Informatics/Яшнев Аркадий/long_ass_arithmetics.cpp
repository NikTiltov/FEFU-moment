#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Здесь все обязательные задачи по асд
//Залил в один файл чтобы не коммитить миллион файлов
//Просто поменяйте операцию на нужную в мэине

class BigInt {
    std::vector<size_t> num;
    size_t size;
public:
    static size_t const BASE = 1e9;

    BigInt() {
        num.resize(2, 0);
        size = 1;
    }
    BigInt(long long n);

    [[nodiscard]]
    inline size_t len() const { return size; }

    //TODO: Move tmp ops to private
    void add(BigInt const &other);
    void mul(BigInt const &other);
    void div(long long n);
    void mod(long long n);

    BigInt &operator+=(BigInt const &other);
    BigInt &operator*=(BigInt const &other);

    BigInt &operator/=(long long n);
    BigInt &operator%=(long long n);

    friend std::ostream &operator<<(std::ostream &out, BigInt const &n);
    friend std::istream &operator>>(std::istream &in, BigInt &n);
};


BigInt operator+(BigInt left, BigInt const &right);
BigInt operator*(BigInt left, BigInt const &right);

BigInt operator/(BigInt left, long long right);
BigInt operator%(BigInt left, long long right);

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    BigInt a;
    long long b;
    in >> a >> b;
    out << a / b << "\n" << a % b;
}

BigInt::BigInt(long long n) {
    num.resize(2, 0); size = 0;
    if(!n) {
        size = 1;
    }
    while(n) {
        if(num[num.size() - 1]) num.push_back(0);
        num[size++] = n % BASE;
        n /= BASE;
    }
}

std::ostream &operator<<(std::ostream &out, BigInt const &n) {
    out << n.num[n.size - 1];
    for(long long i = n.size - 2; i >= 0; --i) {
        out << std::setfill('0') << std::setw(9) << n.num[i];
    }

    return out;
}

std::istream &operator>>(std::istream &in, BigInt &n) {
    char input;
    while((input = (char) in.get()) &&
           input != '\n' && input != ' ' && !in.eof()) {
        for(size_t i = n.size - 1; i != SIZE_MAX; --i) {
            n.num[i + 1] += (n.num[i] * 10 / BigInt::BASE);
            n.num[i] = (n.num[i] * 10) % BigInt::BASE;
        }

        n.num[0] += input - '0';
        if(n.num[n.size]) {
            if(n.size >= n.num.size() - 1) n.num.push_back(0);
            ++n.size;
        }
    }

    return in;
}

void BigInt::add(BigInt const &other) {
    if(size < other.size) {
        num.resize(other.num.size());
        size = other.size;
    }

    size_t end = (size > other.size) ? other.size : size;
    for(size_t i = 0; i != end; ++i) {
        num[i] += other.num[i];
        num[i + 1] += num[i] / BASE;
        if(num[i] / BASE) {
            if(i + 1 >= size) {
                if(num.size() - 1 >= size) {
                    num.push_back(0);
                }
                ++size;
            }
        }
        num[i] %= BASE;
    }
}

void BigInt::mul(BigInt const &other) {
    BigInt res;

    for(size_t i = 0; i < size; ++i) {
        for(long long j = 0; j < other.size; ++j) {
            if(i + j >= res.size) {
                ++res.size;
                if (i + j >= res.num.size() - 1) {
                    res.num.push_back(0);
                }
            }
            res.num[i + j] += num[i] * other.num[j];
            for(size_t l = 0; l < res.size - 1; ++l) {
                res.num[l + 1] += res.num[l] / BASE;
                res.num[l] %= BASE;
            }
        }
    }

    if(!res.num[res.size - 1]) {
        res.size = 1;
        res.num.resize(2, 0);
    }

    *this = res;
}

void BigInt::div(long long n) {
    size_t carry = 0;
    for(long long i = size - 1; i >= 0; --i) {
        size_t cur = num[i] + carry * BASE;
        num[i] = cur / n;
        carry = cur % n;

        if(!num[i]) {
            --size;
            num.pop_back();
        }
    }
}

void BigInt::mod(long long n) {
    size_t carry = 0;
    for(long long i = size - 1; i >= 0; --i) {
        size_t cur = num[i] + carry * BASE;
        num[i] = cur / n;
        carry = cur % n;

        if(!num[i]) {
            --size;
            num.pop_back();
        }
    }

    *this = BigInt(carry);
}

BigInt &BigInt::operator+=(BigInt const &other) {
    this->add(other);
    return *this;
}

BigInt operator+(BigInt left, BigInt const &right) {
    return left += right;
}

BigInt &BigInt::operator*=(BigInt const &other) {
    this->mul(other);
    return *this;
}

BigInt operator*(BigInt left, BigInt const &right) {
    return left *= right;
}


BigInt &BigInt::operator/=(long long n) {
    this->div(n);
    return *this;
}


BigInt operator/(BigInt left, long long right) {
    return left /= right;
}

BigInt &BigInt::operator%=(long long n) {
    this->mod(n);
    return *this;
}

BigInt operator%(BigInt left, long long right) {
    return left %= right;
}
