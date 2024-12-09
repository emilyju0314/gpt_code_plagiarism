#include <bits/stdc++.h>
using namespace std;
vector<int> mul(const vector<int> &l, const vector<int> &r) {
  vector<int> ret(l.size());
  for (int i = 0; i < (int)l.size(); ++i) {
    ret[i] = r[l[i]];
  }
  return ret;
}
vector<int> pw(vector<int> a, int n) {
  vector<int> ret(a.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    ret[i] = i;
  }
  while (n) {
    if (n & 1) ret = mul(ret, a);
    a = mul(a, a);
    n >>= 1;
  }
  return ret;
}
inline string solve(const string &s, int k, int d) {
  vector<int> dsort(s.length());
  vector<int> shift(s.length());
  for (int i = 0; i < (int)s.length(); ++i) {
    shift[i] = (i - 1 + (int)s.length()) % ((int)s.length());
  }
  int it = 0;
  for (int i = 0; i < (int)s.length(); ++i) {
    dsort[i] = i;
  }
  for (int i = 0; i < d; ++i) {
    for (int t = 0; t * d + i < k; ++t) {
      dsort[t * d + i] = it++;
    }
  }
  vector<int> res =
      mul(pw(mul(dsort, shift), (int)s.length() - k + 1), pw(shift, k - 1));
  string ret(s.length(), '0');
  for (int i = 0; i < (int)s.length(); ++i) {
    ret[res[i]] = s[i];
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int k, d;
    cin >> k >> d;
    s = solve(s, k, d);
    cout << s << "\n";
  }
  return 0;
}
