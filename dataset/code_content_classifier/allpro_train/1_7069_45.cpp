#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
bool cmax(int &a, int b) { return (a < b) ? a = b, 1 : 0; }
bool cmin(int &a, int b) { return (a > b) ? a = b, 1 : 0; }
template <typename T>
T read() {
  T ans = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch))
    ans = (ans << 3) + (ans << 1) + (ch - '0'), ch = getchar();
  return ans * f;
}
template <typename T>
void write(T x, char y) {
  if (x == 0) {
    putchar('0');
    putchar(y);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  static char wr[20];
  int top = 0;
  for (; x; x /= 10) wr[++top] = x % 10 + '0';
  while (top) putchar(wr[top--]);
  putchar(y);
}
int n, l, r;
struct box {
  int a, b;
  bool operator<(const box &s) const { return b == s.b ? a > s.a : b < s.b; }
} e[N];
int max_d;
void input() {
  n = read<int>(), l = read<int>(), r = read<int>();
  for (register int i = (int)1; i <= (int)n; ++i)
    e[i].a = read<int>(), max_d += e[i].a;
  for (register int i = (int)1; i <= (int)n; ++i) e[i].b = read<int>();
}
int dp[N];
const int inf = 0x3f3f3f3f;
void work() {
  swap(l, r);
  l = max_d - l, r = max_d - r;
  memset(dp, -inf, sizeof dp);
  dp[0] = 0;
  sort(e + 1, e + n + 1);
  for (register int i = (int)1; i <= (int)n; ++i) {
    for (register int j = (int)max_d; j >= (int)e[i].a; --j) {
      cmax(dp[j], dp[j - e[i].a] + (l <= j && j <= r) * e[i].b);
    }
  }
  write(*max_element(dp, dp + max_d + 1), '\n');
}
int main() {
  input();
  work();
  return 0;
}
