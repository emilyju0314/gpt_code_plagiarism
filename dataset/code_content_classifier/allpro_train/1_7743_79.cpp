#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, l, r;
    cin >> n >> l >> r;
    long long x = n / l;
    if (r * x >= n)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
