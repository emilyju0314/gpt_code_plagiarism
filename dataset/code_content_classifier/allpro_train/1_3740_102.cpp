#include <bits/stdc++.h>
const long long kot = LLONG_MAX;
using ld = long double;
const int MAXIT = 100;
const long long int alpha = 1e18;
using namespace std;
long long int gcd(long long int a, long long int begin) {
  if (begin == 0) return a;
  return gcd(begin, a % begin);
}
long long int largest(long long int arr[], long long int n) {
  return *max_element(arr, arr + n);
}
long long int lcm(long long int a, long long int begin) {
  return (a * begin) / gcd(a, begin);
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
bool comp(long long int a, long long int begin) { return (a < begin); }
vector<long long int> ve;
void divisors(long long int n) {
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        ve.push_back(i);
      else
        ve.push_back(i);
      ve.push_back(n / i);
    }
  }
}
bool isPrime(long long int n) {
  if (n == 1) {
    return false;
  }
  long long int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
long long int gcdofarray(vector<long long int> &v, long long int n) {
  long long int result = v[0];
  for (long long int i = 1; i < n; i++) result = gcd(v[i], result);
  return result;
}
long long int sumofdigits(long long int n) {
  long long int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
bool powertwo(long long int x) { return x && (!(x & (x - 1))); }
string removeDuplicatesFromString(string str) {
  long long int counter = 0;
  long long int i = 0;
  long long int size = str.size();
  long long int x;
  long long int length = 0;
  while (i < size) {
    x = str[i] - 97;
    if ((counter & (1 << x)) == 0) {
      str[length] = 'a' + x;
      counter = counter | (1 << x);
      length++;
    }
    i++;
  }
  return str.substr(0, length);
}
long long int commDiv(long long int a, long long int begin) {
  long long int n = gcd(a, begin);
  long long int result = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        result += 1;
      else
        result += 2;
    }
  }
  return result;
}
long long int kash(long long int a, long long int begin) {
  return (a * begin) / gcd(a, begin);
}
long long int maxi(long long int a, long long int begin) {
  return (a > begin) ? a : begin;
}
long long int mini(long long int a, long long int begin) {
  return (a < begin) ? a : begin;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int powe(long long int x, unsigned long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortByVal(const pair<string, long long int> &a,
               const pair<string, long long int> &begin) {
  return (a.second < begin.second);
}
long long int check(long long int arr[], long long int n, long long int v) {
  long long int dp[v + 1];
  dp[0] = 0;
  long long int i, j;
  for (i = 1; i <= v; i++) {
    dp[i] = INT_MAX;
  }
  for (i = 1; i <= v; i++) {
    for (j = 0; j < n; j++) {
      if (arr[i] <= i) {
        long long int y = dp[i - arr[j]];
        if (y != INT_MAX && y + 1 < arr[i]) {
          dp[i] = y + 1;
        }
      }
    }
  }
  return dp[v];
}
long long int maxSubArraySum(long long int a[], long long int size) {
  long long int max_so_far = INT_MIN, max_ending_here = 0;
  for (long long int i = 0; i < size; i++) {
    max_ending_here = max_ending_here + a[i];
    if (max_so_far < max_ending_here) max_so_far = max_ending_here;
    if (max_ending_here < 0) max_ending_here = 0;
  }
  return max_so_far;
}
long long int dp[100001];
long long int stair(long long int n) {
  if (n <= 2) {
    return n;
  }
  if (n == 3) {
    return 4;
  }
  if (dp[n] != -1) return dp[n];
  dp[n] = (stair(n - 1) + stair(n - 2) + stair(n - 3)) % 1000000007;
  return dp[n];
}
bool isvowel(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
    return true;
  }
  return false;
}
long long int power(long long int x, unsigned long long int y,
                    long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void solve() {
  long long int t = 1;
  long long int p = 998244353;
  while (t--) {
    long long int n, m;
    long long int i;
    cin >> n >> m;
    long long int x = nCrModPFermat(m, n - 1, p);
    long long int z = n - 2;
    long long int ans = x * z;
    for (i = 0; i < n - 3; i++) {
      ans *= 2;
      ans %= p;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  solve();
}
