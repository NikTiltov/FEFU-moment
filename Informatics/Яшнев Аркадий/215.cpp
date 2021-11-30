#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

typedef std::pair<std::string, char> psc;

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt", std::fstream::trunc);

    int r, n;
    fin >> r >> n;

    std::vector<psc> patterns(r);

    for(auto &it : patterns) {
        std::getline(fin, it.first);
        std::getline(fin, it.first);
        char in; fin >> in;
        while(in == '\n') fin >> in;
        it.second = in;
    }

    std::sort(patterns.begin(), patterns.end(),
              [](psc const &p1, psc const &p2) -> bool
              { return p1.first.size() > p2.first.size(); });

    std::string cur_line{}; std::getline(fin, cur_line);
    for(int i = 0; i < n; i++) {
        std::getline(fin, cur_line);
        std::vector<std::string> strings(cur_line.size() + 1);

        for(size_t j = 1; j < cur_line.size() + 1; j++) {
            strings[j] = strings[j - 1] + cur_line[j - 1];
            for(auto &it : patterns)
                if (j >= it.first.size() &&
                    !cur_line.compare(j - it.first.size(), it.first.size(), it.first) &&
                    strings[j - it.first.size()].size() + 1 < strings[j].size())
                    strings[j] = strings[j - it.first.size()] + it.second;
        }

        fout << strings[cur_line.size()] << '\n';
    }
}
