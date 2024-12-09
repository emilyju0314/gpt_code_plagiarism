#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[200011];
int flag;
int read() {
  int _ = 0, __ = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') __ = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    _ = _ * 10 + ch - '0';
    ch = getchar();
  }
  return _ * __;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    flag = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[i - 1]) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "1" << endl;
    else
      cout << n << endl;
  }
  return 0;
}
