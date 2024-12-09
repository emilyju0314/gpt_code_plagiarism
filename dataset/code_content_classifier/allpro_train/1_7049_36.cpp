#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N], n, w, B, K;
int ans[N], id[N], mb, mx;
long long wi[N];
pair<long long, int> p[N];
inline double slip(int x, int y) { return (double)(wi[y] - wi[x]) / (y - x); }
struct st {
  int top, a[405], tag, pos;
  int id;
  inline void rebuild(int l, int r) {
    int rr = min(id * B, mx);
    top = pos = 0;
    for (int i = l; i <= r; i++) wi[i] += i;
    for (int i = (id - 1) * B + 1; i <= rr; i++)
      if (wi[i] + (long long)i * tag > wi[pos] + (long long)pos * tag) pos = i;
    a[++top] = pos;
    for (int i = pos + 1; i <= rr; i++) {
      while (top > 1 && slip(i, a[top]) > slip(a[top], a[top - 1])) top--;
      a[++top] = i;
    }
    pos = 1;
  }
} s[400];
bool cmp(int x, int y) {
  if (b[x] == b[y]) return a[x] < a[y];
  return b[x] < b[y];
}
void modify(int r) {
  int rr = (r - 1) / B + 1;
  if (rr == 1)
    s[1].rebuild(1, r);
  else {
    s[rr].rebuild((rr - 1) * B + 1, r);
    for (int i = 1; i <= rr - 1; i++) {
      s[i].tag++;
      for (; s[i].pos < s[i].top &&
             slip(s[i].a[s[i].pos], s[i].a[s[i].pos + 1]) > -s[i].tag;
           s[i].pos++)
        ;
    }
  }
}
pair<long long, int> ask() {
  pair<long long, int> res =
      make_pair(wi[s[1].a[s[1].pos]] + (long long)s[1].tag * s[1].a[s[1].pos],
                s[1].a[s[1].pos]);
  static pair<long long, int> a;
  for (int i = 2; i <= K; i++) {
    a = make_pair(wi[s[i].a[s[i].pos]] + (long long)s[i].tag * s[i].a[s[i].pos],
                  s[i].a[s[i].pos]);
    if (a.first > res.first) res = a;
  }
  return res;
}
void read(int &n) {
  static char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (n = 0; c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int main() {
  read(n), read(w);
  for (int i = 1; i <= n; i++)
    read(a[i]), read(b[i]), id[i] = i, mx = max(mx, a[i]);
  sort(id + 1, id + n + 1, cmp);
  mb = b[id[n]];
  B = (int)sqrt(mx);
  K = (mx - 1) / B + 1;
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= K; i++) s[i].id = i;
  ans[0] = n;
  p[0] = make_pair(0ll, 0);
  int j = 1;
  for (int i = 1; i <= mb + 1; i++) {
    ans[i] = ans[i - 1];
    while (b[id[j]] == i - 1 && j <= n) {
      ans[i]--;
      modify(a[id[j]]);
      j++;
    }
    p[i] = ask();
  }
  for (int i = 0; i <= mb + 1; i++)
    printf("%I64d %d\n", (long long)ans[i] * i * w + p[i].first, p[i].second);
  return 0;
}
