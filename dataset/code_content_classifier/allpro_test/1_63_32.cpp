#include <bits/stdc++.h>
using namespace std;
template <class _F, class _S>
ostream &operator<<(ostream &out, const pair<_F, _S> &_pair) {
  return out << "(" << _pair.first << "," << _pair.second << ")";
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &_vec) {
  out << "[";
  for (int _vecp = 0; _vecp < _vec.size(); ++_vecp)
    out << _vec[_vecp] << ",]"[_vecp + 1 == _vec.size()];
  return out;
}
void debug() {}
template <class T, class... U>
void debug(const T &head, const U &...tail) {
  cerr << head << (sizeof...(tail) ? " " : "\n"), debug(tail...);
}
template <class... T>
void D(const T &...parm) {
  cerr << ">>> ", debug(parm...);
}
const int mx = 4e5 + 10;
const long long mod = 998244353;
mt19937_64 mtrand(time(0));
int n, m, T;
string s[20];
int b[20];
int cnt[1 << 20];
vector<int> vec[20];
unordered_map<int, int> mp[20], mp2[20];
int dp[1 << 20][2];
int sk[mx], tot;
void solve(int id) {
  for (int i = 0; i < s[id].size(); ++i) {
    if (s[id][i] == '(')
      ++b[id];
    else
      --b[id];
    vec[id].push_back(b[id]);
    ++mp2[id][b[id]];
    if (!mp[id].count(b[id])) mp[id][b[id]] = mp2[id][b[id] + 1];
  }
}
void run_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    solve(i);
  }
  int up = 1 << n;
  for (int i = 0; i < up; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) cnt[i] += b[j];
    }
    dp[i][0] = dp[i][1] = -0x3f3f3f3f;
  }
  dp[0][0] = 0;
  for (int i = 1; i < up; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        int st = i & (up - (1 << j) - 1);
        if (mp[j].count(-cnt[st] - 1)) {
          dp[i][1] = max(dp[i][1], dp[st][0] + mp[j][-cnt[st] - 1]);
        } else {
          dp[i][0] = max(dp[i][0], dp[st][0] + mp2[j][-cnt[st]]);
        }
        dp[i][1] = max(dp[i][1], dp[st][1]);
      }
    }
  }
  long long ans = max(dp[up - 1][0], dp[up - 1][1]);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  T = 1;
  for (int i = 1; i <= T; ++i) run_case();
}
