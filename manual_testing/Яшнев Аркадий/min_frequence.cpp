#include <fstream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

//Это много библиотек для такого простого алгоритма

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    std::string str{};
    std::map<char, size_t> map;
    std::getline(fin, str);
    for(auto &it : str) {
        if(map.count(it)) map[it]++;
        else map[it] = 1;
    }

    std::vector<std::pair<size_t, char>> reversed;
    reversed.reserve(map.size());
    for(auto &it : map) {
        reversed.emplace_back(it.second, it.first);
    }

    std::sort(reversed.begin(), reversed.end());

    for(auto &it : reversed) {
        fout << it.second << "%: " << ((double) (100 * it.first) / str.size()) << '\n';
    }

    fout << "Minimal double length: " << ceil(log2((double) map.size()));
}
