#include <bits/stdc++.h>
using namespace std;
const int N = 111;
char grid[N][N];
int must[N][N];
int n;
vector<pair<int, int> > v;
int main() {
  scanf("%d", &n);
  getchar();
  int i, j, k, c1, c2;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%c", &grid[i][j]);
    }
    getchar();
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (grid[i][j] == '.') {
        v.push_back(make_pair(i, j));
        break;
      }
    }
  }
  if ((int)v.size() == n) {
    for (i = 0; i < n; i++) {
      printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
  }
  v.clear();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (grid[j][i] == '.') {
        v.push_back(make_pair(j, i));
        break;
      }
    }
  }
  if ((int)v.size() == n) {
    for (i = 0; i < n; i++) {
      printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
  }
  cout << "-1\n";
  return 0;
}
