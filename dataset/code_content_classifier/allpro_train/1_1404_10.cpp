#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int prime[maxn];
bool vis[maxn];
int tot;
void prime_table() {
  memset(vis, true, sizeof(vis));
  memset(prime, 0, sizeof(prime));
  vis[0] = false;
  vis[1] = false;
  tot = 0;
  for (int i = 2; i < maxn; i++) {
    if (vis[i]) prime[tot++] = i;
    for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}
vector<int> v;
long long cast(int p) {
  long long ans = 0;
  for (int i = 0; i < v.size(); i += p) {
    long long mid = v[(i + i + p - 1) / 2];
    for (int j = i; j < i + p; j++) ans += abs(v[j] - mid);
  }
  return ans;
}
int a[100005];
int main() {
  prime_table();
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i]) v.push_back(i);
  }
  if (v.size() == 1) {
    cout << "-1" << endl;
    return 0;
  }
  long long mins = 1e18;
  for (int i = 0; prime[i] <= sum; i++) {
    if (sum % prime[i] == 0) mins = min(mins, cast(prime[i]));
  }
  cout << mins << endl;
}
