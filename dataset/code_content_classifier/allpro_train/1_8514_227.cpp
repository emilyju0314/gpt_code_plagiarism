#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAXN = 100000 + 10;
ll a[100000 + 10];
ll sumEvenL[MAXN];
ll sumEvenR[MAXN];
ll sumOdd[MAXN];
ll n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n--;
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    sumOdd[i] = sumOdd[i - 1] + a[i - 1] - (1 - (1 & a[i - 1]));
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] >= 2)
      sumEvenL[i] = sumEvenL[i - 1] + a[i - 1] - (1 & a[i - 1]);
  }
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] >= 2) sumEvenR[i] = sumEvenR[i + 1] + a[i] - (1 & a[i]);
  }
  ll mmax = 0;
  ll ret = 0;
  for (int i = 0; i <= n; ++i) {
    mmax = max(mmax, sumEvenL[i] - sumOdd[i]);
    ret = max(ret, sumOdd[i] + sumEvenR[i] + mmax);
  }
  cout << ret << endl;
}
