#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, maxx, minn = 1000, t;
  cin >> n;
  int i;
  int c[n];
  for (i = 0; i < n; i++) {
    cin >> c[i];
    if (c[i] == 180) {
      cout << "0";
      return 0;
    }
    if (c[i] == c[i - 1] && i != 0) {
      sum++;
    }
  }
  if (sum == n - 1 && n % 2 == 0) {
    cout << "0";
    return 0;
  }
  sum = 0;
  int j;
  for (i = 0; i < n; i++) {
    t = i;
    sum = 0;
    if (c[i] == 180) {
      cout << "0";
      return 0;
    }
    for (j = t; j < n; j++) {
      if (sum + c[j] <= 180)
        sum += c[j];
      else {
        break;
      }
      if (j == n - 1) {
        t = -1;
        j = t;
      }
      if (sum == 180) {
        cout << "0";
        return 0;
      }
    }
    maxx = 360 - sum;
    if (minn > fabs(sum - maxx)) minn = fabs(maxx - sum);
  }
  cout << minn;
  return 0;
}
