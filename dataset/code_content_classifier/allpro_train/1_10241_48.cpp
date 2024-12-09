#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, a[N], b[N];
int resY, maxX, maxY;
pair<int, int> dist(int x, int y, int u, int v) {
  x -= u;
  y -= v;
  if ((x < 0 && y > 0) || (x > 0 && y < 0))
    return make_pair(abs(x) + abs(y), abs(y) * abs(y) + abs(x) * abs(x));
  return make_pair(max(abs(x), abs(y)), abs(y) * abs(y) + abs(x) * abs(x));
}
pair<int, int> calcDist(int x, int y) {
  pair<int, int> res = make_pair(0, 0);
  for (int i = 1; i <= n; i++) res = max(res, dist(x, y, a[i], b[i]));
  return res;
}
pair<int, int> calcY(int x) {
  int l = 0, r = maxY + 1, res;
  while (l < r) {
    int mid = (l + r) >> 1;
    pair<int, int> r1 = calcDist(x, mid);
    pair<int, int> r2 = calcDist(x, mid + 1);
    if (r1 < r2) {
      res = mid;
      r = mid;
    } else {
      res = mid + 1;
      l = mid + 1;
    }
  }
  resY = res;
  return calcDist(x, res);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (char ch : s)
      if (ch == 'B')
        a[i]++;
      else
        b[i]++;
  }
  maxX = *max_element(a + 1, a + 1 + n);
  maxY = *max_element(b + 1, b + 1 + n);
  int l = 0, r = maxX + 1, resX;
  while (l < r) {
    int mid = (l + r) >> 1;
    pair<int, int> r1 = calcY(mid);
    pair<int, int> r2 = calcY(mid + 1);
    if (r1 < r2) {
      resX = mid;
      r = mid;
    } else {
      resX = mid + 1;
      l = mid + 1;
    }
  }
  cout << calcY(resX).first << endl;
  for (int i = 1; i <= resX; i++) putchar('B');
  for (int i = 1; i <= resY; i++) putchar('N');
  return 0;
}
