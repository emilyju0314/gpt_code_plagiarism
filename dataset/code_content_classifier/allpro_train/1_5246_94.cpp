#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int maxn = 1e4 + 50;
const int maxm = 5e5 + 50;
int k;
int ans[maxm];
struct Node {
  int id, x, r, flag, f, val;
  Node() { id = x = r = flag = f = val = 0; }
  Node(int a, int b, int c, int d, int e, int g) {
    id = a;
    x = b;
    r = c;
    flag = d;
    f = e;
    val = g;
  }
  bool operator<(const Node &b) {
    if (x == b.x) {
      if (f == b.f) return flag < b.flag;
      return f < b.f;
    }
    return x < b.x;
  }
} nod[maxm], tmp[maxm];
struct In {
  int r, x, f;
} input[maxm];
int cmp(const In &a, const In &b) {
  if (a.r == b.r) {
    if (a.x == b.x) return a.f < b.f;
    return a.x < b.x;
  }
  return a.r > b.r;
}
struct bit {
  int a[maxn];
  int lowbit(int x) { return x & -x; }
  void add(int i) {
    for (int k = i; k < maxn; k += lowbit(k)) a[k]++;
  }
  int query(int i) {
    int sum = 0;
    for (int j = i; j > 0; j -= lowbit(j)) sum += a[j];
    return sum;
  }
};
bit b;
void cdq(int l, int r) {
  if (l == r) return;
  cdq(l, (l + r) / 2);
  cdq((l + r) / 2 + 1, r);
  int p = l, q = (l + r) / 2 + 1, cnt = 0;
  while (p <= (l + r) / 2 && q <= r) {
    if (nod[p] < nod[q]) {
      if (!nod[p].flag) b.add(nod[p].f);
      tmp[cnt++] = nod[p++];
    } else {
      if (nod[q].flag && nod[q].x > 0 && nod[q].f > 0)
        ans[nod[q].id] += nod[q].val * b.query(nod[q].f);
      tmp[cnt++] = nod[q++];
    }
  }
  while (p <= (l + r) / 2) tmp[cnt++] = nod[p++];
  while (q <= r) {
    if (nod[q].flag && nod[q].x > 0) {
      if (nod[q].f > 0) ans[nod[q].id] += nod[q].val * b.query(nod[q].f);
    }
    tmp[cnt++] = nod[q++];
  }
  for (int i = 0; i < maxn; i++) b.a[i] = 0;
  for (int i = l; i <= r; i++) nod[i] = tmp[i - l];
}
int main() {
  int m, cnt = 0;
  scanf("%d%d", &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &input[i].x, &input[i].r, &input[i].f);
  }
  sort(input, input + m, cmp);
  for (int i = 0; i < m; i++) {
    int a = input[i].x, b = input[i].r, c = input[i].f;
    nod[++cnt] = Node(cnt, a, b, 0, c, 0);
    nod[++cnt] = Node(cnt - 1, a - b - 1, b, 1, c - k - 1, 1);
    nod[++cnt] = Node(cnt - 2, a + b, b, 1, c + k, 1);
    nod[++cnt] = Node(cnt - 3, a - b - 1, b, 1, c + k, -1);
    nod[++cnt] = Node(cnt - 4, a + b, b, 1, c - k - 1, -1);
  }
  cdq(1, cnt);
  long long sum = 0;
  for (int i = 0; i < maxm; i++) sum += ans[i];
  cout << sum - (long long)m;
  return 0;
}
