#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= m;
    (a *= a) %= m;
    b >>= 1;
  }
  return ans;
}
long long f[200005], p[200005], sp[200005], a[200005], b[200005];
map<int, int> arr;
void pre(long long m) {
  f[0] = 1;
  f[1] = 1, p[1] = 0, sp[1] = 0;
  for (int i = 2; i < 200005; i++) {
    p[i] = 0;
    int x = i;
    while (!(x & 1)) {
      x >>= 1;
      p[i]++;
    };
    f[i] = f[i - 1] * (i / (1 << p[i]));
    f[i] %= m;
    sp[i] = sp[i - 1] + p[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(30);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    arr[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    arr[b[i]]++;
  }
  long long m;
  cin >> m;
  pre(m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (a[i] == b[i]);
  }
  long long prod = 1;
  long long cnt2 = 0;
  for (auto x : arr) {
    int tmp = x.second;
    (prod *= f[tmp]) %= m;
    cnt2 += sp[tmp];
  }
  cnt2 -= cnt;
  long long pw = modpow(2, cnt2, m);
  (prod *= pw) %= m;
  cout << prod << endl;
}
