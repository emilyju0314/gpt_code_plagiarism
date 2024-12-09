#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i % 2 == 0) sum += a[i];
    }
    long long int ind = -1;
    long long int summax = 0;
    long long int other = 0;
    for (int i = 0; i < n; i++) {
      if (i <= n - 2) {
        long long int diff = a[i + 1] - a[i];
        other += diff;
        if (other > summax) {
          summax = other;
          ind = i;
        }
        if (other < 0) other = 0;
        ++i;
      }
    }
    other = 0;
    if (n % 2 == 1) {
      for (long long int i = n - 1; i >= 0; i--) {
        if (i >= 1) {
          long long int diff = a[i - 1] - a[i];
          other += diff;
          if (other > summax) {
            summax = other;
            ind = i;
          }
          if (other < 0) other = 0;
          --i;
        }
      }
    } else {
      for (long long int i = n - 2; i >= 0; i--) {
        if (i >= 1) {
          long long int diff = a[i - 1] - a[i];
          other += diff;
          if (other > summax) {
            summax = other;
            ind = i;
          }
          if (other < 0) other = 0;
          --i;
        }
      }
    }
    cout << summax + sum << endl;
  }
}
