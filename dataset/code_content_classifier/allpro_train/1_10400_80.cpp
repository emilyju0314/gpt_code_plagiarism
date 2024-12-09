#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long gcd(long long a, long long b) {
  if (a < b)
    return gcd(b, a);
  else if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long pow(long long b, long long e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long a = pow(b, e / 2);
    return a * a;
  } else {
    long long a = pow(b, e / 2);
    return b * a * a;
  }
}
long long pow_m(long long x, long long y, long long m = 1000000007) {
  x = x % m;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long modInverse(long long a, long long m) { return pow_m(a, m - 2, m); }
long long max(long long a, long long b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a <= b)
    return a;
  else
    return b;
}
long long sum(vector<long long> v) {
  long long sm = 0;
  for (long long i = 0; 0 < v.size() ? i < v.size() : i > v.size();
       0 < v.size() ? i += 1 : i -= 1)
    sm += v[i];
  return sm;
}
long long bin_coff(long long n, long long k, long long m) {
  vector<vector<long long> > ans(n + 1, vector<long long>(k, 0));
  for (long long i = 0; 0 < n + 1 ? i < n + 1 : i > n + 1;
       0 < n + 1 ? i += 1 : i -= 1) {
    for (long long j = 0;
         0 < min(i, k) + 1 ? j < min(i, k) + 1 : j > min(i, k) + 1;
         0 < min(i, k) + 1 ? j += 1 : j -= 1) {
      if (j == 0 || j == i)
        ans[i][j] = 1;
      else
        ans[i][j] = ans[i - 1][j - 1] % m + ans[i - 1][j] % m;
    }
  }
  return ans[n][k] % m;
}
long long inverse(long long i) {
  if (i == 1) return 1;
  return (1000000007 -
          ((1000000007 / i) * inverse(1000000007 % i)) % 1000000007 +
          1000000007) %
         1000000007;
}
long long maxProduct(vector<long long> arr, long long n, long long k) {
  sort(arr.begin(), arr.end());
  long long prod = 1;
  if (arr[n - 1] == 0 && (k & 1)) return 0;
  if (arr[n - 1] <= 0 && (k & 1)) {
    for (long long i = n - 1; i >= n - k; i--) prod *= arr[i];
    return prod;
  }
  long long i = 0, j = n - 1;
  if (k & 1) {
    prod *= arr[j];
    j--;
    k--;
  }
  k >>= 1;
  for (long long itr = 0; itr < k; itr++) {
    long long left_product = arr[i] * arr[i + 1];
    long long right_product = arr[j] * arr[j - 1];
    if (left_product > right_product) {
      prod *= left_product;
      i += 2;
    } else {
      prod *= right_product;
      j -= 2;
    }
  }
  return prod;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 2) {
    if (s[0] >= s[1])
      cout << "NO" << endl;
    else
      cout << "YES" << endl << "2" << endl << s[0] << " " << s[1] << endl;
  } else {
    cout << "YES" << endl << "2" << endl;
    cout << s[0] << " " << s.substr(1) << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
