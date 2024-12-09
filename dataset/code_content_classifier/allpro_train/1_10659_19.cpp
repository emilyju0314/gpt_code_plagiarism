#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
template <class T>
inline bool setmin(T &a, T b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T>
inline bool setmax(T &a, T b) {
  if (a < b) return a = b, 1;
  return 0;
}
namespace fastio {
template <class T>
istream &operator>>(istream &os, vector<T> &container) {
  for (auto &u : container) os >> u;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}
template <class T1, class T2>
inline istream &operator>>(istream &os, pair<T1, T2> &p) {
  return os >> p.first >> p.second;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}
template <typename... args>
void re(args &...tail) {
  ((cin >> tail), ...);
}
template <typename... args>
void pr(args... tail) {
  ((cout << tail << " "), ...);
}
template <typename... args>
void prln(args... tail) {
  ((cout << tail << " "), ...);
  cout << "\n";
}
}  // namespace fastio
using namespace fastio;
namespace debug {
template <typename _T>
inline void _debug(const char *s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _debug(const char *s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _debug(s + 1, a...);
}
}  // namespace debug
using namespace debug;
const int N = 1e5 + 7;
string s;
int n, q;
int nxt[N][26];
int dp[257][257][257];
string rel[3];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  re(n, q, s);
  for (int i = (0); i <= (25); i++) nxt[n][i] = nxt[n + 1][i] = n;
  for (int i = (n - 1); i >= (0); i--) {
    for (int j = (0); j <= (25); j++) {
      nxt[i][j] = (s[i] == 'a' + j ? i : nxt[i + 1][j]);
    }
  }
  dp[0][0][0] = -1;
  for (int _ = (1); _ <= (q); _++) {
    char t;
    int x;
    re(t, x);
    x--;
    if (t == '+') {
      char l;
      re(l);
      rel[x] += l;
      int e0 = (int)(rel[0]).size(), e1 = (int)(rel[1]).size(),
          e2 = (int)(rel[2]).size();
      int b0 = (x == 0 ? e0 : 0);
      int b1 = (x == 1 ? e1 : 0);
      int b2 = (x == 2 ? e2 : 0);
      for (int a = (b0); a <= (e0); a++) {
        for (int b = (b1); b <= (e1); b++) {
          for (int c = (b2); c <= (e2); c++) {
            auto &v = dp[a][b][c];
            v = n;
            if (a) setmin(v, nxt[dp[a - 1][b][c] + 1][rel[0][a - 1] - 'a']);
            if (b) setmin(v, nxt[dp[a][b - 1][c] + 1][rel[1][b - 1] - 'a']);
            if (c) setmin(v, nxt[dp[a][b][c - 1] + 1][rel[2][c - 1] - 'a']);
          }
        }
      }
    } else {
      rel[x].pop_back();
    }
    prln(dp[(int)(rel[0]).size()][(int)(rel[1]).size()][(int)(rel[2]).size()] <
                 n
             ? "YES"
             : "NO");
  }
  exit(0);
}
