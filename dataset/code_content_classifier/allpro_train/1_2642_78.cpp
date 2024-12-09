#include <bits/stdc++.h>
using namespace std;
int a[2000001], b[2000001];
int main() {
  char ch[2000001];
  int i, n, k = 1000, m = 0, t = 0, j = 0;
  int l = 0, r, x, ans = 0, c = 0;
  cin >> n >> m;
  if (n == 1 && m == 10) {
    cout << "-1";
    return 0;
  }
  if (m == 10) {
    for (i = 1; i < n; i++) cout << "1";
    cout << "0";
    return 0;
  }
  for (i = 1; i <= n; i++) {
    cout << m;
  }
  return 0;
}
