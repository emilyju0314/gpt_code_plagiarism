#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int arr[maxn];
long long a[maxn];
int n, m;
int max_suf[4 * maxn], max_pre[4 * maxn], max_wid[4 * maxn];
int sign(long long x) { return x < 0 ? -1 : 1; }
int S(int i, int j) { return j - i + 1; }
int p;
int upd_wid(int o, int L, int R) {
  int M = L + (R - L) / 2;
  if (L == R)
    return max_wid[o] = a[L] ? 1 : 0;
  else {
    int w1, w2, w3;
    if (p <= M) {
      w1 = upd_wid(2 * o, L, M);
      w2 = max_wid[2 * o + 1];
    } else {
      w1 = max_wid[2 * o];
      w2 = upd_wid(2 * o + 1, M + 1, R);
    }
    w3 = a[M] && a[M + 1] && sign(a[M + 1]) <= sign(a[M])
             ? S(max_suf[2 * o], M) + S(M + 1, max_pre[2 * o + 1])
             : 0;
    int ans = max(w1, w2);
    ans = max(ans, w3);
    return max_wid[o] = ans;
  }
}
int upd_suf(int o, int L, int R) {
  int M = L + (R - L) / 2;
  if (L == R)
    return max_suf[o] = L;
  else {
    int s1, s2;
    if (p <= M) {
      s1 = upd_suf(2 * o, L, M);
      s2 = max_suf[2 * o + 1];
    } else {
      s2 = upd_suf(2 * o + 1, M + 1, R);
      s1 = max_suf[2 * o];
    }
    int ans = s2;
    if (s2 == M + 1 && a[M] && a[M + 1] && sign(a[M + 1]) <= sign(a[M]))
      ans = s1;
    return max_suf[o] = ans;
  }
}
int upd_pre(int o, int L, int R) {
  int M = L + (R - L) / 2;
  if (L == R)
    return max_pre[o] = L;
  else {
    int p1, p2;
    if (p <= M) {
      p1 = upd_pre(2 * o, L, M);
      p2 = max_pre[2 * o + 1];
    } else {
      p2 = upd_pre(2 * o + 1, M + 1, R);
      p1 = max_pre[2 * o];
    }
    int ans = p1;
    if (p1 == M && a[M] && a[M + 1] && sign(a[M + 1]) <= sign(a[M])) ans = p2;
    return max_pre[o] = ans;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for (int i = 1; i < n; i++) {
    a[i] = arr[i + 1] - arr[i];
    p = i;
    upd_pre(1, 1, n - 1);
    upd_suf(1, 1, n - 1);
    upd_wid(1, 1, n - 1);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int l, r, v;
    scanf("%d%d%d", &l, &r, &v);
    int wid;
    if (n != 1) {
      p = l - 1;
      a[l - 1] += v;
      upd_pre(1, 1, n - 1);
      upd_suf(1, 1, n - 1);
      upd_wid(1, 1, n - 1);
      p = r;
      a[r] -= v;
      upd_pre(1, 1, n - 1);
      upd_suf(1, 1, n - 1);
      upd_wid(1, 1, n - 1);
      wid = max_wid[1] + 1;
    } else
      wid = 1;
    printf("%d\n", wid);
  }
}
