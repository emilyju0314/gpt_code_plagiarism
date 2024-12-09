#include <bits/stdc++.h>
const int md = 1000000007;
using namespace std;
using namespace std::chrono;
long long pw(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m);
    b /= 2;
  }
  return c;
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long inverse(long long i) {
  if (i == 1) return 1;
  return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
long long ceel(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
long long my_log(long long n, long long b) {
  long long i = 1;
  long long ans = 0;
  while (1) {
    if (i > n) {
      ans--;
      break;
    }
    if (i == n) break;
    i *= b;
    ans++;
  }
  return ans;
}
bool is(string r) {
  string p = r;
  reverse(p.begin(), p.end());
  return (r == p);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<char> capl = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> sml = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string conv(long long a) {
  string b;
  int c = my_log(a, 2);
  c++;
  b = '1';
  for (int i = 0; i < c - 1; i++) {
    long long k = a >> (c - 2 - i);
    if (k & 1)
      b += '1';
    else
      b += '0';
  }
  return b;
}
long long link[100001];
long long sz[100001];
int fnd(long long x) {
  while (x != link[x]) x = link[x];
  return x;
}
bool same(long long a, long long b) { return fnd(a) == fnd(b); }
void unite(long long a, long long b) {
  a = fnd(a);
  b = fnd(b);
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  link[b] = a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, a, b, e, a1, b1, e1, c, d, w;
  cin >> n >> m;
  vector<tuple<long long, long long, long long>> v;
  cin >> a1 >> b1 >> e1;
  for (long long i = 1; i < m; i++)
    cin >> a >> b >> e, v.push_back(make_tuple(e, a, b));
  sort(v.begin(), v.end());
  long long x = 0;
  for (long long i = 1; i <= n; i++) link[i] = i;
  for (long long i = 1; i <= n; i++) sz[i] = 1;
  long long cnt = 0;
  for (long long i = 0; i < m - 1; i++) {
    c = get<1>(v[i]), d = get<2>(v[i]), w = get<0>(v[i]);
    if (same(c, d))
      continue;
    else {
      x += w;
      cnt++;
      unite(c, d);
    }
  }
  if (cnt < n - 1) {
    cout << 1000000000;
    return 0;
  }
  long long y = 0;
  cnt = 1;
  for (long long i = 1; i <= n; i++) link[i] = i;
  for (long long i = 1; i <= n; i++) sz[i] = 1;
  unite(a1, b1);
  for (long long i = 0; i < m - 1; i++) {
    c = get<1>(v[i]), d = get<2>(v[i]), w = get<0>(v[i]);
    if (same(c, d))
      continue;
    else {
      y += w;
      cnt++;
      unite(c, d);
    }
  }
  cout << x - y;
}
