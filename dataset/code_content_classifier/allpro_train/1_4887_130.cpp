#include <bits/stdc++.h>
using namespace std;
int a[500010];
int ans[500010], an;
void push(int k) { ans[an++] = k; }
const int N = 1 << 19;
int b[1 << 20];
void update(int i, int x) {
  i += N;
  b[i] = x;
  while (i > 1) {
    i >>= 1;
    b[i] = min(b[i + i], b[i + i + 1]);
  }
}
int query(int l, int r, int p = 1, int L = 0, int R = N) {
  if (r <= L || R <= l) return N;
  if (l <= L && R <= r) return b[p];
  int mid = (L + R) / 2;
  return min(query(l, r, p + p, L, mid), query(l, r, p + p + 1, mid, R));
}
map<int, int> m, c;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < N + N; i++) {
    b[i] = N;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (!m.count(a[i])) {
      m[a[i]] = i;
      continue;
    }
    if (c[a[i]] >= 2) {
      for (int j = 0; j < 4; j++) {
        push(a[i]);
      }
      c.clear();
      m.clear();
      continue;
    }
    int j = query(m[a[i]] + 1, i);
    if (j < m[a[i]]) {
      push(a[j]);
      push(a[i]);
      push(a[j]);
      push(a[i]);
      c.clear();
      m.clear();
      continue;
    }
    update(i, m[a[i]]);
    c[a[i]]++;
  }
  printf("%d\n", an);
  for (int i = 0; i < an; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
