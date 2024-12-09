#include <bits/stdc++.h>
using namespace std;
int debug = 0;
int n;
vector<int> c;
vector<vector<int>> ans;
void shuf(vector<int> D) {
  vector<int> c2;
  int m = D.size();
  int lst = n;
  for (int i = m - 1; i >= 0; --i) {
    for (int j = lst - D[i]; j < lst; ++j) {
      c2.push_back(c[j]);
    }
    lst -= D[i];
  }
  c = c2;
}
int main() {
  cin >> n;
  c.resize(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  while (1) {
    int flag = 0, x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && c[i - 1] + 1 == c[i]) {
        continue;
      }
      for (int j = i + 1; j < n; ++j) {
        if (j < n - 1 && c[j] + 1 == c[j + 1]) {
          continue;
        }
        if (c[i] > c[j] && c[j] + 1 == c[i]) {
          flag = 1;
          x = i, y = j;
          break;
        }
      }
      if (flag) break;
    }
    if (flag == 0) break;
    int z = y;
    while (z > x && c[z] == c[y] + (z - y)) --z;
    vector<int> D;
    if (x > 0) D.push_back(x);
    D.emplace_back(z - x + 1);
    D.push_back(y - z);
    if (n - 1 - y > 0) D.push_back(n - 1 - y);
    ans.push_back(D);
    shuf(D);
  }
  int q = ans.size();
  cout << q << '\n';
  for (auto i : ans) {
    cout << i.size() << ' ';
    for (auto j : i) cout << j << ' ';
    cout << '\n';
  }
}
