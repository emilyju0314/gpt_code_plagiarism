#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
long long a[N];
long long ans((100000000000000000ll));
struct Sun {
  int siz;
  long long s[N];
  Sun() { siz = 0, memset(s, 0, sizeof(s)); }
  int size() { return siz; }
  void clear() { siz = 0; }
  bool cmp(int ca, int cb) { return s[ca] > s[cb]; }
  void Swap(int ca, int cb) { swap(s[ca], s[cb]); }
  void up(int o) {
    for (int p; (p = o >> 1) && cmp(o, p); Swap(o, p), o = p)
      ;
  }
  void down(int o) {
    for (int p; (p = o << 1) <= siz; o = p) {
      if (p < siz && cmp(p + 1, p)) p++;
      if (cmp(p, o)) {
        Swap(o, p);
        continue;
      }
      break;
    }
  }
  void Push(long long v) {
    s[++siz] = v;
    up(siz);
  }
  long long Pop() {
    Swap(1, siz--);
    down(1);
    return s[siz + 1];
  }
} Heap;
int main() {
  int n, m, b, c;
  register int i, j;
  scanf("%d%d%d%d", &n, &m, &b, &c);
  for (i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  b = min(5 * c, b);
  for (i = 0; i <= 4; ++i) {
    Heap.clear();
    long long BIG((100000000000000000ll) + i), tot(0);
    for (j = 1; j <= n; ++j) {
      long long now = (BIG - a[j]) / 5 * b + (BIG - a[j]) % 5 * c;
      tot += now;
      Heap.Push(now);
      if (Heap.size() > m) tot -= Heap.Pop();
      if (Heap.size() == m) ans = min(ans, tot - (BIG - a[j]) / 5 * b * m);
    }
  }
  printf("%I64d", ans);
  return 0;
}
