#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int a[n], m = 0, idx;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) {
      m = a[i];
      idx = i;
    }
  }
  long long int c = 0, k;
  if (idx == n - 1)
    k = idx - 1;
  else
    k = idx;
  for (long long int i = 0; i < k; i++)
    if (a[i] > a[i + 1]) {
      c++;
      break;
    }
  if (c)
    cout << "NO\n";
  else {
    for (long long int i = idx; i < n - 1; i++)
      if (a[i + 1] > a[i]) {
        c++;
        break;
      }
    if (c)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
