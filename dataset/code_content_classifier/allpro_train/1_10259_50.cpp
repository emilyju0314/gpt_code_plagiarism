#include <bits/stdc++.h>
const int inf = (1ll << 31) - 1;
using namespace std;
int a[(int)(2e5)], n, m;
bool used[(int)(2e5)];
char x[(int)(2e5)];
int main() {
  cin >> n >> m;
  int k = -1;
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> a[i];
    if (x[i] == '-') {
      if (!used[a[i]]) {
        k = i;
      }
    }
    used[a[i]] = 1;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) ans.push_back(i);
  }
  if (k == -1) {
    memset(used, 0, sizeof(used));
    bool ok = 1;
    int cur = 0;
    for (int i = 1; i < m; i++) {
      if (a[i] == a[0]) {
        if (cur != 0) ok = false;
        if (i + 1 < m && a[i] != a[i + 1]) ok = false;
        i++;
      } else if (used[a[i]]) {
        used[a[i]] = false;
        cur--;
      } else {
        used[a[i]] = 1;
        cur++;
      }
    }
    if (ok == 1) {
      ans.push_back(a[0]);
    }
  } else {
    memset(used, 0, sizeof(used));
    int cur = 0;
    for (int i = 0; i < k; i++) {
      if (used[a[i]]) {
        cur--;
        used[a[i]] = 0;
      } else if (x[i] != '-') {
        used[a[i]] = 1;
        cur++;
      }
    }
    if (cur == 0) {
      if (k == m - 1)
        ans.push_back(a[k]);
      else if (a[k + 1] == a[k]) {
        memset(used, 0, sizeof(used));
        cur = 0;
        bool ok = 1;
        for (int i = k + 2; i < m; i++) {
          if (a[i] == a[k]) {
            if (cur != 0) ok = false;
            if (i + 1 < m && a[i] != a[i + 1]) {
              ok = false;
            }
            i++;
          } else if (used[a[i]]) {
            used[a[i]] = false;
            cur--;
          } else {
            used[a[i]] = 1;
            cur++;
          }
        }
        if (ok == 1) {
          ans.push_back(a[k]);
        }
      }
    }
  }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
