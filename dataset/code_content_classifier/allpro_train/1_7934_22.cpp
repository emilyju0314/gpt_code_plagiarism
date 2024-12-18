#include <bits/stdc++.h>
using namespace std;
const int N = 4 * ((int)(5e5) + 7);
int d[N];
long long sum[N];
long long mn[N];
inline void push(int v, int l, int r) {
  if (d[v] != 0) {
    int m = (l + r) / 2;
    d[v * 2 + 1] = d[v];
    d[v * 2 + 2] = d[v];
    mn[v * 2 + 1] = d[v];
    mn[v * 2 + 2] = d[v];
    sum[v * 2 + 1] = (m - l) * (long long)d[v];
    sum[v * 2 + 2] = (r - m) * (long long)d[v];
    d[v] = 0;
  }
}
inline void upd(int v, int l, int r, int tl, int tr, int x) {
  if (tl >= r || tr <= l) {
    return;
  }
  if (tl >= l && tr <= r) {
    sum[v] = (tr - tl) * (long long)x;
    mn[v] = x;
    d[v] = x;
  } else {
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    upd(v * 2 + 1, l, r, tl, tm, x);
    upd(v * 2 + 2, l, r, tm, tr, x);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
  }
}
inline long long get(int v, int l, int r, int tl, int tr) {
  if (tl >= r || tr <= l) {
    return 0;
  }
  if (tl >= l && tr <= r) {
    return sum[v];
  } else {
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr);
  }
}
struct ev {
  int a, b, c;
};
inline int first_smal(int v, int l, int r, int x) {
  if (r - l == 1) {
    return l;
  } else {
    int m = (l + r) / 2;
    if (mn[v * 2 + 1] < x) {
      return first_smal(v * 2 + 1, l, m, x);
    } else {
      return first_smal(v * 2 + 2, m, r, x);
    }
  }
}
int main() {
  {
    vector<ev> e;
    int n, p, q, r;
    scanf("%d%d%d%d", &n, &p, &q, &r);
    for (int i = 0; i < n; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      e.push_back({a, b, c});
    }
    sort(e.begin(), e.end(), [](ev a, ev b) { return a.a < b.a; });
    for (int i = 0; i < N; i++) {
      sum[i] = d[i] = mn[i] = 0;
    }
    vector<int> vl_(q + 1);
    vector<int> vr_(r + 1);
    int sz = 0;
    for (int i = 0; i < n; i++) {
      sz++;
      vl_[e[i].b]++;
      vr_[e[i].c]++;
    }
    int j = -1;
    long long ans = 0;
    for (int cur = 1; cur <= p; cur++) {
      while (j + 1 < n && e[j + 1].a < cur) {
        j++;
        vl_[e[j].b]--;
        vr_[e[j].c]--;
        sz--;
        int vr = min(max(0, first_smal(0, 0, q + 1, e[j].c)), e[j].b + 1);
        if (vr != e[j].b + 1 && get(0, vr, vr + 1, 0, q + 1) < e[j].c) {
          upd(0, vr, e[j].b + 1, 0, q + 1, e[j].c);
        }
      }
      while (vl_.size() > 0 && vl_.back() == 0) {
        vl_.pop_back();
      }
      while (vr_.size() > 0 && vr_.back() == 0) {
        vr_.pop_back();
      }
      if (vl_.size() == 0) {
        ans += q * (long long)r - get(0, 1, q + 1, 0, q + 1);
      } else {
        int min_b = vl_.size();
        int min_c = vr_.size() - 1;
        if (min_b > q) {
          continue;
        }
        int cur = first_smal(0, 0, q + 1, min_c);
        cur = max(cur, 1);
        cur = max(cur, min_b);
        cur = min(cur, q + 1);
        int vr = cur;
        if (vr == q + 1 || get(0, vr, vr + 1, 0, q + 1) >= min_c) {
          ans +=
              (q - min_b + 1) * (long long)r - get(0, min_b, q + 1, 0, q + 1);
        } else {
          ans += (q - min_b + 1) * (long long)r - get(0, min_b, vr, 0, q + 1) -
                 (q - vr + 1) * (long long)min_c;
        }
      }
    }
    printf("%lld\n", ans);
  }
}
