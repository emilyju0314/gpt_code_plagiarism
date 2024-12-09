#include <bits/stdc++.h>
using namespace std;
void repeat() {
  long long n;
  cin >> n;
  long long arr[n];
  char a[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long B[n], R[n];
  long long b = 0, r = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 'B') {
      B[b] = arr[i];
      b++;
    } else {
      R[r] = arr[i];
      r++;
    }
  }
  sort(B, B + b);
  sort(R, R + r);
  long long p = 1, q = n;
  for (long long i = 0; i < b; i++) {
    if (B[i] >= p)
      p++;
    else {
      cout << "NO" << endl;
      return;
    }
  }
  for (long long i = r - 1; i >= 0; i--) {
    if (R[i] <= q)
      q--;
    else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    repeat();
  }
  return 0;
}
