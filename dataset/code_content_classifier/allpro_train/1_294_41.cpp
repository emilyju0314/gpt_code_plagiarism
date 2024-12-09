#include <bits/stdc++.h>
using namespace std;
string smallest(string s) {
  if (s.length() % 2 == 1) return s;
  string s1 = smallest(s.substr(0, s.length() / 2));
  string s2 = smallest(s.substr(s.length() / 2));
  if (s1 < s2)
    return s1 + s2;
  else
    return s2 + s1;
}
bool solve(string s1, string s2) {
  for (int i = 0; i < s1.length(); i++)
    if (s1[i] != s2[i]) return 0;
  return 1;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  s1 = smallest(s1);
  s2 = smallest(s2);
  if (solve(s1, s2))
    cout << "YES\n";
  else
    cout << "NO\n";
}
