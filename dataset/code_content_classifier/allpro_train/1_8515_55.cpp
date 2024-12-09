#include <bits/stdc++.h>
using namespace std;
int q[100005];
long long ans[100005];
long long arr[100005];
long long sum[100005];
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n, greater<int>());
  for (int i = 0; i < n; i++) {
    ans[1] += 1ll * i * arr[i];
    sum[i] = arr[i] + ((i > 0) ? sum[i - 1] : 0);
  }
  for (int i = 2; i <= 100000; i++) {
    long long lo = 1;
    int cnt = 1;
    ans[i] = 0;
    while (lo < n) {
      long long hi = lo * i;
      hi = min(n - 1, hi);
      ans[i] += (1ll * (cnt) * (sum[hi] - sum[lo - 1]));
      cnt++;
      lo = hi + 1;
    }
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    cout << ans[x] << endl;
  }
}
