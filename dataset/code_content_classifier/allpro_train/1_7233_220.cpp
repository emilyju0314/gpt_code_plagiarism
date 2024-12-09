#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long fastpower(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return fastpower((x * x) % M, n / 2, M);
  else
    return (x * fastpower((x * x) % M, (n - 1) / 2, M)) % M;
}
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
long long modInverse(long long A, long long M) {
  return fastpower(A, M - 2, M);
}
void sieve(long long N) {
  bool isPrime[N + 1];
  for (long long i = 0; i <= N; ++i) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (long long i = 2; i * i <= N; ++i) {
    if (isPrime[i] == true) {
      for (long long j = i * i; j <= N; j += i) isPrime[j] = false;
    }
  }
}
vector<long long> factorize(long long n) {
  vector<long long> res;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    res.push_back(n);
  }
  return res;
}
long long arr[100005];
vector<pair<int, int> > v[100005];
int subtree[100005];
int vis[100005];
int dfs(int a) {
  int x = 1;
  vis[a] = 1;
  for (auto it : v[a]) {
    if (!vis[it.first]) {
      vis[it.first] = 1;
      x += dfs(it.first);
    }
  }
  subtree[a] = x;
  return x;
}
long long ans = 0;
void dfs1(int a, int cont) {
  vis[a] = 1;
  if (cont > arr[a]) {
    ans += subtree[a];
    return;
  } else {
    for (auto it : v[a]) {
      if (!vis[it.first]) {
        vis[it.first] = 1;
        dfs1(it.first, max(cont + it.second, it.second));
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  for (long long i = 1; i <= n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back({i + 1, y});
    v[i + 1].push_back({x, y});
  }
  dfs(1);
  memset(vis, 0, sizeof(vis));
  dfs1(1, 0);
  cout << ans << endl;
  return 0;
}
