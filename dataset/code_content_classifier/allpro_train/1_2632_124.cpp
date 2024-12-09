#include <bits/stdc++.h>
using namespace std;
bool B, bb[109];
vector<pair<int, int> > a;
vector<int> b[109];
void DFS(int x, int y) {
  if (x == y) B = true;
  for (int i = 0; i < b[x].size(); i++) {
    if (!bb[b[x][i]]) {
      bb[b[x][i]] = true;
      DFS(b[x][i], y);
    }
  }
}
int main() {
  int i, j, n, p, x, y, k;
  cin >> n;
  p = 0;
  for (i = 0; i < n; i++) {
    cin >> k;
    cin >> x >> y;
    B = false;
    if (k == 1) {
      a.push_back(make_pair(x, y));
      for (j = 0; j < a.size(); j++) {
        if ((x > a[j].first && x < a[j].second) ||
            (y > a[j].first && y < a[j].second))
          b[p].push_back(j);
        if ((a[j].first > x && a[j].first < y) ||
            (a[j].second > x && a[j].second < y))
          b[j].push_back(p);
      }
      p++;
    } else {
      for (j = 0; j < n; j++) bb[j] = false;
      x--;
      y--;
      bb[x] = true;
      DFS(x, y);
      if (B)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
