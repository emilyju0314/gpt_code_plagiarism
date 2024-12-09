#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  long long max = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  long long l[n];
  for (long long i = 0; i < n; i++) {
    l[i] = 0;
  }
  if (arr[0] == max) {
    l[0] = 1;
  }
  for (long long i = 1; i < n; i++) {
    if (arr[i] == max) {
      l[i] = l[i - 1] + 1;
    } else {
      l[i] = 0;
    }
  }
  sort(l, l + n);
  cout << l[n - 1] << "\n";
}
