#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1000000000009;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long arr[14], temp[14], ans = 0;
  for (int i = 0, sz = (int)14; i < sz; i++) cin >> arr[i];
  for (int i = 0, sz = (int)14; i < sz; i++) {
    long long k = arr[i], sum = 0, times = 14;
    for (int j = 0; j < 14; j++) temp[j] = arr[j];
    temp[i] = 0;
    for (int j = (i + 1) % 14; times--; j = (j + 1) % 14) {
      int add = k / 14;
      temp[j] += add;
    }
    k = k % 14;
    for (int j = (i + 1) % 14; k; j = (j + 1) % 14) {
      temp[j]++;
      k--;
    }
    for (int j = 0; j < 14; j++) {
      if (!(temp[j] % 2)) sum += temp[j];
    }
    ans = max(ans, sum);
  }
  cout << ans << "\n";
  return 0;
}
