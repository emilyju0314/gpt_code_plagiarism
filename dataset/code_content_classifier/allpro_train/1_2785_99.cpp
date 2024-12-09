#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long val = k / (n - 1);
    long long rem = k % (n - 1);
    if (rem)
      cout << (n * val) + rem << "\n";
    else
      cout << (n * val) - 1 << "\n";
  }
  return 0;
}
