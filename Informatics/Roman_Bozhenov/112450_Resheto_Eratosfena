#include <iostream>

using namespace std;

int main() {
    long long n, p = 2;
    cin >> n;
    long long* a = new long long[n + 1];
    for (int  i = 2; i <= n; i++) {
        a[i] = i;
    }
    for (p = 2; p < n + 1; p++) {
        if (a[p] != 0) {
            cout << a[p] << " ";
            if (p * p < n + 1) {
              for (long long i = p * p; i < n + 1; i += p) {
                  a[i] = 0;
              }
            }
        }
    }
}

//просто решето. алгоритм гуглиться за минуту
