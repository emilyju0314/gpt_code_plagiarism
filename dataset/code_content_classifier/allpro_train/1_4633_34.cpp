#include <bits/stdc++.h>
using namespace std;
int s1, s2, n1, n2, p, ans;
int n, a[100100], i, j;
int main() {
  cin >> n >> a[1];
  p = 1, s1 = 1, n1 = a[1];
  for (i = 2; i <= n; i++) {
    cin >> a[i];
    if (a[i] == n1)
      s1++;
    else if (a[i] == n2)
      s2++;
    else {
      while (s1 && s2) {
        if (a[p] == n1)
          s1--;
        else
          s2--;
        p++;
      }
      if (s1 == 0)
        n1 = a[i], s1 = 1;
      else
        n2 = a[i], s2 = 1;
    }
    ans = max(ans, s1 + s2);
  }
  cout << ans;
}
