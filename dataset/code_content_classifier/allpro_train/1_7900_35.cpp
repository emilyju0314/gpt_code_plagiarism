#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
long long n;
string S;
long long DP[200005][7][7], ini;
vector<long long> V[10];
long long dp(long long pos, long long pre_state) {
  if (DP[pos][pre_state][ini] != -1) return DP[pos][pre_state][ini];
  if (pos == n + 1) {
    for (auto v : V[pre_state]) {
      if (v == ini) return 0;
    }
    return INT_MAX;
  }
  long long mn = INT_MAX;
  for (auto v : V[pre_state]) {
    if ((v % 2 && S[pos - 1] == 'R') || (!(v % 2) && S[pos - 1] == 'L'))
      mn = min(mn, 1 + dp(pos + 1, v));
    else
      mn = min(mn, dp(pos + 1, v));
  }
  return DP[pos][pre_state][ini] = mn;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  V[1].push_back(3);
  V[1].push_back(5);
  V[2].push_back(1);
  V[2].push_back(3);
  V[3].push_back(4);
  V[3].push_back(6);
  V[4].push_back(1);
  V[4].push_back(3);
  V[5].push_back(4);
  V[5].push_back(6);
  V[6].push_back(2);
  long long cs, mn;
  cin >> cs;
  while (cs--) {
    cin >> n;
    cin >> S;
    mn = INT_MAX;
    for (long long i = 0; i <= n + 1; i++) {
      for (long long j = 1; j < 7; j++) {
        for (long long k = 1; k < 7; k++) {
          DP[i][j][k] = -1;
        }
      }
    }
    for (ini = 1; ini <= 6; ini++) {
      if ((ini % 2 && S[0] == 'R') || (!(ini % 2) && S[0] == 'L'))
        mn = min(mn, 1 + dp(2, ini));
      else
        mn = min(mn, dp(2, ini));
    }
    cout << mn << endl;
  }
  return 0;
}
