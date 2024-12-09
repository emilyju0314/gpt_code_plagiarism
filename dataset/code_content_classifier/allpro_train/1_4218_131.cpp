#include <bits/stdc++.h>
using namespace std;
long long int arr[200005];
long long int arr1[200005];
int main() {
  long long int n, m, x, res;
  scanf("%lld", &n);
  scanf("%lld", &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  arr1[0] = 0;
  for (int i = 1; i <= n; i++) {
    arr1[i] = arr[i - 1] + arr1[i - 1];
  }
  for (int i = 0; i < m; i++) {
    scanf("%lld", &x);
    int p = lower_bound(arr1, arr1 + n, x) - arr1;
    long long int res = x - arr1[p - 1];
    cout << p << " " << res << endl;
  }
}
