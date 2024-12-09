#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long linf = (long long)1e18;
const double eps = (double)1e-8;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 5;
const int MX = (int)2e6;
const double pi = acos(-1);
int p[MX + 5];
long long s[MX + 5], k[MX + 5];
long long ans;
long long n, first, second;
vector<int> pr;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = (2); i <= (int)(MX / 2); ++i) {
    if (p[i]) continue;
    pr.push_back(i);
    for (long long j = (long long)i * i; j <= MX / 2; j += i) p[j] = 1;
  }
  memset((s), 0, sizeof(s));
  memset((k), 0, sizeof(k));
  cin >> n >> first >> second;
  for (int i = (1); i <= (int)(n); ++i) {
    int x;
    cin >> x;
    ++k[x];
    s[x] += x;
  }
  for (int i = (1); i <= (int)(MX); ++i) {
    s[i] = s[i - 1] + s[i];
    k[i] = k[i - 1] + k[i];
  }
  ans = n * min(first, second);
  for (int i = (0); i < (int)(pr.size()); ++i) {
    int x = pr[i];
    int c = first / second;
    c = min(x - 1, c);
    int y = x;
    long long o = 0;
    while (y <= MX) {
      o += ((k[y] - k[y - c - 1]) * y - (s[y] - s[y - c - 1])) * second;
      o += (k[y - c - 1] - k[y - x]) * first;
      y += x;
    }
    ans = min(ans, o);
  }
  cout << ans << "\n";
  return 0;
}
