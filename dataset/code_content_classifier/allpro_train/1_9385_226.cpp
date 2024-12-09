#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p;
  int ans = 0;
  cin >> s >> p;
  for (int i = 0; i < p.size(); i++) {
    if (s[ans] == p[i]) ans++;
  }
  cout << ++ans << endl;
  return 0;
}
