#include <bits/stdc++.h>
using namespace std;
int n, a[11111];
int sum = 0, x, y;
map<short, bool> used, empty;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) a[i] *= -1;
  }
  for (int i = 1; i <= n; i++) {
    x = y = 0;
    for (int j = 1; j <= n; j++) {
      if (j < i && a[j] > a[i] || j > i && a[j] < a[i]) x++;
      if (j < i && a[j] > -a[i] || j > i && a[j] < -a[i]) y++;
    }
    if (x > y) a[i] *= -1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++)
      if (a[j] > a[i]) sum++;
  }
  cout << sum;
  return 0;
}
