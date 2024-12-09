#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int INF = 0x7f7f7f7f;
int ca[30], cb[30], cc[30];
void calc(string s, int *arr) {
  for (int i = 0; s[i]; i++) arr[s[i] - 'a']++;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b >> c;
  calc(a, ca);
  calc(b, cb);
  calc(c, cc);
  int ansb, ansc;
  ansb = ansc = 0;
  for (int cntb = 0;; cntb++) {
    bool ok = true;
    for (int i = 0; i < 26; i++) ok &= ca[i] >= (cntb * cb[i]);
    if (!ok) break;
    int cntc = (int)(a.size());
    for (int i = 0; i < 26; i++)
      if (cc[i]) cntc = min(cntc, (ca[i] - cntb * cb[i]) / cc[i]);
    if (cntb + cntc > ansb + ansc) {
      ansb = cntb;
      ansc = cntc;
    }
  }
  for (int i = 0; i < 26; i++) ca[i] -= (cb[i] * ansb + cc[i] * ansc);
  while (ansb--) cout << b;
  while (ansc--) cout << c;
  for (int i = 0; i < 26; i++)
    if (ca[i] > 0)
      while (ca[i]--) cout << (char)('a' + i);
  cout << endl;
  return 0;
}
