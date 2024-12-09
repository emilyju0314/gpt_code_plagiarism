#include <bits/stdc++.h>
using namespace std;
long long tst;
void cleanData();
long long n, m, k, a[100005], b, c, d, x;
long long mp[100005];
int primo[100005];
vector<int> primos;
void criba(int n) {
  for (int i = 2; i < n; ++i) primo[i] = 1;
  for (int i = 2; i * i < n; i++)
    if (primo[i])
      for (int j = i * i; j < n; j += i) primo[j] = 0;
  for (int i = 2; i < n; ++i) {
    if (primo[i]) primos.push_back(i);
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    long long curr = a[i];
    if (curr == 1) continue;
    mp[curr]++;
    ans = max(ans, mp[curr]);
    for (long long j = 2; j * j <= curr; ++j) {
      if (a[i] % j == 0) {
        mp[j]++;
        ans = max(ans, mp[j]);
        if (a[i] / j != j) mp[a[i] / j]++, ans = max(ans, mp[a[i] / j]);
      }
    }
  }
  cout << max(ans, 1ll);
}
int main() {
  ios_base::sync_with_stdio(0);
  criba(100005);
  tst = 1;
  while (tst--) {
    solve();
  }
  return 0;
}
void cleanData() {}
