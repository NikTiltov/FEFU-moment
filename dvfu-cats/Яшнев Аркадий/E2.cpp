#include <fstream>
#include <map>

using namespace std;

//А тут я Илью буллил

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    size_t size; fin >> size;
  
    //Задача по сути своей частотный словарь из асд
    //Так что мы можем тупо посчитать сколько раз встретилась та или иная цифра
    map<int, int> m;
    for(int i = 0; i != size; i++) {
        int in; fin >> in;
        m[in]++;
    }
    
    for(auto &it : m) {
        fout << it.first << " " << it.second << "\n";
    }
}
