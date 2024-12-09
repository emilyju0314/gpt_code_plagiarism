#include <bits/stdc++.h>
using namespace std;
int a[312345], b[312345], abin[312345][10], bbin[312345][10];
vector<int> amat[312345], v, ansb;
int main() {
  int n, m, i, j, k;
  int x, jpos, ans, tmpans, f_ans, tp;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    x = a[i];
    for (j = 0; j < 9; j++) {
      abin[i][8 - j] = x % 2;
      x /= 2;
    }
    for (j = 1; j <= m; j++) {
      amat[i].push_back(j);
    }
  }
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    x = b[i];
    for (j = 0; j < 9; j++) {
      bbin[i][8 - j] = x % 2;
      x /= 2;
    }
  }
  for (i = 0; i < 9; i++) {
    ans = 0;
    for (j = 1; j <= n; j++) {
      if (abin[j][i] == 0) {
        continue;
      }
      tmpans = 1;
      for (k = 0; k < amat[j].size(); k++) {
        jpos = amat[j][k];
        tmpans = (tmpans & bbin[jpos][i]);
      }
      ans = (ans | tmpans);
    }
    if (ans == 1) {
      ansb.push_back(1);
      continue;
    }
    for (j = 1; j <= n; j++) {
      if (abin[j][i] == 0) {
        continue;
      }
      v.clear();
      for (k = 0; k < amat[j].size(); k++) {
        jpos = amat[j][k];
        if (bbin[jpos][i] == 0) {
          v.push_back(jpos);
        }
      }
      amat[j].clear();
      for (k = 0; k < v.size(); k++) {
        amat[j].push_back(v[k]);
      }
    }
    ansb.push_back(0);
  }
  tp = 1;
  f_ans = 0;
  for (i = ansb.size() - 1; i >= 0; i--) {
    f_ans += tp * ansb[i];
    tp *= 2;
  }
  cout << f_ans << endl;
}
