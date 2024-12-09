#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1, 0);
  vector<pair<int, int> > zeros;
  for (int i = 0; i < m; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      for (int j = x + 1; j <= y; j++) {
        arr[j] = 1;
      }
    } else {
      zeros.push_back(make_pair(x, y));
    }
  }
  bool exist = true;
  for (int i = 0; i < zeros.size(); i++) {
    bool flag = false;
    for (int j = zeros[i].first + 1; j <= zeros[i].second; j++) {
      if (arr[j] == 0) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      exist = false;
      break;
    }
  }
  if (exist) {
    cout << "YES" << endl;
    arr[0] = 2000;
    for (int i = 1; i <= n; i++) {
      if (arr[i] == 1) {
        arr[i] = arr[i - 1];
      } else {
        arr[i] = arr[i - 1] - 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
