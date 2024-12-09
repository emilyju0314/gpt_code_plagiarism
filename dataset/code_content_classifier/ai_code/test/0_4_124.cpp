#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int n;
string s,t;
ll dp[2005][2005][2];
ll dfs(int i, int j, int val){
  if(i == n and j == n) 
      return val ? 0 : 1;
  if(~dp[i][j][val]) return dp[i][j][val];
  ll ans = 0;
  if(i == j){
    if(s[i] != t[j]){
      if(s[i] == '1' and t[j] == '0' and val) return 0;
      if(s[i] == '0' and t[j] == '1' and !val) return 0;
    }
    if(s[i] != '?'){
      if(s[i] != t[j]) return 0;
      return dfs(i + 1, j + 1, val);
    }
    if(t[j] != '?'){
      int d = t[j] - '0';
      if(d <= val) return 0;
      return dfs(i + 1, j + 1, d);
    }
    return dfs(i + 1, j + 1, val) * 2 % mod;
  }
  if(i < j){
    if(s[i] != '?' and s[j] != '?'){
      return (s[i] != s[j]) == val and t[i] == '?' and t[j] == '?' ? 0 : 1;
    }
    else if(s[i] == '?' and s[j] == '?'){
      if(t[i] == '?' and t[j] == '?'){
        return dfs(i + 1, j + 1, val) * 2 % mod;
      }
      if(t[i] == '1') ans += dfs(i + 1, j, val);
      if(t[j] == '1') ans += dfs(i, j - 1, val);
      return ans % mod;
    }
    else if(s[i] == '?'){
      swap(i, j);
      swap(s, t);
      return dfs(i, j, val);
    }
  }
}
int main(){
  int tt;
  cin >> tt;
  while(tt--){
    cin >> n >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, n-1, 0) << '\n';
  }
}