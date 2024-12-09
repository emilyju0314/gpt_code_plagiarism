#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> operator/(pair<int, int> a, int b) {
  return make_pair(a.first / b, a.second / b);
}
const int N = 150005;
const int M = 9 * N;
vector<pair<int, int> > pts,
    mv = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
vector<int> E8[M], E4[M];
int n, cmp[M], my[M], ym[N], csz, out;
pair<int, int> a[N];
set<int> act;
bool huo[M];
void Consider(int first) {
  if (huo[first]) act.erase(my[first]);
  bool rch = 0;
  for (int second : E4[first])
    if (cmp[second] == out) rch = 1;
  bool art = 0;
  assert(E8[first].size() == 8);
  for (int i = 0; i < 8; i++) {
    int second = E8[first][i];
    if (cmp[second] == -1) {
      vector<int> qq;
      for (int j = (i + 1) % 8, las = -1, in = 0; j != i; j = (j + 1) % 8) {
        int z = E8[first][j];
        if (las != cmp[z]) las = cmp[z], in = 0;
        if (j % 2 == 1 && !in && las != -1) qq.push_back(las), in = 1;
      }
      sort(qq.begin(), qq.end());
      for (int j = 1; j < qq.size(); j++)
        if (qq[j] == qq[j - 1]) art = 1;
      break;
    }
  }
  huo[first] = rch && !art;
  if (huo[first]) act.insert(my[first]);
}
vector<int> all[M];
void Merge(int a, int b) {
  if (b == out || (a != out && all[a].size() < all[b].size())) swap(a, b);
  for (int i : all[b]) cmp[i] = a, all[a].push_back(i);
  for (int i : all[b])
    for (int j : E4[i])
      if (cmp[j] == -1) Consider(j);
}
int ans[N];
bool was[M];
int main() {
  scanf("%i %*i", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%i %i", &a[i].first, &a[i].second);
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++)
        pts.push_back(make_pair(a[i].first + dx, a[i].second + dy));
  }
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  for (int i = 0; i < pts.size(); i++) {
    for (pair<int, int> d : mv) {
      pair<int, int> b = pts[i] + d;
      int j = lower_bound(pts.begin(), pts.end(), b) - pts.begin();
      if (j < pts.size() && pts[j] == b) {
        E8[i].push_back(j);
        if (d.first * d.second == 0) E4[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int j = lower_bound(pts.begin(), pts.end(), a[i]) - pts.begin();
    cmp[j] = -1;
    my[j] = i;
    ym[i] = j;
  }
  queue<int> q;
  for (int i = 0; i < pts.size(); i++) {
    if (cmp[i] == 0) {
      q.push(i);
      cmp[i] = ++csz;
      while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : E4[u]) {
          if (cmp[v] == 0) {
            cmp[v] = csz;
            q.push(v);
          }
        }
      }
    }
  }
  q.push(ym[1]);
  was[ym[1]] = 1;
  int num = 0;
  while (q.size()) {
    int u = q.front();
    num++;
    q.pop();
    for (int v : E8[u]) {
      if (cmp[v] == -1 && !was[v]) {
        was[v] = 1;
        q.push(v);
      }
    }
  }
  if (num < n) return 0 * printf("NO\n");
  out = cmp[0];
  for (int i = 0; i < pts.size(); i++) {
    if (cmp[i] == -1)
      Consider(i);
    else
      all[cmp[i]].push_back(i);
  }
  for (int pos = n; pos >= 1; pos--) {
    int first = *act.rbegin();
    act.erase(first);
    ans[pos] = first;
    first = ym[first];
    for (int second : E4[first])
      if (cmp[second] != -1) {
        cmp[first] = cmp[second];
        all[cmp[first]].push_back(first);
        break;
      }
    for (int second : E8[first])
      if (cmp[second] == -1) Consider(second);
    for (int second : E4[first])
      if (cmp[second] != -1 && cmp[second] != cmp[first])
        Merge(cmp[first], cmp[second]);
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%i\n", ans[i]);
  return 0;
}
