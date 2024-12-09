#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 1e9 + 7;
long long power(long long a, long long b) {
  if (b == 0)
    return 1;
  else {
    long long x = power(a, b / 2);
    x = (x * x) % MOD;
    if (b & 1)
      return (x * a) % MOD;
    else
      return x;
  }
}
long long &Mod(long long &a) {
  if (a >= MOD) {
    return Mod(a -= MOD);
  } else if (a < 0) {
    return Mod(a += MOD);
  } else {
    return a;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = 19;
const int MX = (1 << 18);
int n;
double dp[MX][N];
bool calc[MX][N];
double p[N][N];
double solve(int mask, int cur) {
  if (__builtin_popcount(mask) == n) {
    return cur == 0;
  }
  if (calc[mask][cur]) return dp[mask][cur];
  double pr = 0;
  for (int next_player = 0; next_player < n; next_player++) {
    if (!(mask & (1 << next_player))) {
      if (cur == 0) {
        pr = max(solve(mask ^ (1 << next_player), cur) * p[cur][next_player],
                 pr);
      } else if (next_player == 0) {
        pr = max(
            solve(mask ^ (1 << next_player), next_player) * p[next_player][cur],
            pr);
      } else {
        pr =
            max(solve(mask ^ (1 << next_player), next_player) *
                        p[next_player][cur] +
                    solve(mask ^ (1 << next_player), cur) * p[cur][next_player],
                pr);
      }
    }
  }
  dp[mask][cur] = pr;
  calc[mask][cur] = true;
  return dp[mask][cur];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  double answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i != j) {
        int mask = (1 << i) ^ (1 << j);
        double t_ans = 0;
        if (i == 0) {
          t_ans = solve(mask, i) * p[i][j];
        } else {
          t_ans = solve(mask, i) * p[i][j] + solve(mask, j) * p[j][i];
        }
        answer = max(t_ans, answer);
      }
    }
  }
  cout << answer << '\n';
}
