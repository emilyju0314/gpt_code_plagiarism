#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int d;
int ng[1 << 20];
bool vis[1 << 20];
int im[20][100002];
int rng(int id, int l, int r) {
  int R = im[id][r];
  if (l) R -= im[id][l - 1];
  return R;
}
int cn(int num) {
  int r = 0;
  while (num) {
    if ((num & 1)) {
      r++;
    }
    num >>= 1;
  }
  return r;
}
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < a; j++) {
      int b;
      scanf("%d", &b);
      b--;
      im[i][b]++;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      im[i][j] += im[i][j - 1];
    }
  }
  for (int i = 0; i + d <= n; i++) {
    int b = 0;
    for (int j = 0; j < m; j++) {
      if (rng(j, i, i + d - 1)) {
        b |= (1 << j);
      }
    }
    ng[b] = 1;
  }
  for (int i = 0; i < (1 << m); i++) {
    if (ng[i] && vis[i] == false) {
      for (int j = ((i + 1) | i); j < (1 << m); j++, j |= i) {
        ng[j] = true;
        vis[j] = true;
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < (1 << m); i++) {
    if (ng[i] == false) {
      int er = m - cn(i);
      ans = min(ans, er);
    }
  }
  cout << ans << endl;
  return 0;
}
