#include <iostream>

using namespace std;

int main() {
  string s; int ints, po, t = 0;
  cin >> s;
  if ((s.find('e') > 0) && ((s.find('e') < 50))){
    po = s.find('e');
    s.erase(s.find('e'), 1);
    for ( int i = 0 ; i <= s.length() ; i++ ) {
      if (s[i] == '1') t ++;
    }
    if ( t % 2 == 0 ) {
      s = s.insert( po , "0" );
    }
    else s = s.insert( po , "1" );
    cout << s << endl;
  }
  if ((s.find('o') > 0) && ((s.find('o') < 50))){
    po = s.find('o');
    s.erase(s.find('o'), 1);
    for ( int i = 0 ; i <= s.length() ; i++ ) {
      if (s[i] == '1') t ++;
    }
    if ( t % 2 == 0 ) {
      s = s.insert( po , "1" );
    }
    else s = s.insert( po , "0" );
    cout << s << endl;
  }
}
