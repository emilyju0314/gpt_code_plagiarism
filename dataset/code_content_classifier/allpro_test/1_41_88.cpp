#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
vector<int> ans;
int ma;
int n, k;
void solve(int x, int y) {
  vector<int> A, B;
  while (x) {
    A.push_back(x % k);
    x /= k;
  }
  while (y) {
    B.push_back(y % k);
    y /= k;
  }
  while (A.size() < 10) A.push_back(0);
  while (B.size() < 10) B.push_back(0);
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  for (int i = 0; i < A.size(); i++) {
    if (A[i] != B[i]) {
      ma = max(ma, 10 - i);
      ans.push_back(10 - i);
      break;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  ma = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      solve(i, j);
    }
  }
  printf("%d\n", ma);
  for (auto it : ans) {
    printf("%d ", it);
  }
}
