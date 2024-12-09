#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mp;
  int c = 1000;
  char ii;
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'n')
      mp['n']++;
    else if (a[i] == 'i')
      mp['i']++;
    else if (a[i] == 'e')
      mp['e']++;
    else if (a[i] == 't')
      mp['t']++;
  }
  mp['n'] += min(min(mp['e'] / 3, mp['t']), min(mp['i'], (mp['n'] - 3) / 2));
  mp['n'] /= 3;
  mp['e'] /= 3;
  c = min(min(mp['n'], mp['i']), min(mp['e'], mp['t']));
  cout << c << endl;
  return 0;
}
