#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, M = 2e5 + 7;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
int n, p, k;
int arr[M], pric[M], ctr[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < k; i++) {
      pric[i] = ctr[i] = 0;
    }
    int ind;
    for (int i = k - 1; i < n; i++) {
      ind = (i + 1) % k;
      if (pric[ind] + arr[i] > p) break;
      pric[ind] += arr[i];
      ctr[ind] += k;
    }
    int maxi = ctr[0];
    ind = 0;
    for (int i = 1; i < k; i++) {
      ind += arr[i - 1];
      if (pric[i] + ind <= p) maxi = max(maxi, ctr[i] + i);
    }
    cout << maxi << "\n";
  }
  return 0;
}
