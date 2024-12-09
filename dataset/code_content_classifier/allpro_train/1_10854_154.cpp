#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c[50], s, x[2500] = {}, y[2500] = {}, a[50][50];
  cin >> n;
  for (int i = s = 0; i < n; ++i) {
    cin >> c[i];
    s += c[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < c[i]; ++j) {
      cin >> a[i][j];
      x[a[i][j] - 1] = i;
      y[a[i][j] - 1] = j;
    }
  }
  vector<int> ans;
  for (int i = 0, k = 0; i < n; ++i) {
    for (int j = 0; j < c[i]; ++j, ++k) {
      if (x[k] == i && y[k] == j)
        continue;
      else {
        int xx = x[k], yy = y[k];
        ans.push_back(((((xx * 50 + yy) * 50) + i) * 50) + j);
        swap(x[k], x[a[i][j] - 1]);
        swap(y[k], y[a[i][j] - 1]);
        swap(a[i][j], a[xx][yy]);
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    int xx, yy, pp, qq, val = ans[i];
    qq = val % 50 + 1;
    val /= 50;
    pp = val % 50 + 1;
    val /= 50;
    yy = val % 50 + 1;
    val /= 50;
    xx = val % 50 + 1;
    val /= 50;
    cout << xx << ' ' << yy << ' ' << pp << ' ' << qq << endl;
  }
  return 0;
}
