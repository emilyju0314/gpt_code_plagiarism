#include <bits/stdc++.h>
using namespace std;
string t;
void rekt() {
  cout << ":(";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int cnt = 0;
  cin >> t;
  for (auto c : t) cnt += c == 'a';
  int rem = t.size() - cnt;
  if (rem % 2) rekt();
  rem /= 2;
  string s, sp;
  for (int i = 0; i < t.size(); ++i)
    if (i < t.size() - rem)
      s += t[i];
    else
      sp += t[i];
  for (auto c : sp)
    if (c == 'a') rekt();
  string snow;
  for (auto i : s)
    if (i != 'a') snow += i;
  if (snow == sp)
    cout << s;
  else
    rekt();
}
