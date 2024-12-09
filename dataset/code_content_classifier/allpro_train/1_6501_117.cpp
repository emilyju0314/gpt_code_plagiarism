#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long n, m, i, j, x, y, ans = 0x1bbbbbbbbbbbbbbbll, dp[500005], sz[500005],
                            stk[500005], tp;
vector<long long> e[500005];
struct ii {
  long long x, y;
};
bool cmp(ii x, ii y) {
  if (x.x == y.x) return x.y < y.y;
  return x.x < y.x;
}
double slp(ii x, ii y) { return 1.0 * (x.y - y.y) / (x.x - y.x); }
void dfs(int x, int fa) {
  sz[x] = 1;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (*it != fa) {
      dfs(*it, x);
      sz[x] += sz[*it];
    }
  dp[x] = (sz[x]) * (sz[x]);
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (*it != fa) {
      dp[x] = min(dp[x], dp[*it] + (sz[x] - sz[*it]) * (sz[x] - sz[*it]));
    }
  vector<ii> v;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (*it != fa) {
      v.push_back(
          (ii){sz[*it], dp[*it] + (sz[*it]) * (sz[*it]) - 2 * n * sz[*it]});
    }
  sort(v.begin(), v.end(), cmp);
  stk[tp = 1] = 0;
  for (int i = 1; i < v.size(); i++) {
    while (tp > 1 && slp(v[stk[tp - 1]], v[stk[tp]]) > -2 * v[i].x) tp--;
    ans =
        min(ans, 2 * v[i].x * v[stk[tp]].x + v[stk[tp]].y + v[i].y + (n) * (n));
    if (v[i].x == v[i - 1].x) continue;
    while (tp > 1 && slp(v[stk[tp - 1]], v[stk[tp]]) <= slp(v[stk[tp]], v[i]))
      tp--;
    stk[++tp] = i;
  }
}
int main() {
  read(n);
  for (((i)) = (1); ((i)) <= ((n - 1)); ((i))++) {
    read(x);
    read(y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 0);
  ans = min(ans, dp[1]);
  cout << ((n) * (n)-ans) / 2 + n * (n - 1) / 2 << endl;
  return 0;
}
