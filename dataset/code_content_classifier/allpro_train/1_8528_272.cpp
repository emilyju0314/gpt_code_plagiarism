#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod = 1e9 + 7;
const long long MOD = 2019;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long findSubarray(long long arr[], long long n, long long k) {
  long long window_sum = 0;
  long long min_window = INT_MAX;
  long long last = 0;
  for (long long i = 0; i < n; i++) {
    window_sum += arr[i];
    if (i + 1 >= k) {
      if (min_window > window_sum) {
        min_window = window_sum;
        last = i;
      }
      window_sum -= arr[i + 1 - k];
    }
  }
  long long sum = 0;
  for (long long i = last - k + 1; i <= last; i++) {
    sum += arr[i];
  }
  return sum;
}
long long nextpermutation(vector<long long> v) {
  vector<long long> t = v;
  sort((t).begin(), (t).end());
  long long x = 0;
  while (true) {
    x++;
    if (t == v) {
      return x;
    }
    next_permutation((t).begin(), (t).end());
  }
}
vector<long long> factors(long long n) {
  vector<long long> ans;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n == i * i)
        ans.push_back(i);
      else {
        ans.push_back(i);
        if (i != n / i) ans.push_back(n / i);
      }
    }
  }
  sort((ans).begin(), (ans).end());
  return ans;
}
bool isSubSequence(char str1[], char str2[], long long m, long long n) {
  if (m == 0) return true;
  if (n == 0) return false;
  if (str1[m - 1] == str2[n - 1])
    return isSubSequence(str1, str2, m - 1, n - 1);
  return isSubSequence(str1, str2, m, n - 1);
}
void findDivisors(long long n) {
  long long div[n + 1];
  memset(div, 0, sizeof div);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j * i <= n; j++) div[i * j]++;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) ans += i * div[i];
  cout << ans << "\n";
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCr(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long double dist(long long x1, long long y1, long long x2, long long y2) {
  long double a = (x1 - x2) * (x1 - x2);
  long double b = (y1 - y2) * (y1 - y2);
  return sqrt(a + b);
}
long long maxSubArraySum(vector<long long> a, long long size) {
  long long max_so_far = INT_MIN, max_ending_here = 0;
  for (long long i = 0; i < size; i++) {
    max_ending_here = max_ending_here + a[i];
    if (max_so_far < max_ending_here) max_so_far = max_ending_here;
    if (max_ending_here < 0) max_ending_here = 0;
  }
  return max_so_far;
}
long long min_modulo(long long l, long long r) {
  if (r - l >= MOD)
    return 0;
  else {
    long long ans = MOD - 1;
    for (long long i = l; i <= r; i++) {
      for (long long j = i + 1; j <= r; j++) {
        ans = min(ans, (i * j) % MOD);
      }
    }
    return ans;
  }
}
long long digitSum(long long n) {
  long long res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return (res);
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
string work(string s) {
  if (s.size() % 2) return s;
  string s1 = work(s.substr(0, s.size() / 2));
  string s2 = work(s.substr(s.size() / 2, s.size() / 2));
  if (s1 < s2)
    return s1 + s2;
  else
    return s2 + s1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed << setprecision(12);
  long long T;
  T = 1;
  for (long long tc = 0; tc < T; tc++) {
    string s, t;
    cin >> s >> t;
    string s1 = work(s);
    string s2 = work(t);
    if (s1 == s2)
      cout << ("Yes") << "\n";
    else
      cout << ("No") << "\n";
  }
  return 0;
}
