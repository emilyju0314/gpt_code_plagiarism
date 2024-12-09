#include <bits/stdc++.h>
using namespace std;
int code() {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int aa = max(a, b);
  aa = max(aa, c);
  long long int sum = a + b + c - aa;
  long long int ans = ((sum - aa <= 0) ? aa - sum + 1 : 0);
  cout << ans << endl;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  code();
}
