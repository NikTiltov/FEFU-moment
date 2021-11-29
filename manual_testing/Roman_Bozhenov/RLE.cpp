#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    string unchanged;
    input >> unchanged;
    int count;
    for (int i = 0; i < unchanged.length();)
    {
        count = 1;
        if ((i + count) < unchanged.length()) {
            if (unchanged[i] == unchanged[i + count]) { // подсчёт повторяющихся символов
                while (unchanged[i] == unchanged[i + count] && (count < 127) && (i + count) < unchanged.length() + 1)
                {
                    count++;
                }
                output << count + 128 << unchanged[i];
                i += count;
            }
            else // подсчёт неповторяющихся символов
            {
                while (unchanged[i + count - 1] != unchanged[i + count] && (count < 127) && (i + count) < unchanged.length())
                {
                    count++;
                }
                output << count - 1;
                for (int k = i; k < i + count - 1; k++)
                    output << unchanged[k];
                i += count - 1;
            }
        }
        else
        {
            output << 1 << unchanged[i];
            i++;
        }
    }
}
