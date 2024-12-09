#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, char> Map;
  Map.insert({'A', 'A'});
  Map.insert({'b', 'd'});
  Map.insert({'d', 'b'});
  Map.insert({'H', 'H'});
  Map.insert({'I', 'I'});
  Map.insert({'M', 'M'});
  Map.insert({'O', 'O'});
  Map.insert({'o', 'o'});
  Map.insert({'p', 'q'});
  Map.insert({'T', 'T'});
  Map.insert({'U', 'U'});
  Map.insert({'v', 'v'});
  Map.insert({'V', 'V'});
  Map.insert({'W', 'W'});
  Map.insert({'w', 'w'});
  Map.insert({'X', 'X'});
  Map.insert({'x', 'x'});
  Map.insert({'Y', 'Y'});
  Map.insert({'q', 'p'});
  map<char, char>::iterator itr;
  string s;
  cin >> s;
  int i = 0, j = s.length() - 1;
  while (i <= j) {
    itr = Map.find(s[i]);
    if (itr == Map.end() || itr->second != s[j]) {
      cout << "NIE";
      return 0;
    }
    i++;
    j--;
  }
  cout << "TAK";
  return 0;
}
