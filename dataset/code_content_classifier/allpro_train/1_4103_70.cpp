#include <bits/stdc++.h>
using namespace std;
const int maxn = 2002;
string p, s;
int lenp = 0, lens = 0;
string pi[maxn];
string si[maxn];
int k;
int main() {
  getline(cin, p), getline(cin, s);
  lenp = p.length();
  lens = s.length();
  scanf("%d", &k);
  for (register int i = 0; i < lenp; i++) {
    pi[i % k] += p[i];
  }
  int t = min(k, lens);
  string ans = "2";
  for (register int i = 1; i <= t; i++) {
    for (register int j = 0; j < i; j++) si[j] = "";
    for (register int j = 0; j < lens; j++) {
      si[j % i] += s[j];
    }
    string res = "";
    int kk = i - 1;
    for (register int j = k - 1; j >= 0; j--) {
      if (kk < 0) {
        res += '0';
      } else if (pi[j] == si[kk]) {
        kk--;
        res += '1';
      } else {
        res += '0';
      }
    }
    if (kk < 0) {
      reverse(res.begin(), res.end());
      ans = min(ans, res);
    }
  }
  if (ans != "2") {
    cout << ans << endl;
  } else {
    cout << '0' << endl;
  }
  return 0;
}
