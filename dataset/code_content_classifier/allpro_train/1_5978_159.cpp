#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp;
  if (b % 2) tmp = (tmp * a);
  return tmp;
}
void sol() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans = 0;
  int x = -1, y = -1;
  for (int i = 0; i < n; i++) {
    int tmp = max(x, y);
    if (x == tmp && y == tmp) ans--;
    x = tmp;
    y = tmp;
    if (min(a[i], b[i]) >= x) {
      ans++;
      ans += (min(a[i], b[i]) - x);
    }
    x = a[i];
    y = b[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    sol();
  }
  return 0;
}
