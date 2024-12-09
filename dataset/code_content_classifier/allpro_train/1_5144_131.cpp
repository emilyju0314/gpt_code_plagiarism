#include <bits/stdc++.h>
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e9 + 9;
vector<long long> primes;
class Graph {
  map<long long, vector<long long>> ma;

 public:
  void addedge(long long n, long long m) {
    ma[n].push_back(m);
    ma[m].push_back(n);
  }
  long long solve(long long n) {
    bool visited[n + 1];
    long long i;
    for (i = 1; i <= n; i++) visited[i] = 0;
    long long ans = 0;
    for (i = 1; i <= n; i++) {
      if (!visited[i]) {
        ans++;
        dfs(visited, i);
      }
    }
    return (n - ans);
  }
  void dfs(bool visited[], long long no) {
    visited[no] = 1;
    for (auto node : ma[no])
      if (!visited[node]) dfs(visited, node);
  }
};
vector<long long> primeFactors(long long n) {
  vector<long long> ans;
  long long cur = 1;
  ans.push_back(1);
  while (n % 2 == 0) {
    cur = cur * 2;
    ans.push_back(cur);
    n = n / 2;
  }
  for (long long i = 3; i * i <= (n); i = i + 2) {
    while (n % i == 0) {
      cur = cur * i;
      ans.push_back(cur);
      n = n / i;
    }
  }
  if (n > 2) ans.push_back(cur * n);
  return ans;
}
long long modoinv(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long fact(long long n) {
  if (n == 0) return (long long)1;
  long long ans = 1;
  while (n != 1) {
    ans *= n;
    ans %= (long long)(1000000007);
    n--;
  }
  return ans;
}
void sieve(long long p) {
  vector<bool> mark(p, 1);
  for (long long i = 3; i < p; i += 2) {
    if (mark[i] == 1) {
      for (long long j = i * i; j < p; j += 2 * i) {
        mark[j] = 0;
      }
    }
  }
  primes.push_back(2);
  for (long long i = 3; i < p; i += 2) {
    if (mark[i]) primes.push_back(i);
  }
}
long long mod_exp(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long a = mod_exp(x, n / 2, m);
  if (n % 2 == 0)
    return (a * a) % m;
  else
    return (x * a * a) % m;
}
bool isPrime(long long n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, z, i, e;
  cin >> n >> a >> b;
  for (i = 0; i < n; i++) {
    cin >> e;
    z = (e * a) / b;
    long long l = 0, r = e, mid, ans = b;
    while (l <= r) {
      mid = (l + r) / 2;
      if ((mid * a) / b < z) {
        l = mid + 1;
      } else {
        ans = mid;
        r = mid - 1;
      }
    }
    cout << e - ans << " ";
  }
}
