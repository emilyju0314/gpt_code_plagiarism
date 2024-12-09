#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = 2123123123;
const int MOD = 1e9 + 7;
inline void OPEN(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
int n, m;
long long ans, anita;
int a[100000 + 5];
vector<int> idx[100000 + 5];
set<int> s;
long long count(int ch, int place) {
  long long ret = 0;
  for (int i = 0; i < (int)(idx[place]).size(); i++) {
    int gett = idx[place][i];
    if (gett > 0 && a[gett - 1] != place)
      ret += abs((long long)(ch)-a[gett - 1]);
    if (gett < m - 1 && a[gett + 1] != place)
      ret += abs((long long)(ch)-a[gett + 1]);
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    idx[a[i]].push_back(i);
    s.insert(a[i]);
  }
  for (int i = 0; i < m - 1; i++) {
    anita += abs(a[i] - a[i + 1]);
  }
  for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++it) {
    int k = *it;
    int last = k;
    int l = 1, r = n;
    for (int bs = 0; bs < 40; bs++) {
      int fm = (k - 1), sm = (k + 1), mm = k;
      long long fr = count(fm, last), sr = count(sm, last),
                mr = count(mm, last);
      if (fr < sr && fr < mr) {
        r = k;
        k = (k + l) / 2;
      }
      if (sr < fr && sr < mr) {
        l = k;
        k = max(k + 1, (k + r) / 2);
      }
    }
    long long s = count(last, last);
    long long t = count(k, last);
    if (s - t > ans) {
      ans = s - t;
    }
  }
  printf("%I64d\n", anita - ans);
  return 0;
}
