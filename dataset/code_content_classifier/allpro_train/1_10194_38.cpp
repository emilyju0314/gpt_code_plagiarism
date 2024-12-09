#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
int n, size, a[100005], b[100005], pri[200005], last[2000005];
bool flag, vis[2000005], use[2000005];
inline bool check(int x) {
  int num[50], size = 0;
  while (vis[x]) {
    num[++size] = last[x];
    x = x / last[x];
  }
  num[++size] = x;
  for (int i = 1; i <= size; i++) {
    if (use[num[i]]) {
      return false;
    }
  }
  return true;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 2; i <= 2000000; i++) {
    if (!vis[i]) {
      pri[++size] = i;
    }
    for (int j = 1; j <= size; j++) {
      int k = pri[j] * i;
      if (k > 2000000) break;
      vis[k] = true;
      last[k] = pri[j];
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (flag) {
      while (use[pri[j]]) {
        j++;
      }
      use[pri[j]] = true;
      b[i] = pri[j];
    } else {
      int k = a[i];
      while (!check(k)) {
        k++;
      }
      if (k > a[i]) {
        flag = true;
      }
      b[i] = k;
      while (vis[k]) {
        use[last[k]] = true;
        k = k / last[k];
      }
      use[k] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    write(b[i]);
    putchar(' ');
  }
  return 0;
}
