#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long l = 0, r = n - 1;
  long long sum = 0;
  while (l < r) {
    long long temp = a[l] + a[r];
    sum += temp * temp;
    l++;
    r--;
  }
  cout << sum;
  return 0;
}
