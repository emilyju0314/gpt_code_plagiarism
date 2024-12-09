#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int n, i;
    cin >> n;
    long long int a[n];
    long double sum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long double ans = ceil(sum / n);
    long long int num = (long long int)ans;
    cout << num << "\n";
  }
}
