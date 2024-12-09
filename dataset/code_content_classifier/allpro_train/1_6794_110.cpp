#include <bits/stdc++.h>
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
const int MAXN = 100100;
int a[MAXN];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int all1 = -1;
  bool renzoku = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1 && renzoku)
      all1 = i;
    else
      renzoku = false;
  }
  if (a[n - 1] == 1) {
    cout << "NO" << endl;
    return 0;
  }
  if (n == 1) {
    cout << "YES" << endl;
    cout << "0" << endl;
    return 0;
  }
  if (all1 == n - 3 && a[n - 2] == 0 && a[n - 1] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if (a[n - 2] == 1) {
    for (int i = 0; i < n - 1; i++) {
      cout << a[i] << "->";
    }
    cout << a[n - 1] << endl;
    return 0;
  } else {
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        index = i;
        break;
      }
    }
    cout << "(";
    for (int i = 0; i < index; i++) {
      cout << a[i] << "->";
    }
    cout << a[index] << ")->(";
    for (int i = index + 1; i < n - 2; i++) {
      cout << a[i] << "->";
    }
    cout << a[n - 2] << ")->";
    cout << a[n - 1] << endl;
    return 0;
  }
  return 0;
}
