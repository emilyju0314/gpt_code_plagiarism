#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
string s, a, b;
pair<long long, long long> H[2010][2010];
long long hash1 = 257, hash2 = 13;
long long pw1[3000], pw2[3000];
pair<long long, long long> gethash(int x, int y) {
  long long ret = 0, ret1 = 0;
  for (int i = x; i <= y; i++) {
    ret = (ret * hash1 + s[i]) % MOD;
    ret1 = (ret1 * hash2 + s[i]) % MOD;
  }
  return {ret, ret1};
}
pair<long long, long long> gethash2(string t) {
  long long ret = 0, ret1 = 0;
  for (int i = 0; i < t.size(); i++) {
    ret = (ret * hash1 + t[i]) % MOD;
    ret1 = (ret1 * hash2 + t[i]) % MOD;
  }
  return {ret, ret1};
}
int main() {
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= 2005; i++) {
    pw1[i] = pw1[i - 1] * hash1 % MOD;
    pw2[i] = pw2[i - 1] * hash2 % MOD;
  }
  cin >> s >> a >> b;
  for (int i = 1; i <= s.size(); i++) {
    H[0][i - 1] = gethash(0, i - 1);
    long long n1 = H[0][i - 1].first, n2 = H[0][i - 1].second;
    for (int j = 1; j < s.size() - i + 1; j++) {
      n1 -= (pw1[i - 1] * s[j - 1]) % MOD;
      n2 -= (pw2[i - 1] * s[j - 1]) % MOD;
      n1 = (n1 + 10 * MOD) % MOD;
      n2 = (n2 + 10 * MOD) % MOD;
      n1 = n1 * hash1 % MOD;
      n2 = n2 * hash2 % MOD;
      n1 += s[j + i - 1];
      n2 += s[j + i - 1];
      H[j][j + i - 1] = {n1, n2};
    }
  }
  pair<long long, long long> aa = gethash2(a), bb = gethash2(b);
  vector<pair<long long, long long> > ans;
  int mx = max(a.size(), b.size());
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + mx - 1; j < s.size(); j++) {
      pair<long long, long long> aaa = H[i][i + a.size() - 1],
                                 bbb = H[j - b.size() + 1][j];
      if (aaa == aa && bbb == bb) ans.push_back(H[i][j]);
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << endl;
  return 0;
}
