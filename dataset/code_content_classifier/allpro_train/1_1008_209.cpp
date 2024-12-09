#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string a = "heidi";
  int i, j;
  i = j = 0;
  while (i < s.length() && j < 5) {
    if (s[i] == a[j]) {
      ++i;
      ++j;
    } else {
      ++i;
    }
  }
  cout << (j == 5 ? "YES" : "NO") << endl;
}
