#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long cnt[maxn], mu[maxn];
bool vis[maxn];
vector<int> v[maxn];
void updata(int x, int a) {
  for (int i : v[x]) cnt[i] += a;
}
long long check(int x) {
  long long res = 0;
  for (int i : v[x]) res += mu[i] * cnt[i];
  return res;
}
int main() {
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) v[j].push_back(i);
    if (i == 1)
      mu[i] = -1;
    else if ((i / v[i][1]) % v[i][1] == 0)
      mu[i] = 0;
    else
      mu[i] = -mu[i / v[i][1]];
  }
  long long n, a, ans = 0ll;
  cin >> n;
  while (n--) {
    cin >> a;
    ans = max(a, ans);
    vis[a] = true;
  }
  stack<int> s;
  for (int g = 1; g < maxn; g++) {
    for (int i = maxn / g; i > 0; i--) {
      if (!vis[i * g]) continue;
      while (check(i)) {
        ans = max(ans, 1ll * i * g * s.top());
        updata(s.top(), -1);
        s.pop();
      }
      updata(i, 1);
      s.push(i);
    }
    while (!s.empty()) {
      updata(s.top(), -1);
      s.pop();
    }
  }
  cout << ans;
}
