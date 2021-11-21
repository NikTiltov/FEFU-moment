#include <fstream>
#include <numeric>

//А вот тут явно видно насколько я устал от си
//Боже спасибо за еще один день с стл

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int a, b;
    fin >> a >> b;
    fout << std::gcd(a, b) << " " << std::lcm(a, b);
    
    fin.close();
    fout.close();
}
