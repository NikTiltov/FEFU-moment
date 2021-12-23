#include <fstream>
#include <bitset>
#include <string>

using std::ifstream, std::ofstream;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, pwr = 1, num = 0; fin >> N;
    for(size_t i = 0; i != N; ++i, pwr *= 2);
    for(size_t i = 0; i != pwr; ++i) {
        fout << std::bitset<15>(num++).to_string().erase(0, 15 - N) << "\n";
    }

    fin.close(); fout.close();
}
