#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int ara[n], s = 0, sum = 0, cnt = 0, res = 0;
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
    sum += ara[i];
  }
  if (sum % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  sum /= 3;
  for (int i = 0; i < n - 1; i++) {
    s += ara[i];
    if (s == 2 * sum) res += cnt;
    if (s == sum) cnt++;
  }
  cout << res << endl;
  return 0;
}
