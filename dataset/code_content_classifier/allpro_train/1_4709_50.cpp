#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int modi(long long int n, long long int m = 1000000007) {
  n %= m;
  n += m;
  n %= m;
  return n;
}
long long int fib(long long int n) {
  if (n == 0 || n == 1)
    return 1;
  else {
    long long int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (long long int i = 2; i <= n; i++) {
      arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
  }
}
long long int mpow(long long int base, long long int exp) {
  base %= 1000000007;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % 1000000007;
    base = ((long long int)base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
long long int modInverse(long long int n) { return mpow(n, 1000000007 - 2); }
long long int nCrModPFermat(long long int n, long long int r) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 1000000007;
  return (fac[n] * modInverse(fac[r]) % 1000000007 * modInverse(fac[n - r]) %
          1000000007) %
         1000000007;
}
long long int is_prime(long long int a) {
  long long int i;
  if (a == 2 || a == 3)
    return 1;
  else
    for (i = 2; i * i <= a; i++) {
      if (a % i == 0) return 0;
    }
  return 1;
}
long long int digsum(long long int n) { return floor(log10(n)) + 1; }
long long int multiply(long long int x, long long int res[],
                       long long int res_size);
long long int factorial(long long int n) {
  long long int res[500];
  res[0] = 1;
  long long int res_size = 1;
  for (long long int x = 2; x <= n; x++) res_size = multiply(x, res, res_size);
  for (long long int i = res_size - 1; i >= 0; i--) cout << res[i];
}
long long int multiply(long long int x, long long int res[],
                       long long int res_size) {
  long long int carry = 0;
  for (long long int i = 0; i < res_size; i++) {
    long long int prod = res[i] * x + carry;
    res[i] = prod % 10;
    carry = prod / 10;
  }
  while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
  }
  return res_size;
}
long long int binsearch(long long int arr[], long long int l, long long int r,
                        long long int no) {
  while (l <= r) {
    long long int mid = (l + r) / 2;
    if (arr[mid] == no)
      return mid;
    else if (arr[mid] < no)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
string sortString(string &str) {
  long long int i = 0, j = 0, k = 0;
  long long int charCount[26] = {0};
  for (long long int i = 0; i < str.length(); i++) charCount[str[i] - 'a']++;
  for (long long int i = 0; i < 26; i++) {
    for (long long int j = 0; j < charCount[i]; j++) {
      str[k++] = char('a' + i);
    }
  }
  return str;
}
const long long int N = 2e5 + 5;
bool vis[N];
vector<long long int> adj[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i = 0, j = 0;
  long double p, q;
  cin >> p >> q;
  long long int n;
  cin >> n;
  bool check = true;
  for (long long int i = 0; i < n; i++) {
    long double a;
    cin >> a;
    if (!q) check = false;
    if (p / q < a) check = false;
    p = p - a * q;
    swap(p, q);
  }
  if (q == 0)
    check = true;
  else
    check = false;
  if (check)
    cout << "YES";
  else
    cout << "NO";
}
