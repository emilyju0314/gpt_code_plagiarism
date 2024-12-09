#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  set<string> se;
  cin >> s;
  for (int i = 0; i <= s.size(); i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      string t = s;
      t.insert(t.begin() + i, c);
      se.insert(t);
    }
  }
  cout << se.size() << endl;
}
