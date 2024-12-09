#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
struct data {
  int x, y, id, sgn;
  data(int x = 0, int y = 0, int id = 0, int sgn = 0)
      : x(x), y(y), id(id), sgn(sgn) {}
  inline bool operator<(const data& a) const {
    return x == a.x ? y < a.y : x < a.x;
  }
};
LL ans[N];
int q[N << 3];
int r[N], b[N];
void add(int u) {
  for (; u < N; u += u & -u) b[u]++;
}
int calc(int u) {
  int ans = 0;
  for (; u > 0; u -= u & -u) ans += b[u];
  return ans;
}
vector<data> all;
void add(int a, int b, int c, int d, int t) {
  all.push_back(data(c, d, t, 1));
  if (a > 1) {
    all.push_back(data(a - 1, d, t, -1));
    if (b > 1) all.push_back(data(a - 1, b - 1, t, 1));
  }
  if (b > 1) all.push_back(data(c, b - 1, t, -1));
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", r + i);
  for (int i = 1, a, b, c, d; i <= m; i++) {
    ans[i] = 1ll * n * (n - 1) / 2;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > 1) {
      add(1, 1, a - 1, n, i * 8 + 0);
      if (b > 1) add(1, 1, a - 1, b - 1, i * 8 + 4);
      if (d < n) add(1, d + 1, a - 1, n, i * 8 + 5);
    }
    if (c < n) {
      add(c + 1, 1, n, n, i * 8 + 1);
      if (b > 1) add(c + 1, 1, n, b - 1, i * 8 + 6);
      if (d < n) add(c + 1, d + 1, n, n, i * 8 + 7);
    }
    if (b > 1) add(1, 1, n, b - 1, i * 8 + 2);
    if (d < n) add(1, d + 1, n, n, i * 8 + 3);
  }
  sort(all.begin(), all.end());
  auto a = all.begin();
  for (int i = 1; i <= n; i++) {
    add(r[i]);
    for (; a != all.end() && a->x == i; a++) {
      q[a->id] += (a->sgn) * calc(a->y);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i * 8; j < (i + 1) * 8; j++) {
      if (j < i * 8 + 4)
        ans[i] -= 1ll * q[j] * (q[j] - 1) / 2;
      else
        ans[i] += 1ll * q[j] * (q[j] - 1) / 2;
    }
    printf("%I64d\n", ans[i]);
  }
  return 0;
}
