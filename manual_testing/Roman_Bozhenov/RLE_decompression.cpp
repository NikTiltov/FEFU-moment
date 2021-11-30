#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	string compressed, curr_str;
	input >> compressed;
	int count, gre;
	for (int i = 0; i < compressed.size();)
	{
		curr_str.clear();
		gre = compressed[i];
		while (47 < gre && gre < 58)
		{
			curr_str += compressed[i];
			i += 1;
			gre = compressed[i];
		}
		count = atoi(curr_str.c_str());
		if (count > 128) {
			for (int k = 0; k < count - 128; k++)
			{
				output << compressed[i];
			}
			i++;
		}
		else 
		{
			for (int k = 0; k < count; k++)
			{
				output << compressed[i + k];
			}
			i += count;
		}
	}
}
