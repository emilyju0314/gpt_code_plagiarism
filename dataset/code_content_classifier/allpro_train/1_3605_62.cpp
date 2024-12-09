#include <bits/stdc++.h>
using namespace std;
int a[26], b[26];
long long int q;
int comp(long long int k) {
  long long int qs = q;
  for (int i = 0; i < 26; i++) qs -= max(b[i] * k - a[i], 0LL);
  return qs >= 0;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.precision(10);
  string s, t;
  cin >> s;
  cin >> t;
  for (char c : s)
    if (c == '?')
      q++;
    else
      a[c - 'a']++;
  for (char c : t) b[c - 'a']++;
  int l = 0, r = 10E5 + 1;
  while (r - l > 1) {
    int p = (l + r) / 2;
    if (comp(p))
      l = p;
    else
      r = p;
  }
  for (int i = 0; i < 26; i++) b[i] *= l;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      while (b[j] - a[j] <= 0 && j < 26) j++;
      if (j < 26) {
        s[i] = j + 'a';
        b[j]--;
      } else
        s[i] = 'a';
    }
  }
  cout << s;
  return 0;
}
