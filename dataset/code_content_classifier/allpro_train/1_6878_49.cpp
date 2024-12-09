#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
const int maxn = 4005, maxq = 20005;
int n, p, q;
int res[maxq];
struct ks {
  int h[maxn];
  ks() { fill(h, h + maxn, 0); }
  void add(int c, int happiness) {
    for (int i = maxn - 1; i >= c; --i) {
      h[i] = max(h[i], h[i - c] + happiness);
    }
  }
};
struct obj {
  int c, h, t;
};
vector<obj> a;
struct query {
  int t, b, i;
};
vector<query> qu[1 << 15];
int go(ks &a, int c) {
  int res = 0;
  for (int i = 0; i <= c; ++i) {
    res = max(res, a.h[i]);
  }
  return res;
}
inline void calc(int l, int r, vector<obj> a, ks b) {
  int md = (l + r) / 2;
  ks now = b;
  vector<obj> L, R;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i].t <= l && a[i].t + p >= r) {
      now.add(a[i].c, a[i].h);
      continue;
    }
    if (a[i].t + p - 1 >= l && a[i].t < md) {
      L.push_back(a[i]);
    }
    if (a[i].t < r && a[i].t + p - 1 >= md) {
      R.push_back(a[i]);
    }
  }
  if (l + 1 == r) {
    for (int i = 0; i < qu[l].size(); ++i) {
      res[qu[l][i].i] = go(now, qu[l][i].b);
    }
    return;
  }
  calc(l, md, L, now);
  calc(md, r, R, now);
}
void gen() {
  freopen("input.txt", "wt", stdout);
  n = 4000;
  p = 3000;
  q = 20000;
  cout << n << " " << p << endl;
  srand(time(NULL));
  for (int i = 0; i < 4000; ++i) {
    cout << (rand() << 16 | rand()) % 4000 << " "
         << (rand() << 16 | rand()) % 4000 << " "
         << (rand() << 16 | rand()) % 20000 << endl;
  }
  for (int i = 0; i < q; ++i) {
    cout << (rand() << 16 | rand()) % 20000 << " "
         << (rand() << 16 | rand()) % 4000 << endl;
  }
}
int main(void) {
  scanf("%d %d", &n, &p);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &a[i].c, &a[i].h, &a[i].t);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    query b;
    scanf("%d %d", &b.t, &b.b);
    b.i = i;
    qu[b.t].push_back(b);
  }
  calc(0, (1 << 15), a, ks());
  for (int i = 0; i < q; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}
