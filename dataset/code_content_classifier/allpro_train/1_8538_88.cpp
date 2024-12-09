#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int n;
vector<int> V, K, X;
const int INF = 1e9 + 9;
const int N = 77;
int dp[N][N][N][2];
void mini(int& a, int b) { a = min(a, b); }
int count_remaining(const vector<int>& list, int from, int limit) {
  int cnt = 0;
  for (int i = from; i < (int)list.size() && list[i] < limit; i++) {
    ++cnt;
  }
  return cnt;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      V.push_back(i);
    } else if (s[i] == 'K') {
      K.push_back(i);
    } else {
      X.push_back(i);
    }
  }
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= n; b++) {
      for (int c = 0; c <= n; c++) {
        for (int d = 0; d < 2; d++) {
          dp[a][b][c][d] = INF;
        }
      }
    }
  }
  dp[0][0][0][0] = 0;
  for (int v = 0; v <= (int)V.size(); v++) {
    for (int k = 0; k <= (int)K.size(); k++) {
      for (int x = 0; x <= (int)X.size(); x++) {
        for (int type = 0; type < 2; type++) {
          auto moving_cost = [&](int where) {
            return count_remaining(V, v, where) + count_remaining(K, k, where) +
                   count_remaining(X, x, where);
          };
          int already = dp[v][k][x][type];
          if (v < (int)V.size()) {
            mini(dp[v + 1][k][x][1], already + moving_cost(V[v]));
          }
          if (k < (int)K.size() && type == 0) {
            mini(dp[v][k + 1][x][0], already + moving_cost(K[k]));
          }
          if (x < (int)X.size()) {
            mini(dp[v][k][x + 1][0], already + moving_cost(X[x]));
          }
        }
      }
    }
  }
  int ans = min(dp[V.size()][K.size()][X.size()][0],
                dp[V.size()][K.size()][X.size()][1]);
  cout << ans << "\n";
}
