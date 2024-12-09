#include <bits/stdc++.h>
using namespace std;
double dis(int x1, int y1, int x2, int y2) {
  int x = x2 - x1;
  x = x * x;
  int y = y2 - y1;
  y = y * y;
  return (sqrt(x + y));
}
int main() {
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  vector<pair<int, int>> vec;
  int x1 = min(xa, xb);
  int y1 = min(ya, yb);
  int x2 = x1, y2 = max(ya, yb);
  while (y1 <= y2) vec.push_back({x1, y1}), y1++;
  x1++;
  while (x1 <= max(xa, xb)) vec.push_back({x1, y2}), x1++;
  int x = max(xa, xb);
  int y = max(ya, yb);
  y--;
  while (y >= min(ya, yb)) vec.push_back({x, y}), y--;
  x = max(xa, xb);
  y = min(ya, yb);
  x--;
  while (x > min(xa, xb)) vec.push_back({x, y}), x--;
  int n;
  cin >> n;
  map<pair<int, int>, int> mp;
  while (n--) {
    int x, y, r;
    cin >> x >> y >> r;
    for (int i = 0; i < vec.size(); i++) {
      int xx = vec[i].first;
      int yy = vec[i].second;
      if (dis(x, y, xx, yy) <= double(r)) mp[{xx, yy}] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (mp[{vec[i].first, vec[i].second}] == 0) cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
