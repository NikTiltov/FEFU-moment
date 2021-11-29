#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//Я не буду врать
//Возможно это самый худший код из всего что я писал
//Пожалуйста не смотрите

void rle_archive(std::ifstream &fin, std::ofstream &fout);

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    rle_archive(fin, fout);

    fin.close(); fout.close();
}

void rle_archive(std::ifstream &fin, std::ofstream &fout) {
    std::string get{}; std::getline(fin, get);
    std::vector<int> prefix_sum(get.size()); prefix_sum[0] = 1;

    for(size_t i = 1; i < get.size(); i++) {
        prefix_sum[i] = prefix_sum[i - 1] * (get[i] == get[i - 1]) + 1;
        if(prefix_sum[i] == 256) {
            prefix_sum[i] = 1;
        }
    }

    int sequence_of_1 = 0;
    for(int i = 0; i < get.size(); i++) {
        if(prefix_sum[i] == 1) {
            if(i && prefix_sum[i - 1] != 1)
                fout << prefix_sum[i - 1] << get[i - 1];
            sequence_of_1++;
        }
        else if(sequence_of_1 > 2) {
            fout << -sequence_of_1 + 1 << get.substr(i - sequence_of_1, sequence_of_1 - 1);
            sequence_of_1 = 0;
        } else if(sequence_of_1 == 2) {
            fout << 1 << get[i - 2];
            sequence_of_1 = 0;
        } else {
            sequence_of_1 = 0;
        }
    }

    if(sequence_of_1 >= 2) {
        fout << -sequence_of_1 << get.substr(get.size() - sequence_of_1);
    } else if(sequence_of_1) {
        fout << 1 << *end(get);
    } else {
        fout << *(end(prefix_sum) - 1) << *(end(get) - 1);
    }
}
