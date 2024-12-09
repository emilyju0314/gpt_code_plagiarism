#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string name;
  cin >> name;
  long long int i;
  long long int n = name.length();
  vector<long long int> arr(n);
  long long int start = n - 1;
  for (i = 0; i < n; i++) {
    arr[i] = power(2, start + i, (long long int)(1e9 + 7));
  }
  long long int ans = 0;
  reverse(arr.begin(), arr.end());
  for (i = 0; i < n; i++) {
    ans += (name[i] - '0') * (arr[i]);
    ans %= (long long int)(1e9 + 7);
  }
  cout << ans << '\n';
  return 0;
}
