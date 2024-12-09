#include <bits/stdc++.h>
long long MOD = 1000000007;
long long inf = 1e18;
using namespace std;
priority_queue<long long> R, C;
long long L[1001][1001];
long long RR[1000001];
long long CC[1000001];
int main() {
  ios::sync_with_stdio(0);
  long long n, m, k, p, i, r, c, s, j, ans;
  long long anss = -inf;
  cin >> n >> m >> k >> p;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> L[i][j];
    }
  }
  RR[0] = 0;
  CC[0] = 0;
  for (i = 0; i < n; i++) {
    s = L[i][0];
    for (j = 1; j < m; j++) {
      s += L[i][j];
    }
    R.push(s);
  }
  for (i = 0; i < m; i++) {
    s = L[0][i];
    for (j = 1; j < n; j++) {
      s += L[j][i];
    }
    C.push(s);
  }
  for (i = 1; i <= k; i++) {
    r = R.top();
    R.pop();
    R.push(r - m * p);
    c = C.top();
    C.pop();
    C.push(c - n * p);
    RR[i] = r + RR[i - 1];
    CC[i] = c + CC[i - 1];
  }
  ans = -inf;
  for (i = 0; i <= k; i++) {
    j = k - i;
    ans = 0;
    ans += RR[i];
    ans += CC[j];
    ans -= (j * p * i);
    anss = max(ans, anss);
  }
  cout << anss << '\n';
  return 0;
}
