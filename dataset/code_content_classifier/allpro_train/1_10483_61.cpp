#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
const long long MOD = 1e9 + 7;
long long n, x, store[MAXN];
void add(long long& a, long long b) { a = (a + b) % MOD; }
void addElement(long long k) {
  vector<long long> div;
  for (long long i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      div.push_back(i);
      if (i != k / i) div.push_back(k / i);
    }
  }
  sort(div.begin(), div.end(), greater<long long>());
  for (long long d : div) {
    add(store[d], store[d - 1]);
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  store[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    addElement(x);
  }
  long long ans = 0;
  for (int i = 1; i < MAXN; i++) {
    add(ans, store[i]);
  }
  cout << ans << endl;
  return 0;
}
