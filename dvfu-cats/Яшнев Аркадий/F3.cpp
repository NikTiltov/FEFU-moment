#include <fstream>
#include <string>

using std::ifstream, std::ofstream, std::string;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string text{}, S1{}, S2{};
    getline(fin, text);
    getline(fin, S1);
    getline(fin, S2);

    if(S2.find(S1) != string::npos) {
        fout << -1;
    } else {
        size_t pos;
        while((pos = text.find(S1)) != string::npos) {
            text.replace(pos, S1.length(), S2);
        }
        fout << text;
    }


    fin.close(); fout.close();
}
