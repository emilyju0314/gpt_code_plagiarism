#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
const int offset = (1 << 19);
const int inf = (1 << 30);
struct tournament {
  vector<int> v[offset * 2];
  void update(int x, int y) {
    x += offset;
    v[x].push_back(y);
  }
  void built() {
    for (int i = offset - 1; i > 0; i--) {
      int pt = 0, pt1 = 0;
      int a = i * 2, b = i * 2 + 1;
      while (pt != (int)v[a].size() || pt1 != (int)v[b].size()) {
        if (pt == (int)v[a].size()) {
          v[i].push_back(v[b][pt1]);
          pt1++;
        } else if (pt1 == (int)v[b].size()) {
          v[i].push_back(v[a][pt]);
          pt++;
        } else if (v[a][pt] < v[b][pt1]) {
          v[i].push_back(v[a][pt]);
          pt++;
        } else {
          v[i].push_back(v[b][pt1]);
          pt1++;
        }
      }
    }
    for (int i = (1); i < int(offset * 2); i++) v[i].push_back(inf);
  }
  int get(int cvor, int lt, int rt, int a, int b, int x) {
    if (lt > b || rt < a) return 0;
    if (lt >= a && rt <= b)
      return lower_bound((v[cvor]).begin(), (v[cvor]).end(), x) -
             v[cvor].begin();
    int mid = (lt + rt) >> 1;
    int r1, r2;
    r1 = r2 = 0;
    r1 = get(cvor * 2, lt, mid, a, b, x);
    r2 = get(cvor * 2 + 1, mid + 1, rt, a, b, x);
    return r1 + r2;
  }
} T;
int n, l[MAXN], r[MAXN], p[MAXN * 3], ans[MAXN * 3];
vector<int> v;
int main() {
  scanf("%d", &n);
  for (int i = (0); i < int(n); i++) {
    scanf("%d %d", &l[i], r + i);
    v.push_back(l[i]);
    v.push_back(r[i]);
  }
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  int M = 0;
  for (int i = (0); i < int(n); i++) {
    l[i] = lower_bound((v).begin(), (v).end(), l[i]) - v.begin() + 1;
    r[i] = lower_bound((v).begin(), (v).end(), r[i]) - v.begin() + 1;
    M = max(M, r[i]);
  }
  M++;
  for (int i = (0); i < int(n); i++) p[l[i]] = r[i];
  for (int i = (0); i < int(M); i++)
    if (p[i]) T.update(i, p[i]);
  T.built();
  for (int i = (0); i < int(M); i++)
    if (p[i]) ans[i] = T.get(1, 0, offset - 1, i, p[i], p[i]);
  for (int i = (0); i < int(n); i++) printf("%d\n", ans[l[i]]);
  return 0;
}
