#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  string s,t; cin >> s >> t;
  int S=s.size(), T=t.size();
  int dp[S+1][T+1];
  memset(dp, 0, sizeof(dp));

  REP(i,S) REP(j,T) {
    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
    if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
  }

  int i=S,j=T;
  string ans;
  while (i>0 && j>0) {
    if(dp[i][j] == dp[i-1][j]) i--;
    else if (dp[i][j] == dp[i][j-1]) j--;
    else {
      i--; j--; ans.push_back(s[i]);
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}