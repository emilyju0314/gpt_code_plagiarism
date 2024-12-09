#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int inf = 1e9;
const long long mod = 1e17 + 12345654321;
long long ans;
long long p[maxn];
long long hash1[maxn];
long long hash2[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  scanf("%d%d", &n, &m);
  p[0] = 1;
  for (int i = 1; i < n; i++) p[i] = (p[i - 1] * 2) % mod;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    v--;
    u--;
    hash1[v] += p[u];
    hash1[v] %= mod;
    hash2[v] = hash1[v];
    hash1[u] += p[v];
    hash1[u] %= mod;
    hash2[u] = hash1[u];
  }
  for (int i = 0; i < n; i++) hash2[i] = (hash2[i] + p[i]) % mod;
  sort(hash2, hash2 + n);
  sort(hash1, hash1 + n);
  for (int l = 0, r = 0; r < n; r++) {
    if (hash1[l] != hash1[r]) l = r;
    ans += r - l;
  }
  for (int l = 0, r = 0; r < n; r++) {
    if (hash2[l] != hash2[r]) l = r;
    ans += r - l;
  }
  printf("%I64d", ans);
}
