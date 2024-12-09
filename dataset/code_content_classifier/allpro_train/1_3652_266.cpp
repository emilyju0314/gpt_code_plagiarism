#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long EXP(long long x, long long p) {
  if (p == 0) return 1;
  long long Ans = EXP(x, p / 2);
  Ans = (Ans * Ans) % N;
  if (p % 2 == 1) Ans *= x;
  return Ans % N;
}
string s;
long long dp[2005][2005];
long long k[2005][2005];
long long F(int i, int j) {
  if (i >= j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  long long ans = 0;
  if (s[i] == ')') ans = F(i + 1, j);
  if (s[j] == '(') ans = F(i, j - 1);
  if (s[i] == '(' && s[j] == ')') {
    ans = (F(i + 1, j - 1) + EXP(2, k[i + 1][j - 1])) % N;
  }
  if (s[i] == '(' && s[j] == '?')
    ans = ((F(i + 1, j - 1) + EXP(2, k[i + 1][j - 1])) % N + F(i, j - 1)) % N;
  if (s[i] == '?' && s[j] == ')')
    ans = ((F(i + 1, j - 1) + EXP(2, k[i + 1][j - 1])) % N + F(i + 1, j)) % N;
  if (s[i] == '?' && s[j] == '?') {
    ans = ((F(i + 1, j - 1) + EXP(2, k[i + 1][j - 1])) % N +
           (F(i + 1, j) + F(i, j - 1) - F(i + 1, j - 1)) % N) %
          N;
  }
  return dp[i][j] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> s;
  for (int i = 0; i < 2005; i++) {
    for (int j = 0; j < 2005; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    long long cons = 0;
    for (int j = i; j < s.length(); j++) {
      if (s[j] == '?') cons++;
      k[i][j] = cons;
    }
  }
  cout << (F(0, s.length() - 1) + N) % N << endl;
  return 0;
}
