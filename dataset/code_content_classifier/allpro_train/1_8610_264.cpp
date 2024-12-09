#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, mx;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 || mx < a[i]) mx = a[i];
  }
  cout << mx;
}
