#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double eps = 1e-9;
long double pi = 3.14159265358979323846264338327950;
long double e = 2.7182818284590452353602874713527;
const int N = 1e3 + 3;
int a[N], n, k;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int Find(int prv, int nxt) {
  int cr = 2;
  while (1) {
    if (gcd(cr, prv) == 1 && gcd(cr, nxt) == 1) break;
    cr++;
  }
  return cr;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> ans;
  ans.push_back(a[0]);
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    int prv = ans.back();
    int nxt = a[i];
    if (gcd(prv, nxt) > 1) {
      int ins = Find(prv, nxt);
      ans.push_back(ins);
      cnt++;
    }
    ans.push_back(nxt);
  }
  cout << cnt << endl;
  for (int i = 0; i < ((int)(ans).size()); i++) cout << ans[i] << " ";
  return 0;
}
