#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(array<T, 2> &arr);
template <typename T>
void print(vector<T> &v);
template <typename T>
void print(deque<T> &v);
template <typename T>
T _gcd(T a, T b);
template <typename T>
vector<T> sieve(T n);
template <typename T>
T power(T x, T y, long long p = LLONG_MAX);
long long nxt();
template <typename T>
T modInverse(T n, T p);
long long gcd(vector<long long> &diff);
bool isPowerof2(long long x);
vector<long long> divisors(long long n) {
  vector<long long> ans;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (n / i != i) ans.push_back(n / i);
    }
  }
  ans.push_back(1);
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> input(n + 2);
  for (long long i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    input[i + 1] = temp;
  }
  vector<vector<long long> > operations(m, vector<long long>(3));
  for (long long i = 0; i < m; i++) {
    long long x, y, d;
    cin >> x >> y >> d;
    operations[i][0] = x, operations[i][1] = y, operations[i][2] = d;
  }
  vector<long long> queries(m + 2, 0);
  for (long long i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    queries[x]++;
    queries[y + 1]--;
  }
  for (long long i = 1; i < m + 1; i++) {
    queries[i] = queries[i - 1] + queries[i];
  }
  vector<long long> lara_croft(n + 2, 0);
  for (long long i = 0; i < m; i++) {
    long long x = operations[i][0], y = operations[i][1], d = operations[i][2];
    lara_croft[x] += (d * queries[i + 1]);
    lara_croft[y + 1] -= (d * queries[i + 1]);
  }
  for (long long i = 1; i < n + 1; i++) {
    lara_croft[i] = lara_croft[i - 1] + lara_croft[i];
  }
  for (long long i = 1; i < n + 1; i++) {
    input[i] = input[i] + lara_croft[i];
  }
  for (long long i = 1; i < n + 1; i++) cout << input[i] << " ";
  cout << '\n';
  return 0;
}
template <typename T>
T power(T x, T y, long long p) {
  T res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
template <typename T>
vector<T> sieve(T n) {
  vector<long long> prime(n + 1, 1);
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = 2; j * i <= n; j++) {
        prime[i * j] = 0;
      }
    }
  }
  vector<T> ans;
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) ans.push_back(i);
  }
  return prime;
}
template <typename T>
T _gcd(T a, T b) {
  T temp1 = max(a, b), temp2 = min(a, b);
  a = temp1, b = temp2;
  if (a == 0) return b;
  if (b == 0) return a;
  if (a % b == 0) return b;
  return _gcd(b, a % b);
}
template <typename T>
void print(array<T, 2> &arr) {
  cout << arr[0] << " " << arr[1] << '\n';
}
template <typename T>
void print(vector<T> &v) {
  for (T x : v) cout << x << " ";
  cout << '\n';
}
template <typename T>
T modInverse(T n, T p) {
  return power(n, p - 2, p) % p;
}
template <typename T>
void print(deque<T> &v) {
  for (auto x : v) cout << x << " ";
  cout << '\n';
}
long long nxt() {
  long long x;
  cin >> x;
  return x;
}
bool isPowerof2(long long x) { return !(x && (x & (x - 1))); }
