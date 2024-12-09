#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int st = 0, ed = s.length() - 1, c = 0;
  while (st <= ed) {
    if (s[st] != s[ed]) c++;
    st++, ed--;
  }
  if (c > 1 || (c == 0 && s.length() % 2 == 0))
    cout << "NO";
  else
    cout << "YES";
}
