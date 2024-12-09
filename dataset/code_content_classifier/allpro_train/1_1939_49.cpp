#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 100500;
int n, m, q;
int a[N];
bool used[N];
bool isHeavy[N];
long long add[N];
long long sum[N];
vector<int> g[N];
long long light[N];
vector<pair<int, int> > szOfInter[N];
int getIntersection(int id) {
  int ret = 0;
  for (size_t j = 0; j < g[id].size(); j++) {
    int idx = g[id][j];
    if (used[idx]) {
      ++ret;
    }
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int maxLightSize = 334;
  for (int i = 1; i <= m; i++) {
    int sz;
    scanf("%d", &sz);
    sum[i] = 0LL;
    for (int j = 1; j <= sz; j++) {
      int val;
      scanf("%d", &val);
      g[i].push_back(val);
      sum[i] += (1LL * a[val]);
    }
    sort(g[i].begin(), g[i].end());
    if (sz > maxLightSize) {
      isHeavy[i] = true;
    } else {
      isHeavy[i] = false;
    }
    if (i == m) {
      scanf("\n");
    }
  }
  vector<int> heavy;
  for (int i = 1; i <= n; i++) {
    if (!isHeavy[i]) {
      continue;
    }
    for (int j = 1; j <= n; j++) {
      used[j] = false;
    }
    for (size_t j = 0; j < g[i].size(); j++) {
      used[g[i][j]] = true;
    }
    for (int j = 1; j <= n; j++) {
      int sz = getIntersection(j);
      if (!isHeavy[j]) {
        szOfInter[j].push_back(make_pair(i, sz));
      } else {
        szOfInter[i].push_back(make_pair(j, sz));
      }
    }
  }
  while (q--) {
    char type;
    scanf("%c", &type);
    if (type == '+') {
      int k, x;
      scanf("%d%d", &k, &x);
      add[k] += (1LL * x);
      if (!isHeavy[k]) {
        for (size_t j = 0; j < g[k].size(); j++) {
          int idx = g[k][j];
          light[idx] += (1LL * x);
        }
        for (size_t j = 0; j < szOfInter[k].size(); j++) {
          int idx = szOfInter[k][j].first;
          int mult = szOfInter[k][j].second;
          sum[idx] += (1LL * mult * x);
        }
      }
    } else {
      int k;
      scanf("%d", &k);
      long long res = 0LL;
      if (isHeavy[k]) {
        res = sum[k];
        for (size_t j = 0; j < szOfInter[k].size(); j++) {
          int idx = szOfInter[k][j].first;
          int mult = szOfInter[k][j].second;
          res = res + (1LL * mult * add[idx]);
        }
      } else {
        for (size_t j = 0; j < g[k].size(); j++) {
          int idx = g[k][j];
          res += (1LL * a[idx] + light[idx]);
        }
        for (size_t j = 0; j < szOfInter[k].size(); j++) {
          int idx = szOfInter[k][j].first;
          int mult = szOfInter[k][j].second;
          res = res + (1LL * mult * add[idx]);
        }
      }
      printf("%I64d\n", res);
    }
    if (q > 0) {
      scanf("\n");
    }
  }
  return 0;
}
