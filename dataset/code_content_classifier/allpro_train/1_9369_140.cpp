#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * neg;
}
inline void print(long long x) {
  if (x < 0) {
    putchar('-');
    print(abs(x));
    return;
  }
  if (x <= 9)
    putchar(x + '0');
  else {
    print(x / 10);
    putchar(x % 10 + '0');
  }
}
long long p[200005], a[200005], n = read();
struct SegTree {
  struct node {
    long long l, r, val, mn;
  } s[800005];
  inline long long query_sum(long long k, long long l, long long r) {
    if (l > r) return 0;
    if (l <= s[k].l && s[k].r <= r) {
      return s[k].val;
    }
    long long mid = (s[k].l + s[k].r) >> 1;
    if (r <= mid)
      return query_sum(k << 1, l, r);
    else if (l > mid)
      return query_sum(k << 1 | 1, l, r);
    else
      return query_sum(k << 1, l, mid) + query_sum(k << 1 | 1, mid + 1, r);
  }
  inline void build(long long k, long long l, long long r) {
    s[k].l = l;
    s[k].r = r;
    if (l == r) {
      s[k].val = s[k].mn = a[l];
      return;
    }
    long long mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    s[k].val = s[k << 1].val + s[k << 1 | 1].val;
    s[k].mn = max(s[k << 1 | 1].mn, s[k << 1 | 1].val + s[k << 1].mn);
  }
  inline void modify(long long k, long long ind, long long x) {
    if (s[k].l == s[k].r) {
      s[k].val -= x * 2;
      s[k].mn = s[k].val;
      return;
    }
    long long mid = (s[k].l + s[k].r) >> 1;
    if (ind <= mid)
      modify(k << 1, ind, x);
    else
      modify(k << 1 | 1, ind, x);
    s[k].val = s[k << 1].val + s[k << 1 | 1].val;
    s[k].mn = max(s[k << 1 | 1].mn, s[k << 1 | 1].val + s[k << 1].mn);
  }
  inline long long query(long long k, long long l, long long r) {
    if (l > r) return 0;
    if (l <= s[k].l && s[k].r <= r) {
      return s[k].mn;
    }
    long long mid = (s[k].l + s[k].r) >> 1;
    if (r <= mid)
      return query(k << 1, l, r);
    else if (l > mid)
      return query(k << 1 | 1, l, r);
    else
      return max(query(k << 1 | 1, mid + 1, r),
                 query_sum(k << 1 | 1, mid + 1, r) + query(k << 1, l, mid));
  }
} st;
long long pos[200005], sum = 0;
signed main() {
  for (long long i = 1; i <= n; i++) p[i] = read(), pos[p[i]] = i;
  for (long long i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  st.build(1, 1, n);
  long long ans = 0x3f3f3f3f;
  ans = min(ans, sum - st.query(1, 2, n));
  for (long long i = 1; i <= n; i++) {
    st.modify(1, pos[i], a[pos[i]]);
    sum -= a[pos[i]];
    ans = min(ans, sum - st.query(1, 2, n));
  }
  cout << ans << endl;
  return 0;
}
