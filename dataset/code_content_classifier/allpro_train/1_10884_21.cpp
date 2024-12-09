#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
template <class T, class... U>
void DEBUG(const T &head, const U &...tail) {}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
int dp[SIZE], n;
int get(int x, int y) {
  if (y > n) return get(x, n) + get(1, y - n);
  return dp[y] - dp[x - 1];
}
int main() {
  R(n);
  for (int i = (1); i <= (n); ++i) {
    R(dp[i]);
    dp[i] += dp[i - 1];
  }
  int s, f;
  R(s, f);
  int v = f - s;
  int ma = -1, st, ans;
  for (int i = (1); i <= (n); ++i) {
    int res = get(i, i + v - 1);
    if (res > ma) {
      ma = res;
      st = i;
      ans = (s - st + 1) % n;
      if (ans <= 0) ans += n;
    } else if (res == ma) {
      int tmp = (s - i + 1) % n;
      if (tmp <= 0) tmp += n;
      if (tmp < ans) ans = tmp;
    }
  }
  W(ans);
  return 0;
}
