#include <fstream>
#include <vector>

using std::pair;

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    size_t N; fin >> N;
    std::vector<pair<int, size_t>> arr(N);

    for(size_t i = 0; i != N; ++i) {
        fin >> arr[i].first;
        arr[i].second = i;
    }

    for(size_t i = N - 2; i != SIZE_MAX; --i) {
        size_t j = i + 1;
        while(j != N && arr[i].first >= arr[j].first) {
            if(j == arr[j].second) {
                j = i;
                break;
            }
            j = arr[j].second;
        }
        arr[i].second = j;
    }

    for(size_t i = 0; i != N; ++i) {
        fout << arr[arr[i].second].first << " ";
    }
}
