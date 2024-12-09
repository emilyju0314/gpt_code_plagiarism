#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int ans = 0;
  for (int j = 0; j < n; j++) {
    if (a[j] != 0) {
      ans++;
      for (int i = j + 1; i < n; i++)
        if (a[i] != 0 & a[i] % a[j] == 0) a[i] = 0;
      a[j] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
