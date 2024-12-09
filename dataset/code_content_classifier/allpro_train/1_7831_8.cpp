#include <bits/stdc++.h>
using namespace std;
long long int mi, m1, m2;
int main() {
  long long int n, d;
  cin >> n >> d;
  long long int r = (n - 1) * 10;
  long long int a[n], su = 0;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) su = su + a[i];
  if (su + r > d)
    cout << -1;
  else
    cout << (d - su) / 5;
}
