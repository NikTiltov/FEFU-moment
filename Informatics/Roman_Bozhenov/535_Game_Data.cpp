#include <iostream>

using namespace std;

int main() {
  int d, m;
  int a[36][15] = {0};
  a[30][2] = a[31][2] = a[31][4] = a[31][6] = a[31][9] = a[31][11]= 6;
  a[30][12] = -1; a[31][10] = -1;
  for (int i = 32; i < 35; i++){
    for (int j = 1; j < 16; j++) {
      a[i][j] = 6;
    }
  }
  for (int i = 1; i < 35; i++){
    for (int j = 13; j < 16; j++) {
      a[i][j] = 6;
    }
  }
  for (int i = 31; i > 0; i--) {
    for (int j = 12; j > 0; j--) {
      if (a[i][j] == 0) {
        if (a[i][j+1] == -1 || a[i][j+2] == -1 || a[i+1][j] == -1 || a[i+2][j] == -1) {
          a[i][j] = 1;
        }
        else if (a[i][j+1] > 0 && a[i][j+2] > 0 && a[i+1][j] > 0 && a[i+2][j] > 0) {
          a[i][j] = -1;
        }
      } 
    }
  }
  cin >> d >> m;
  if (a[d][m] == -1) cout << "2" << endl;
  else if (a[d][m] == 1) cout << "1" << endl;
}

/*
пояснять этот код бессмысленно, т.к. надо разобраться в теории игр. за пояснениями в лс / дс
*/
