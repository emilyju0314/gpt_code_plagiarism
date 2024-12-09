#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 7;
inline long long read() {
  long long res = 0, tmp = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') tmp = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
  return res * tmp;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void fre() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
void hour() {
  cerr << "运行时间：" << 1.0 * clock() / CLOCKS_PER_SEC << "s" << endl;
}
struct node {
  long long val, num;
} s[maxn];
long long ans, n, m, qu, sum;
map<string, long long> w;
string change(long long x) {
  string p = "";
  while (x != 0) p += (x % 10 + '0'), x /= 10;
  return p;
}
bool cmp(node x, node y) { return x.val > y.val; }
priority_queue<long long, vector<long long>, greater<long long> > q, l;
int main() {
  n = read();
  for (register long long i = 1; i <= n; i++) {
    long long x = read();
    ans += x;
    string p = change(x);
    if (w[p] == 0) {
      s[++m].val = x;
      s[m].num = 1;
      w[p] = m;
    } else
      s[w[p]].num++;
  }
  sort(s + 1, s + 1 + m, cmp);
  for (register long long i = 1; i <= m; i++) {
    long long r = 0;
    qu = sum - 2 * q.size();
    sum += s[i].num;
    while (qu != 0 && s[i].num != 0) {
      qu--;
      s[i].num--;
      r++;
    }
    while (!q.empty() && s[i].num != 0 && s[i].val > q.top()) {
      q.pop();
      l.push(s[i].val);
      if (--s[i].num != 0) l.push(s[i].val), s[i].num--;
    }
    while (s[i].num != 0) {
      if (q.empty()) {
        qu += s[i].num;
        s[i].num = 0;
        break;
      }
      if (s[i].num == 1) {
        qu++;
      } else {
        if (s[i].val * 2 > q.top()) {
          l.push(s[i].val * 2 - q.top());
          l.push(q.top());
          q.pop();
          s[i].num--;
        } else
          qu++;
      }
      s[i].num--;
    }
    while (!l.empty()) {
      q.push(l.top());
      l.pop();
    }
    while (r) {
      q.push(s[i].val);
      --r;
    }
  }
  while (!q.empty()) {
    ans -= q.top();
    q.pop();
  }
  write(ans);
  puts("");
  return 0;
}
