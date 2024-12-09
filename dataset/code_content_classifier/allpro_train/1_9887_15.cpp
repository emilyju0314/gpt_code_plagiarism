#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn];
int cnt = 1;
int main() {
  int n;
  ios::sync_with_stdio(false);
  cin >> n;
  if (n % 2 == 0)
    cout << "NO" << endl;
  else {
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        a[i] = cnt++;
        a[n + i] = cnt++;
      } else {
        a[i + n] = cnt++;
        a[i] = cnt++;
      }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 2 * n; i++) cout << a[i] << ' ';
  }
  return 0;
}
