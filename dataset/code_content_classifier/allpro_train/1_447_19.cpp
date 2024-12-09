#include <bits/stdc++.h>
using namespace std;
long long n, v[100000 + 10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  cout << 1 << ' ' << 1 << '\n' << -v[1] << '\n';
  if (n == 1) {
    cout << 1 << ' ' << 1 << '\n'
         << 0 << '\n'
         << 1 << ' ' << 1 << '\n'
         << 0 << '\n';
    return 0;
  }
  cout << 2 << ' ' << n << '\n';
  for (int i = 2; i <= n; i++) cout << v[i] * (n - 1) << ' ';
  cout << '\n';
  cout << 1 << ' ' << n << '\n';
  cout << 0 << ' ';
  for (int i = 2; i <= n; i++) cout << -v[i] * n << ' ';
  cout << '\n';
  return 0;
}
