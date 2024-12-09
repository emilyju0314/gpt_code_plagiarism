#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int n = s.size();
  s += 'b';
  for (int i = 0; i < n; i++) {
    if (s[i] != s[i + 1])
      cout << 1 << " ";
    else
      cout << 0 << " ";
  }
  return 0;
}
