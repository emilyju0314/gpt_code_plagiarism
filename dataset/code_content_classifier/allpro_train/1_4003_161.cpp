#include <bits/stdc++.h>
using namespace std;
long long mul(long long x, long long y, long long z) {
  long long res = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) res = ((res % z) + (x % z)) % z;
    x = (x << 1) % z;
    y >>= 1;
  }
  return res % z;
}
long long fast_expo(long long x, long long y, long long z) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) {
      res = ((res % z) * (x % z)) % z;
    }
    y >>= 1;
    x = ((x % z) * (x % z)) % z;
  }
  return res;
}
void printVec(vector<long long> res) {
  for (auto itr : res) {
    cout << (itr) << " ";
  }
  cout << "\n";
}
unordered_map<long long, vector<long long>> constructTree(
    pair<long long, long long> edges[], long long n) {
  unordered_map<long long, vector<long long>> res;
  for (long long i = 0; i < n; i++) {
    auto pairs = edges[i];
    res[pairs.first].push_back(pairs.second);
    res[pairs.second].push_back(pairs.first);
  }
  return res;
}
void dfs(unordered_map<long long, vector<long long>> &tree, bool visited[],
         int start) {
  visited[start] = true;
  for (auto itr : tree[start]) {
    if (!visited[itr]) {
      dfs(tree, visited, itr);
    }
  }
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    long long res = (x % m + m) % m;
    return res;
  }
}
const long long SZ = 5 * (1e5) + 1;
long long fac[SZ];
long long twoPower[SZ];
long long ncr(long long n, long long r, long long p = 1000000007) {
  if (r > n) return 0;
  if (r == 1) return n;
  if (r == 0 || r == n) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string second;
    cin >> n >> second;
    long long bal = 0, ans = 0;
    for (long long i = 0; i < n; i++) {
      if (second[i] == '(')
        bal++;
      else {
        bal--;
        if (bal < 0) {
          ans++;
          bal = 0;
        }
      }
    }
    cout << ans << "\n";
  }
}
