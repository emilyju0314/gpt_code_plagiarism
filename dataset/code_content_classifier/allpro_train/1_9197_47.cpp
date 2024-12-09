#include <bits/stdc++.h>
using namespace std;
const long long lar = 1e16;
const long long nlar = -1e16;
const long long INF = LLONG_MAX;
const long long NINF = LLONG_MIN;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 100;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long double sqrtBinarySearch(long long num, long long p) {
  long long left = 0, right = num;
  long long mid;
  long double res;
  while (left <= right) {
    mid = (left + right) / 2;
    if (mid * mid == num) {
      res = mid;
      break;
    }
    if (mid * mid < num) {
      left = mid + 1;
      res = mid;
    } else {
      right = mid - 1;
    }
  }
  long double incr = 0.1;
  for (long long i = 0; i < p; i++) {
    while (res * res <= num) {
      res += incr;
    }
    res -= incr;
    incr /= 10;
  }
  return res;
}
long long modInverse(long long a, long long m) {
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
long long add(long long x, long long y) {
  x += y;
  while (x >= mod) x -= mod;
  while (x < 0) x += mod;
  return x;
}
long long mul(long long x, long long y) { return (x * 1ll * y) % mod; }
long long binpow(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y % 2 == 1) ans = mul(ans, x);
    x = mul(x, x);
    y /= 2;
  }
  return ans;
}
long long divmod(long long i, long long pp) {
  return ((i * (modInverse(pp, mod))) % mod);
}
long long divide(long long x, long long y) {
  return mul(x, binpow(y, mod - 2));
}
string to_binary(long long num) {
  string res = "";
  while (num) {
    res += ((num & (1LL)) + '0');
    num /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}
long long to_decimal(string bi) {
  long long dec = 0;
  long long si = bi.size();
  long long upd = 1;
  for (long long i = si - 1; i >= 0; i--) {
    dec += (upd * ((long long)(bi[i] - '0')));
    upd *= 2;
  }
  return dec;
}
vector<bool> SieveOfEratosthenes(long long n) {
  vector<bool> prime(n + 1, true);
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  return prime;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long digitsum(long long x) {
  long long ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
long long nCr(long long n, long long r) {
  if (n == r)
    return 1;
  else if (r == 0)
    return 1;
  else
    return ((nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod);
}
long long sqroot(long long number) {
  long long x = sqrt(number);
  while (x * x < number) x++;
  while (x * x > number) x--;
  return x;
}
long long cbroot(long long number) {
  long long x = cbrt(number);
  while (x * x * x < number) x++;
  while (x * x * x > number) x--;
  return x;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b % a, a);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * power(a, b - 1));
  long long temp = power(a, b / 2);
  return (temp * temp);
}
long long powermod(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * powermod(a, b - 1)) % mod;
  long long temp = powermod(a, b / 2) % mod;
  return (temp * temp) % mod;
}
vector<long long> factor(long long x) {
  vector<long long> fact;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      fact.push_back(i);
      if (i * i != x) {
        fact.push_back(x / i);
      }
    }
  }
  return fact;
}
long long fact[N];
void Initial_Factorial() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i);
    fact[i] %= mod;
  }
}
long long binpow(long long val, long long deg, long long mod) {
  if (!deg) return 1 % mod;
  if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
  long long res = binpow(val, deg >> 1, mod);
  return (res * res) % mod;
}
long long nCr_Binomial(long long n, long long i) {
  long long res = fact[n];
  long long div = fact[n - i] * fact[i];
  div %= mod;
  div = binpow(div, mod - 2, mod);
  return (res * div) % mod;
}
vector<long long> adj[10];
long long number_of_nodes = 10;
vector<long long> visited(number_of_nodes, 0);
void dfs(long long node) {
  visited[node] = 1;
  for (long long i = 0; i < adj[node].size(); ++i) {
    if (visited[adj[node][i]] == 0) dfs(adj[node][i]);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n, 0), b(n, 0);
  map<long long, long long> ind;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    ind[b[i]] = i;
  }
  vector<long long> cnt(n + 10, 0);
  for (long long i = 0; i < n; i++) {
    if (i <= ind[a[i]]) {
      cnt[ind[a[i]] - i]++;
    } else {
      cnt[n - (i - ind[a[i]])]++;
    }
  }
  long long ans = *max_element((cnt).begin(), (cnt).end());
  cout << ans << '\n';
  cerr << "time taken : " << (long double)clock() / CLOCKS_PER_SEC << "secs"
       << '\n';
  return 0;
}
