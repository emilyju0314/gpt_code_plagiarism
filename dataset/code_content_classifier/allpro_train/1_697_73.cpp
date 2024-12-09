#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powmod(long long a, long long b, long long p) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long temp = powmod(a, b / 2, p);
  temp *= temp;
  temp %= p;
  if (b % 2 == 0) return temp;
  temp = temp * a;
  temp %= p;
  return temp;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (__typeof((n)) i = (0); i < (n); i++) cin >> a[i];
  multiset<int> b;
  for (__typeof((n)) i = (0); i < (n); i++) {
    int x;
    cin >> x;
    b.insert(x);
  }
  for (__typeof((n)) i = (0); i < (n); i++) {
    auto it = b.lower_bound(n - a[i]);
    if (it == b.end()) it = b.begin();
    cout << (a[i] + *it) % n << " ";
    b.erase(it);
  }
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
