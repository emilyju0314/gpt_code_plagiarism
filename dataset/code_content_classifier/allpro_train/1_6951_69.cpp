#include <bits/stdc++.h>
using namespace std;
long long n, N, sum, p[4 * 4];
bool ok(vector<long long> v) {
  sort(v.begin(), v.end());
  for (long long i = 0; i < N; i++)
    if (p[i] != v[i]) return false;
  return true;
}
long long cnt[4 * 4], ans[4][4], lef[4 * 4 - 4];
vector<vector<long long> > v, vec;
set<pair<pair<long long, long long>, pair<long long, long long> > > st;
bool ok(vector<long long> v, bool flag) {
  sort(v.begin(), v.end());
  pair<pair<long long, long long>, pair<long long, long long> > pa =
      make_pair(make_pair(v[0], v[1]), make_pair(v[2], v[3]));
  if (st.find(pa) == st.end()) {
    if (flag) {
      st.insert(pa);
    }
    return true;
  }
  return false;
}
bool can(vector<long long> v) {
  for (long long i = 0; i < n; i++) {
    if (cnt[v[i]] < 3) return false;
    v[i] = p[v[i]];
  }
  return ok(v, true);
}
bool ok() {
  long long s = 0;
  for (long long r = 0; r < n; r++) s += ans[r][n - 1];
  if (s != sum) return false;
  s = 0;
  for (long long c = 0; c < n; c++) s += ans[n - 1][c];
  if (s != sum) return false;
  vector<long long> v;
  for (long long r = 0; r < n; r++)
    for (long long c = 0; c < n; c++) v.push_back(ans[r][c]);
  return ok(v);
}
void out() {
  printf("%lld", sum);
  for (long long r = 0; r < n; r++) {
    printf("\n");
    for (long long c = 0; c < n; c++) {
      if (c) printf(" ");
      printf("%lld", ans[r][c]);
    }
  }
}
bool cal(vector<long long> id) {
  multiset<long long> se = multiset<long long>(p, p + N);
  for (long long i = 0; i < n; i++) {
    ans[i][i] = p[id[i]];
    se.erase(se.find(ans[i][i]));
  }
  long long N = 0;
  for (multiset<long long>::iterator it = se.begin(); it != se.end(); it++)
    lef[N++] = *it;
  for (long long i = 0; i < N; i++) {
    for (long long k = 0; k < N; k++) {
      if (k == i) continue;
      for (long long h = 0; h < N; h++) {
        if (h == k || h == i) continue;
        for (long long t = 0; t < N; t++) {
          if (t == h || t == k || t == i) continue;
          ans[0][3] = lef[i];
          ans[1][2] = lef[k];
          ans[2][1] = sum - (ans[1][1] + ans[1][2] + ans[2][2]);
          ans[3][0] = sum - (ans[0][3] + ans[1][2] + ans[2][1]);
          vector<long long> v;
          v.resize(n);
          v[0] = ans[0][3];
          v[1] = ans[1][2];
          v[2] = ans[2][1];
          v[3] = ans[3][0];
          if (ok(v, false)) continue;
          ans[0][1] = lef[h];
          ans[0][2] = sum - (ans[0][0] + ans[0][1] + ans[0][3]);
          ans[3][1] = sum - (ans[0][1] + ans[1][1] + ans[2][1]);
          ans[3][2] = sum - (ans[0][2] + ans[1][2] + ans[2][2]);
          ans[1][0] = lef[t];
          ans[2][0] = sum - (ans[0][0] + ans[1][0] + ans[3][0]);
          ans[1][3] = sum - (ans[1][0] + ans[1][1] + ans[1][2]);
          ans[2][3] = sum - (ans[2][0] + ans[2][1] + ans[2][2]);
          if (ok()) {
            out();
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  long long i, k, h, t, r, c;
  vector<vector<long long> > a;
  vector<long long> b, ret, id;
  scanf("%lld", &n);
  if (n <= 2) {
    scanf("%lld", &i);
    if (n == 1)
      printf("%lld\n%lld", i, i);
    else
      printf("%lld\n%lld %lld\n%lld %lld", (i << 1), i, i, i, i);
    return 0;
  }
  N = n * n;
  for (i = 0; i < N; i++) {
    scanf("%lld", p + i);
    sum += p[i];
  }
  sort(p, p + N);
  sum /= n;
  if (n == 3) {
    for (i = 0; i < N; i++) {
      for (k = 0; k < N; k++) {
        if (k == i) continue;
        for (h = 0; h < N; h++) {
          if (h == k || h == i) continue;
          ans[0][0] = p[i];
          ans[1][1] = p[k];
          ans[0][2] = p[h];
          ans[2][2] = sum - (ans[0][0] + ans[1][1]);
          ans[2][0] = sum - (ans[0][2] + ans[1][1]);
          ans[0][1] = sum - (ans[0][0] + ans[0][2]);
          ans[1][0] = sum - (ans[0][0] + ans[2][0]);
          ans[1][2] = sum - (ans[1][0] + ans[1][1]);
          ans[2][1] = sum - (ans[0][1] + ans[1][1]);
          if (ok()) {
            out();
            return 0;
          }
        }
      }
    }
  }
  id.resize(n);
  for (i = 0; i < N; i++)
    for (k = i + 1; k < N; k++)
      for (h = k + 1; h < N; h++)
        for (t = h + 1; t < N; t++) {
          if (p[i] + p[k] + p[h] + p[t] != sum) continue;
          cnt[i]++;
          cnt[k]++;
          cnt[h]++;
          cnt[t]++;
          id[0] = i;
          id[1] = k;
          id[2] = h;
          id[3] = t;
          v.push_back(id);
        }
  for (i = 0; i < v.size(); i++) {
    if (!can(v[i])) continue;
    vec.push_back(v[i]);
  }
  for (i = 0; i < vec.size(); i++) {
    if (cal(vec[i])) break;
    swap(vec[i][1], vec[i][3]);
    if (cal(vec[i])) break;
    swap(vec[i][2], vec[i][3]);
    if (cal(vec[i])) break;
  }
  return 0;
}
