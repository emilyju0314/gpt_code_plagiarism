#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
const int WOW = 40000;
const int NIL = 0;
const int dy[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int N;
vector<int> rows, cols;
bool f(int y1, int x1, int y2, int x2) {
  if (y1 == 0 || x1 == 0 || y2 == 0 || x2 == 0) return 0;
  printf("? %d %d %d %d\n", y1, x1, y2, x2);
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v & 1;
}
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i)
    if (f(1, i, N, i)) cols.push_back(i);
  if (cols.size() == 1)
    cols.push_back(N);
  else if (cols.size() == 0) {
    for (int i = 1; i < N; ++i)
      if (f(i, 1, i, N)) rows.push_back(i);
    if (rows.size() == 1) rows.push_back(N);
  }
  if (cols.size()) {
    for (int x : cols) {
      int l = 0, r = N;
      while (l + 1 != r) {
        int m = (l + r) >> 1;
        if (f(1, x, m, x))
          r = m;
        else
          l = m;
      }
      ans.push_back({r, x});
    }
  } else {
    for (int y : rows) {
      int l = 0, r = N;
      while (l + 1 != r) {
        int m = (l + r) >> 1;
        if (f(y, 1, y, m))
          r = m;
        else
          l = m;
      }
      ans.push_back({y, r});
    }
  }
  printf("! ");
  for (pair<int, int> p : ans) printf("%d %d ", p.first, p.second);
}
