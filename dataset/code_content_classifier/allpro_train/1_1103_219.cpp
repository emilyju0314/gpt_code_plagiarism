#include <bits/stdc++.h>
using namespace std;
string s;
int m = 0, n = 0;
int main() {
  cin >> s;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == '-')
      m++;
    else
      n++;
  }
  if (m == 0 || n == 0)
    cout << "YES";
  else if (m % n == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
