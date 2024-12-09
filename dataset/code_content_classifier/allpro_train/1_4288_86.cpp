#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  long long i, n, k;
  cin >> n >> k;
  long long ar[n + 1];
  map<long long, long long> m1;
  map<long long, long long> m2;
  long long ans = 0;
  for (i = 0; i < n; i++) {
    cin >> ar[i];
    m2[ar[i]]++;
  }
  for (i = 0; i < n; i++) {
    long long k1 = 0, k2 = 0;
    if (!(ar[i] % k)) {
      k1 = m1[ar[i] / k];
    }
    m2[ar[i]]--;
    k2 = m2[ar[i] * k];
    ans += k1 * k2;
    m1[ar[i]]++;
  }
  cout << ans;
}
