#include <bits/stdc++.h>
using namespace std;
long long fac[1000006];
inline long long exp(long long x, long long n) {
  long long r = 1;
  x = x % 1000000007;
  while (n) {
    if (n % 2) r = (r * x) % 1000000007;
    x = (x * x) % 1000000007;
    n = n / 2;
  }
  return r;
}
inline long long mmi(long long a) {
  return exp(a, 1000000007 - 2) % 1000000007;
}
inline long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i < (n + 1); ++i) {
    res = (res * i) % 1000000007;
  }
  return res;
}
inline void fact_a() {
  fac[0] = 1;
  fac[1] = 1;
  for (long long i = 1; i < (1000006); ++i) {
    fac[i] = (fac[i - 1] * i) % 1000000007;
  }
}
inline long long inv_fact(long long n) {
  fact_a();
  long long par = fac[n];
  long long res = mmi(par);
  return res;
}
inline long long comb(long long n, long long r) {
  fact_a();
  if (n < r) return 0;
  return ((fac[n] * inv_fact(r)) % 1000000007 * inv_fact(n - r)) % 1000000007;
}
struct triplet {
  long long a, b, c;
};
bool operator<(const triplet &t1, const triplet &t2) {
  if (t1.a < t2.a) return true;
  if (t1.a == t2.a && t1.b < t2.b) return true;
  if (t1.a == t2.a && t1.b == t2.b && t1.c < t2.c) return true;
  return false;
}
pair<long long, pair<long long, long long> > ex_gcd(long long a, long long b) {
  if (b == 0) {
    return make_pair(a, make_pair(1, 0));
  }
  pair<long long, pair<long long, long long> > p = ex_gcd(b, a % b);
  long long gcd = p.first;
  long long x1 = p.second.first;
  long long y1 = p.second.second;
  long long x = y1;
  long long y = x1 - (a / b) * y1;
  return make_pair(gcd, make_pair(x, y));
}
long long prime[1000006];
long long spf_prime[1000006];
void sieve() {
  for (long long i = 2; i * i <= 1000000; i++)
    if (prime[i] == 0)
      for (long long j = i * i; j <= 1000000; j += i) prime[j] = 1;
}
void spf() {
  for (long long i = 2; i * i <= 1000000; i++)
    if (!spf_prime[i])
      for (long long j = i * i; j <= 1000000; j += i)
        if (!spf_prime[j]) spf_prime[j] = i;
  for (long long i = 2; i <= 1000000; i++)
    if (!spf_prime[i]) spf_prime[i] = i;
}
long long getparent_BIT(long long idx) { return idx - (idx & -idx); }
long long getnext_BIT(long long idx) { return idx + (idx & -idx); }
long long getsum_BIT(long long idx, long long BIT[], long long n) {
  long long sum = 0;
  while (idx > 0) {
    sum += BIT[idx];
    idx = getparent_BIT(idx);
  }
  return sum;
}
void update_BIT(long long idx, long long BIT[], long long val, long long n) {
  while (idx <= n) {
    BIT[idx] += val;
    idx = getnext_BIT(idx);
  }
}
void build_BIT(long long BIT[], long long a[], long long n) {
  for (long long i = 0; i < (n); ++i) {
    update_BIT(i, BIT, a[i], n);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<pair<long long, long long> > vv(8);
  map<long long, long long> mp1;
  map<long long, long long> mp2;
  vector<long long> v;
  vector<long long> u;
  for (long long i = 0; i < (8); ++i) {
    long long x, y;
    cin >> x >> y;
    vv[i].first = x;
    vv[i].second = y;
    if (mp1.find(x) == mp1.end()) u.push_back(x);
    if (mp2.find(y) == mp2.end()) v.push_back(y);
    mp1[x]++;
    mp2[y]++;
  }
  if (mp1.size() != 3 || mp2.size() != 3) {
    cout << "ugly"
         << "\n";
    exit(0);
  } else {
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    mp1[u[1]]++;
    mp2[v[1]]++;
    for (auto it : mp1) {
      if (it.second != 3) {
        cout << "ugly"
             << "\n";
        exit(0);
      }
    }
    for (auto it : mp2) {
      if (it.second != 3) {
        cout << "ugly"
             << "\n";
        exit(0);
      }
    }
    vv.push_back(make_pair(u[1], v[1]));
    vector<pair<long long, long long> > uu;
    for (long long i = 0; i < (3); ++i)
      for (long long j = 0; j < (3); ++j) uu.push_back(make_pair(u[i], v[j]));
    sort(uu.begin(), uu.end());
    sort(vv.begin(), vv.end());
    for (long long i = 0; i < (9); ++i) {
      if (uu[i].first != vv[i].first || uu[i].second != vv[i].second) {
        cout << "ugly"
             << "\n";
        exit(0);
      }
    }
  }
  cout << "respectable"
       << "\n";
}
