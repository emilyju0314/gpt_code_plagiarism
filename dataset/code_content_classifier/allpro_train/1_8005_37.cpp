#include <bits/stdc++.h>
using namespace std;
const int MAXL = 40000;
pair<int, int> p[MAXL];
int Init() {
  for (int i = 0; i * i < MAXL; i++) {
    for (int j = i; j * j + i * i < MAXL; j++) {
      int now = i * i + j * j;
      p[now].first = i;
      p[now].second = j;
    }
  }
  return 0;
}
inline bool cmp(pair<int, int> a, pair<int, int> b) {
  return atan2(a.second, a.first) < atan2(b.second, b.first) - (1e-8);
}
int L(int a, int b) { return a * a + b * b; }
int n;
int Solve() {
  vector<pair<int, int> > e;
  int sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < MAXL && e.size() <= n; i++) {
    if (p[i].first == 0 && p[i].second == 0) continue;
    sum ^= p[i].first ^ p[i].second;
    e.push_back(p[i]);
  }
  reverse(e.begin(), e.end());
  for (vector<pair<int, int> >::iterator it = e.begin(); it != e.end(); it++) {
    if (((sum ^ it->first ^ it->second) & 1) == 0) {
      e.erase(it);
      break;
    }
  }
  int ix = 0, iy = 0;
  for (vector<pair<int, int> >::iterator it = e.begin(); it != e.end(); it++) {
    int fx = 1, fy = 1;
    int xx = it->first, yy = it->second;
    if (ix > 0) fx = -1;
    if (iy > 0) fy = -1;
    if (L(fx * xx + ix, fy * yy + iy) < L(fx * yy + ix, fy * xx + iy))
      *it = make_pair(fx * xx, fy * yy);
    else
      *it = make_pair(fx * yy, fy * xx);
    ix = it->first + ix;
    iy = it->second + iy;
  }
  sort(e.begin(), e.end(), cmp);
  puts("YES");
  for (vector<pair<int, int> >::iterator it = e.begin(); it != e.end(); it++) {
    printf("%d %d\n", ix, iy);
    ix += it->first;
    iy += it->second;
  }
  return 0;
}
int main() {
  Init();
  Solve();
  return 0;
}
