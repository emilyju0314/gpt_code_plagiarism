#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n;
int x[1100111], mp[1100111];
int mx;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    mp[x[i]]++;
    mx = max(mx, x[i]);
  }
  int ans = 0;
  int i = 0;
  while (i < 1100111 - 2) {
    if (mp[i] & 1) ans++;
    mp[i + 1] += mp[i] / 2;
    i++;
  }
  cout << ans << endl;
  return 0;
}
