#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void amin(T &first, const T &second) {
  if (second < first) first = second;
}
template <class T>
inline void amax(T &first, const T &second) {
  if (first < second) first = second;
}
const int mod = (int)1e9 + 7;
const int maxn = (int)1000;
string a;
int dp[maxn][maxn][3][3];
inline bool check(int c1, int c2) {
  if (c1 == 0) {
    return 1;
  } else if (c2 == 0) {
    return 1;
  } else if (c1 != c2) {
    return 1;
  } else {
    return 0;
  }
}
int rec(int lo, int hi, int cl, int cr) {
  int &ret = dp[lo][hi][cl][cr];
  if (ret != -1) {
    return ret;
  }
  if (lo >= hi) {
    return ret = check(cl, cr);
  }
  int k = 0, i;
  for (i = lo; i <= hi; ++i) {
    if (a[i] == '(') {
      ++k;
    } else {
      --k;
    }
    if (k == 0) {
      break;
    }
  }
  ret = 0;
  for (int L = 0; L < 3; ++L) {
    for (int R = 0; R < 3; ++R) {
      if (L + R > 0 && L * R == 0) {
        if (check(cl, L)) {
          long long tmp =
              (long long)rec(lo + 1, i - 1, L, R) * rec(i + 1, hi, R, cr);
          ret = (ret + tmp) % mod;
        }
      }
    }
  }
  return ret;
}
void solve() {
  cin >> a;
  memset(dp, -1, sizeof(dp));
  cout << (rec(0, ((int)(a).size()) - 1, 0, 0)) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
