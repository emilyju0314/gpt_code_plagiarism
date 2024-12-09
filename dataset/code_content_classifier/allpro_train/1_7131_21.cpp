#include <bits/stdc++.h>
using namespace std;
int n, k;
string ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  if (n < k or (k == 1 and n > 1)) {
    cout << -1 << endl;
    return 0;
  }
  if (k == 1 and n == 1) {
    cout << "a" << endl;
    return 0;
  }
  for (int i = 0; i < n - k; i++) ans += char((i & 1) + 'a');
  if ((n - k) & 1)
    ans += "ba";
  else
    ans += "ab";
  for (int i = 2; i < k; i++) ans += char(i + 'a');
  cout << ans << endl;
  return 0;
}
