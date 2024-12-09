#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 20;
struct node {
  int l, r, id;
} q[maxn];
int pos[maxn], a[maxn], block, pre[maxn];
long long res[maxn], flag[maxn];
bool cmp(node a, node b) {
  if (a.l / block != b.l / block) return a.l < b.l;
  return a.r < b.r;
}
int n, m, k;
int l = 1, r = 0;
long long ans = 0;
void add(int x) {
  ans += flag[x ^ k];
  flag[x]++;
}
void del(int x) {
  flag[x]--;
  ans -= flag[x ^ k];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  block = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = pre[i - 1] ^ a[i];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m, cmp);
  flag[0] = 1;
  for (int i = 1; i <= m; i++) {
    while (l > q[i].l) l--, add(pre[l - 1]);
    while (l < q[i].l) del(pre[l - 1]), l++;
    while (r < q[i].r) r++, add(pre[r]);
    while (r > q[i].r) del(pre[r]), r--;
    res[q[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << res[i] << endl;
  }
}
