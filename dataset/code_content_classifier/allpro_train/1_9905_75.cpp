#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int h, w, q;
char buf[505][505];
int ans[1000005];
struct query_ {
  int y1, x1, y2, x2;
  int id;
};
bitset<505> able[2][505][505];
void rec(int l, int r, vector<query_>& query) {
  vector<query_> left, right;
  int md = (l + r) >> 1;
  for (int i = 0; i < h; ++i)
    for (int j = l; j < r; ++j) able[0][i][j].reset(), able[1][i][j].reset();
  for (int i = 0; i < h; ++i)
    if (buf[i][md] == '.') able[0][i][md].set(i), able[1][i][md].set(i);
  for (int i = h - 1; i >= 0; --i)
    for (int j = md; j >= l; --j)
      if (buf[i][j] == '.') {
        able[0][i][j] |= able[0][i + 1][j];
        if (j < md) able[0][i][j] |= able[0][i][j + 1];
      }
  for (int i = 0; i < h; ++i)
    for (int j = md; j < r; ++j)
      if (buf[i][j] == '.') {
        if (buf[i][j + 1] == '.') able[1][i][j + 1] |= able[1][i][j];
        if (buf[i + 1][j] == '.') able[1][i + 1][j] |= able[1][i][j];
      }
  for (int i = 0; i < query.size(); ++i) {
    if (query[i].x1 <= md && md <= query[i].x2) {
      if ((able[0][query[i].y1][query[i].x1] &
           able[1][query[i].y2][query[i].x2])
              .any()) {
        ans[query[i].id] = 1;
      }
    } else if (query[i].x2 < md)
      left.push_back(query[i]);
    else
      right.push_back(query[i]);
  }
  if (!left.empty()) rec(l, md, left);
  if (!right.empty()) rec(md, r, right);
  query.clear();
}
int main() {
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) buf[i][j] = '#';
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) scanf("%s", buf[i]);
  scanf("%d", &q);
  vector<query_> query;
  for (int i = 0; i < q; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    --a;
    --b;
    --c;
    --d;
    if (a > c || b > d) continue;
    query.push_back((query_){a, b, c, d, i});
  }
  rec(0, w, query);
  for (int i = 0; i < q; ++i) {
    if (ans[i])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
