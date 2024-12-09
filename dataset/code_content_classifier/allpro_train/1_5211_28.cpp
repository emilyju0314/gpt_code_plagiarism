#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF32 = 1e9 + 1e2;
void stndrtn() {}
uniform_int_distribution<int> _d(0, INF32);
mt19937 _rnd;
int rnd(int first) { return _d(_rnd) % first; }
const bool flag = 0;
const vector<int> digits = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
struct Digit {
  int mask;
  Digit() { mask = -1; }
  Digit(string s) {
    mask = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < (int)s.size(); ++i) {
      mask |= (s[i] == '1') * (1 << i);
    }
  }
  int index() {
    for (int i = 0; i < 10; ++i) {
      if (digits[i] == mask) {
        return i;
      }
    }
  }
  int cost(int first) {
    if ((mask & first) != mask) {
      return -1;
    }
    return __builtin_popcount(mask ^ first);
  }
};
const int N = 2e3 + 10;
bool dp[N][N];
void maincode() {
  int n, k;
  cin >> n >> k;
  vector<Digit> d;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    d.push_back(Digit(s));
  }
  dp[n][0] = 1;
  for (int i = n - 1; ~i; --i) {
    for (int j = 0; j <= k; ++j) {
      for (int mask : digits) {
        int cost = d[i].cost(mask);
        dp[i][j] |= (~cost && j >= cost && dp[i + 1][j - cost]);
      }
    }
  }
  if (!dp[0][k]) cout << -1, exit(0);
  vector<Digit> ans(n);
  for (int i = 0; i < n; ++i) {
    int newk = 0;
    for (int mask : digits) {
      int cost = d[i].cost(mask);
      if (~cost && k >= cost && dp[i + 1][k - cost]) {
        newk = k - cost;
        ans[i].mask = mask;
      }
    }
    swap(k, newk);
  }
  for (Digit mask : ans) cout << mask.index();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr), stndrtn();
  _rnd.seed(time(nullptr));
  int ts = 1;
  if (flag) {
    cin >> ts;
  }
  while (ts--) {
    maincode();
  }
  return 0;
}
