#include <bits/stdc++.h>
using namespace std;
long long gcd(long long n, long long m) {
  if (n == 0) return m;
  return gcd(m % n, n);
}
bool ifprime(long long n) {
  if (n == 1) return false;
  long long i;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void disp(vector<long long> v) {
  for (auto u : v) cout << u << " ";
  cout << "\n";
}
void remleadzero(vector<int> &v) {
  vector<int> u;
  int i = 0;
  while (v[i] == 0) i++;
  while (i < v.size()) {
    u.push_back(v[i]);
    i++;
  }
  v = u;
}
long long fast_expo(long long n, long long m, long long md) {
  long long a = 1;
  while (m > 0) {
    if (m & 1) a = (a * n) % md;
    n = (n * n) % md;
    m /= 2;
  }
  return a % md;
}
long long sqroot(long long n) {
  long double N = n;
  N = sqrtl(N);
  long long sq = N - 2;
  sq = max(sq, 0LL);
  while (sq * sq < n) {
    sq++;
  }
  if ((sq * sq) == n) return sq;
  return -1;
}
const long long N = 200005;
const int BLOCK = 300;
int pref[N], first[N], L[N];
int cnt[(BLOCK + 10) * N];
int main() {
  using namespace chrono;
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  chrono::high_resolution_clock::time_point t1 =
      chrono::high_resolution_clock::now();
  string s;
  cin >> s;
  pref[0] = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + (s[i] - '0');
  }
  long long ans = 0;
  for (long long k = 1; k <= BLOCK; k++) {
    for (int i = 0; i <= n; i++) {
      ans += cnt[k * pref[i] - i + n]++;
    }
    for (int i = 0; i <= n; i++) {
      cnt[k * pref[i] - i + n]--;
    }
  }
  int mx1 = n / BLOCK;
  memset(first, -1, sizeof(first));
  memset(L, -1, sizeof(L));
  for (int i = 0; i <= n; i++) {
    L[pref[i]] = i;
    if (first[pref[i]] == -1) first[pref[i]] = i;
  }
  chrono::high_resolution_clock::time_point t2 =
      chrono::high_resolution_clock::now();
  duration<double> tot = duration_cast<duration<double>>(t2 - t1);
  for (int i = 0; i < n; i++) {
    for (int ct = 1; ct < mx1; ct++) {
      long long req = pref[i] + ct;
      if (L[req] == -1) continue;
      if (req > pref[n]) break;
      int val = ((L[req] - i) / ct);
      val -= max((first[req] - i - 1) / ct, BLOCK);
      if (val > 0) ans += val;
    }
  }
  t1 = chrono::high_resolution_clock::now();
  tot = duration_cast<duration<double>>(t1 - t2);
  cout << ans << '\n';
  return 0;
}
