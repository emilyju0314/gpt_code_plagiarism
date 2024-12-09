#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
int F[10], tot;
long long val[10000005], n, m;
int cmp(int a, int b) {
  if (a == b) return 0;
  return (a > b) ? 1 : -1;
}
void dfs(int p, int n) {
  if (p > n) {
    if (n == 2 && F[1] == F[2]) return;
    ++tot;
    for (int i = 1; i <= n; ++i) val[tot] = val[tot] * 10 + F[i];
    return;
  }
  for (int i = 0; i <= 9; ++i) {
    F[p] = i;
    if (p >= 3 && (!cmp(F[p - 2], F[p - 1]) ||
                   cmp(F[p], F[p - 1]) != cmp(F[p - 2], F[p - 1])))
      continue;
    dfs(p + 1, n);
  }
}
inline void prepare() {
  for (int i = 1; i <= 7; ++i)
    for (F[1] = 1; F[1] <= 9; ++F[1]) dfs(2, i);
}
int to[10000005], nxt[10000005], H[10000005], cnt2;
inline void ins(int x, int y) {
  to[++cnt2] = y;
  nxt[cnt2] = H[x];
  H[x] = cnt2;
}
inline bool check(long long p) {
  int st[20], tot = 0;
  for (; p; p /= 10) st[++tot] = p % 10;
  for (int i = 2; i <= tot - 1; ++i)
    if (!cmp(st[i], st[i - 1]) ||
        cmp(st[i], st[i - 1]) != cmp(st[i], st[i + 1]))
      return 0;
  return 1;
}
int cnt[15][15], sum[10000005];
inline void work() {
  if (n > 10000000) {
    for (long long i = n; i <= 100000000000000ll; i += n)
      if (check(i) && --m == 0) {
        cout << i << endl;
        return;
      }
    puts("-1");
    return;
  } else {
    for (int i = 1; i <= tot; ++i)
      if (val[i] % n == 0 && --m == 0) {
        cout << val[i] << endl;
        return;
      }
    for (int i = tot; i >= 1; --i) ins(val[i] % n, i);
    for (int i = 0; i <= n - 1; ++i)
      if (H[i]) {
        int v = (n - (long long)i * 10000000 % n) % n;
        if (!H[v]) continue;
        memset(cnt, 0, sizeof cnt);
        for (int j = H[v]; j; j = nxt[j]) {
          int t = val[to[j]];
          if (t > 10000000 / 10)
            ++cnt[t / (10000000 / 10)][t / (10000000 / 100) % 10];
          else if (t > 10000000 / 100 &&
                   t / (10000000 / 1000) % 10 < t / (10000000 / 100) % 10)
            ++cnt[0][t / (10000000 / 100) % 10];
        }
        for (int j = H[i]; j; j = nxt[j]) {
          int p = to[j], a = val[p] % 10, b = val[p] / 10 % 10;
          if (val[p] < 10) {
            for (int t1 = a + 1; t1 <= 9; ++t1)
              for (int t2 = t1 - 1; t2 >= 0; --t2) sum[p] += cnt[t1][t2];
            for (int t1 = a - 1; t1 >= 0; --t1)
              for (int t2 = t1 + 1; t2 <= 9; ++t2) sum[p] += cnt[t1][t2];
          } else if (b > a)
            for (int t1 = a + 1; t1 <= 9; ++t1)
              for (int t2 = t1 - 1; t2 >= 0; --t2) sum[p] += cnt[t1][t2];
          else
            for (int t1 = a - 1; t1 >= 0; --t1)
              for (int t2 = t1 + 1; t2 <= 9; ++t2) sum[p] += cnt[t1][t2];
        }
      }
    for (int i = 1; i <= tot; ++i) {
      if (m > sum[i])
        m -= sum[i];
      else {
        for (int j = 1; j <= tot; ++j)
          if ((val[i] * 10000000 + val[j]) % n == 0 &&
              check(val[i] * 10000000 + val[j]) && --m == 0) {
            if (val[i] * 10000000 + val[j] > 100000000000000ll)
              puts("-1");
            else
              printf("%I64d%07I64d\n", val[i], val[j]);
            return;
          }
      }
    }
  }
  puts("-1");
}
int main() {
  prepare();
  cin >> n >> m;
  work();
  return 0;
}
