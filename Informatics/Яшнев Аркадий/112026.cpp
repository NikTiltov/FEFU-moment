#include <iostream>

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    int counter = 0;
    for(int i = 0; i < str1.length(); i++)
        if(str1[i] != str2[i]) counter++;
    std::cout << counter;
}
