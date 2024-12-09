#include <bits/stdc++.h>
using namespace std;
int n, a[100010], mx;
long long k;
queue<int> q;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mx < a[i]) mx = a[i];
  }
  if (k >= n)
    cout << mx;
  else {
    int times = 0, winner = 1, fighter = 2, last = n;
    while (times < k) {
      if (a[winner] > a[fighter]) {
        times++;
        a[++last] = a[fighter];
        fighter++;
      } else {
        a[++last] = a[winner];
        times = 1;
        winner = fighter;
        fighter++;
      }
    }
    cout << a[winner];
  }
  return 0;
}
