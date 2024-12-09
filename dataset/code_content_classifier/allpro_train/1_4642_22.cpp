#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
T expo(T base, T e, T mod) {
  T res = 1;
  while (e > 0) {
    if (e & 1) res = res * base % mod;
    base = base * base % mod;
    e >>= 1;
  }
  return res;
}
template <typename T, typename second>
T expo(T b, second e) {
  if (e <= 1) return e == 0 ? 1 : b;
  return (e & 1) == 0 ? expo((b * b), e >> 1) : (b * expo((b * b), e >> 1));
}
template <typename T, typename second>
T modinv(T a, second mod) {
  return expo(a, mod - 2, mod);
}
template <class T, class second>
std::ostream &operator<<(std::ostream &os, const std::pair<T, second> &t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &t) {
  os << "[";
  for (__typeof(t.begin()) it = t.begin(); it != t.end(); it++) {
    if (it != t.begin()) os << ", ";
    os << *it;
  }
  os << "]";
  return os;
}
template <typename T>
void in(T &x) {
  T c = getchar();
  while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
  bool neg = false;
  if (c == '-') neg = true;
  x = 0;
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x * 10) + (c - 48);
  if (neg) x = -x;
}
const int MAXN = 35000 + 100;
const int MAXK = 53;
const long long INF = 1e14;
long long n, k;
long long arr[MAXN];
long long dp[MAXK][MAXN];
int P[MAXN], last[MAXN];
struct node {
  long long val;
  long long lazy;
  void merge(node &l, node &r) { val = max(l.val, r.val); }
  void split(node &l, node &r) {
    if (l.val > -INF) {
      l.val += lazy;
    }
    if (r.val > -INF) {
      r.val += lazy;
    }
    l.lazy += lazy, r.lazy += lazy;
    lazy = 0;
  }
} tree[MAXN * 4];
void build(int k, int root, int l, int r) {
  tree[root].val = -INF;
  tree[root].lazy = 0;
  if (l == r) {
    tree[root].val = dp[k][l];
    return;
  }
  int mid = (l + r) / 2;
  build(k, root * 2, l, mid);
  build(k, root * 2 + 1, mid + 1, r);
  tree[root].merge(tree[root * 2], tree[root * 2 + 1]);
}
void update(int ql, int qr, long long add, int root, int l, int r) {
  if (ql <= l && qr >= r) {
    if (tree[root].val > -INF) {
      tree[root].val += add;
    }
    tree[root].lazy += add;
    return;
  } else if (ql > r || qr < l)
    return;
  tree[root].split(tree[root * 2], tree[root * 2 + 1]);
  int mid = (l + r) >> 1;
  update(ql, qr, add, root * 2, l, mid);
  update(ql, qr, add, root * 2 + 1, mid + 1, r);
  tree[root].merge(tree[root * 2], tree[root * 2 + 1]);
}
long long query(int idx, int root, int l, int r) {
  if (idx >= r) {
    return tree[root].val;
  } else if (l > idx)
    return -INF;
  int mid = (l + r) >> 1;
  tree[root].split(tree[root * 2], tree[root * 2 + 1]);
  long long res = -INF;
  res = max(res, query(idx, root * 2, l, mid));
  res = max(res, query(idx, root * 2 + 1, mid + 1, r));
  tree[root].merge(tree[root * 2], tree[root * 2 + 1]);
  return res;
}
int main() {
  in(n), in(k);
  for (int i = 1; i <= n; i++) {
    P[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    in(arr[i]);
    P[i] = last[arr[i]];
    last[arr[i]] = i;
  }
  fill(&dp[0][0], &dp[0][0] + MAXN * MAXK, -INF);
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    build(i - 1, 1, 0, n);
    dp[i][i] = i;
    for (int x = 1; x <= i; x++) {
      update(P[x], x - 1, 1, 1, 0, n);
    }
    for (int j = i + 1; j <= n; j++) {
      update(P[j], j - 1, 1, 1, 0, n);
      dp[i][j] = query(j - 1, 1, 0, n);
      assert(dp[i][j] > 0);
    }
  }
  printf("%lld\n", dp[k][n]);
  return 0;
}
