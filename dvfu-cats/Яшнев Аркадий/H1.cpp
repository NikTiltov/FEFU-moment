#include <deque>
#include <fstream>
#include <string>

using std::pair, std::deque, std::string;

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int arr[100000];
    string commands{};
    size_t n, m, l_cur = 0, r_cur = 1; fin >> n;
    for(size_t i = 0; i != n; fin >> arr[i++]);
    fin >> m >> commands;
    deque<pair<int, int>> window;
    window.emplace_back(arr[0], 0);

    for(size_t i = 0; i != m; ++i) {
        if(commands[i] == 'R') {
            while(!window.empty() && window.back().first < arr[r_cur]) {
                window.pop_back();
            }
            window.emplace_back(arr[r_cur], r_cur);
            ++r_cur;
        } else {
            if(!window.empty() && window.front().second == l_cur++) {
                window.pop_front();
            }
        }
        fout << window.front().first << " ";
    }

    fin.close(); fout.close();
}
