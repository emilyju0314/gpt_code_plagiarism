#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[300007];
long long ara[300007], tree[1200002], mx = 1000000222222222222;
void update(long long nd, long long l, long long r, long long x, long long y,
            long long val) {
  if (l > y || r < x)
    return;
  else if (l >= x && r <= y) {
    tree[nd] = val;
    return;
  } else {
    long long lt, rt, md, fq, sq, tq;
    lt = nd << 1;
    rt = lt + 1;
    md = (l + r) >> 1;
    update(lt, l, md, x, y, val);
    update(rt, md + 1, r, x, y, val);
    tree[nd] = min(tree[lt], tree[rt]);
  }
}
long long query(long long nd, long long l, long long r, long long x,
                long long y) {
  if (l > y || r < x)
    return mx;
  else if (l >= x && r <= y) {
    return tree[nd];
  } else {
    long long lt, rt, md, fq, sq, tq;
    lt = nd << 1;
    rt = lt + 1;
    md = (l + r) >> 1;
    fq = query(lt, l, md, x, y);
    sq = query(rt, md + 1, r, x, y);
    tq = min(fq, sq);
    return tq;
  }
}
int main() {
  long long n, m, a, b, c, d, i, j, k, x, y, fr, sc, tr,
      p = 0, q, r, s = -2, t, idx, val, ans, e, f, g, h = 0, st, fn;
  vector<pair<long long, long long> > vct;
  vector<long long> v;
  map<long long, long long> mp;
  scanf("%lld %lld %lld", &n, &x, &y);
  n--;
  for (i = 1; i <= n; i++) {
    scanf("%lld %lld", &a, &b);
    vct.push_back(make_pair(a, b));
    v.push_back(a);
    s = max(s, a);
  }
  sort(vct.begin(), vct.end());
  sort(v.begin(), v.end());
  if (x >= s)
    printf("1\n");
  else {
    vector<long long>::iterator it;
    for (i = n - 1; i >= 0; i--) {
      fr = vct[i].first;
      sc = vct[i].second;
      t = sc - fr + 1;
      update(1, 1, n, i + 1, i + 1, t);
      if (mp[t] == 0) {
        p++;
        mp[t] = p;
      }
      q = mp[t];
      adj[q].push_back(i + 1);
    }
    it = upper_bound(v.begin(), v.end(), x);
    idx = it - v.begin();
    ans = n - idx;
    ans++;
    while (1) {
      if (x == 0) break;
      it = upper_bound(v.begin(), v.end(), x);
      idx = it - v.begin();
      st = idx + 1;
      fn = n;
      f = query(1, 1, n, st, fn);
      if (f > x) {
        break;
      } else {
        x = x - f;
        h++;
        it = upper_bound(v.begin(), v.end(), x);
        idx = it - v.begin();
        e = n - idx;
        e = e - h;
        e++;
        ans = min(ans, e);
        if (ans == 1)
          break;
        else {
          m = mp[f];
          d = ara[m];
          g = adj[m][d];
          ara[m]++;
          update(1, 1, n, g, g, mx);
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
