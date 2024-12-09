#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int desll[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int mod = 998244353;
const int maxn = 1e6 + 7;
const int maxm = 1e6 + 1;
const double eps = 1e-8;
int n, k, m;
int ar[maxn];
long long sum[maxn], ans = 0, len;
map<long long, int> ma;
struct node {
  long long L, R, r, x, q;
} no[maxn];
bool cmp1(node n1, node n2) { return n1.r < n2.r; }
bool cmp2(node n1, node n2) { return n1.q < n2.q; }
void add(int x, int val) {
  while (x <= len) {
    sum[x] += val;
    x += x & (-x);
  }
}
long long que(int x) {
  long long ans = 0;
  while (x > 0) {
    ans += sum[x];
    x -= x & (-x);
  }
  return ans;
}
void dcp(int a, int b) {
  if (a == b) return;
  int mid = (a + b) >> 1;
  dcp(a, mid);
  dcp(mid + 1, b);
  int p1, p2;
  p1 = p2 = mid + 1;
  for (int i = a; i <= mid; i++) {
    while (p2 <= b && no[p2].q <= no[i].q + m) {
      add(no[p2].x, 1);
      p2++;
    }
    while (p1 < p2 && no[p1].q < no[i].q - m) {
      add(no[p1].x, -1);
      p1++;
    }
    ans += que(no[i].R) - que(no[i].L - 1);
  }
  for (int i = p1; i < p2; i++) {
    add(no[i].x, -1);
  }
  inplace_merge(no + a, no + mid + 1, no + b + 1, cmp2);
}
int main() {
  memset(sum, 0, sizeof(sum));
  scanf("%d%d", &n, &m);
  len = 0;
  for (int i = 1; i <= n; i++) {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    no[i].x = a;
    no[i].r = b;
    no[i].q = c;
    no[i].L = a - b;
    no[i].R = a + b;
    ar[++len] = a;
    ar[++len] = a + b;
    ar[++len] = a - b;
  }
  sort(ar + 1, ar + 1 + len);
  len = unique(ar + 1, ar + len + 1) - ar - 1;
  for (int i = 1; i <= len; i++) {
    ma[ar[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    no[i].L = ma[no[i].L];
    no[i].R = ma[no[i].R];
    no[i].x = ma[no[i].x];
  }
  sort(no + 1, no + 1 + n, cmp1);
  dcp(1, n);
  printf("%I64d\n", ans);
  return 0;
}
