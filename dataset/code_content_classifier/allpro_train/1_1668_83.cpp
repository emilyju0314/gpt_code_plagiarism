#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};
const int drr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dcc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
class UnionFind {
 private:
  vector<int> rank, p;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) p.push_back(i);
    rank.assign(n, 0);
  }
  int findSet(int s) { return (p[s] == s) ? s : (p[s] = findSet(p[s])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      p[y] = x;
    else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
};
bool fcomp(double A, double B) {
  double EPSILON = numeric_limits<double>::epsilon();
  double diff = A - B;
  return fabs(diff) < EPSILON;
}
double x_y(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  int(c4), (c7);
  scanf("%d %d", &(c4), &(c7));
  int(c47), (c74);
  scanf("%d %d", &(c47), &(c74));
  string res = "";
  int ext = c7 - c47, ys = 1;
  for (int i = 0; i < ext; i++) {
    res += '7';
    c7--;
  }
  for (int i = 0; i < c47; i++) {
    res += "74";
    c4--;
    c7--;
  }
  c74 -= c47 - 1;
  c47 = 0;
  if (c4 < 0 || c7 < 0 || c74 < 0) ys = 0;
  int st = 0, st7 = 0;
  if (c74 > 0 && c4 > 0) {
    c74--;
    st = 1;
    c4--;
  }
  for (int i = 0; i < c4; i++) {
    res += '4';
  }
  c4 = min(c4, 0);
  reverse((res).begin(), (res).end());
  if (c74 > 0 && ext > 0) {
    st7 = 1;
    res.pop_back();
    c74--;
  }
  if (c4 < 0 || c7 < 0 || c74 < 0) ys = 0;
  if (c4 > 0 || c7 > 0 || c74 > 0) ys = 0;
  if (!ys)
    cout << "-1" << endl;
  else {
    if (st7) cout << "7";
    cout << res;
    if (st) cout << "4";
    cout << endl;
  }
  return 0;
}
