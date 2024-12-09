#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
int n;
vector<pair<int, int>> coord;
pair<int, int> good(int m) {
  int minx = -inf, maxx = inf, miny = -inf, maxy = inf, mindiff = -inf,
      maxdiff = inf;
  for (int q = 0; q < n; q++) {
    int x, y;
    tie(x, y) = coord[q];
    minx = max(minx, x - m);
    maxx = min(maxx, x + m);
    miny = max(miny, y - m);
    maxy = min(maxy, y + m);
    mindiff = max(mindiff, y - x - m);
    maxdiff = min(maxdiff, y - x + m);
  }
  minx = max(minx, 0);
  miny = max(miny, 0);
  pair<int, int> bad = {-1, -1};
  if (minx > maxx || miny > maxy || mindiff > maxdiff) return bad;
  if (maxy - minx < mindiff || miny - maxx > maxdiff) return bad;
  pair<int, int> ret = {minx, maxy};
  if (ret.second - ret.first > maxdiff)
    ret.first = min(maxx, ret.second - maxdiff);
  if (ret.second - ret.first > maxdiff || ret == make_pair(0, 0))
    ret.second = max(miny, ret.first + maxdiff);
  assert(ret != make_pair(0, 0));
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int q = 0; q < n; q++) {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int w = 0; w < (int)s.length(); w++) {
      if (s[w] == 'B') x++;
      if (s[w] == 'N') y++;
    }
    coord.emplace_back(x, y);
  }
  int lo = -1, hi = inf, bct = -1, nct = -1;
  while (hi - lo > 1) {
    int m = (lo + hi) / 2;
    auto e = good(m);
    if (e.first == -1)
      lo = m;
    else {
      bct = e.first, nct = e.second;
      hi = m;
    }
  }
  cout << hi << "\n";
  for (int q = 0; q < bct; q++) cout << "B";
  for (int q = 0; q < nct; q++) cout << "N";
  cout << "\n";
  return 0;
}
