#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 2;
long long n, a, k;
long long c[MAXN];
long long w[MAXN];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> w[i];
  cin >> a;
  for (int i = 0; i < n; i++) cin >> c[i];
  priority_queue<long long> pq;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    pq.push(-c[i]);
    while (k < w[i]) {
      if (pq.empty()) {
        cout << "-1\n";
        return 0;
      }
      k += a;
      ans -= pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
