#include <bits/stdc++.h>

using namespace std;

bool solve(int n)
{
  string str[505];
  for(int i = 0; i < n; i++) cin >> str[i];

  bool G[33][33] = {{false}};
  for(int i = 0; i < n-1; i++) {
    bool flag = (str[i].size() <= str[i+1].size());
    for(int j = 0; j < min(str[i].size(), str[i+1].size()); j++) {
      if(str[i][j] != str[i+1][j]) {
	G[str[i][j]-'a'][str[i+1][j]-'a'] = true;
	flag = true;
	break;
      }
    }
    if(!flag) return true;
  }
  
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      for(int k = 0; k < 26; k++) {
	G[j][k] |= G[j][i] & G[i][k];
      }
    }
  }
  
  bool ans = false;
  for(int i = 0; i < 26; i++) ans |= G[i][i];

  return ans;
}

int main()
{
  int n;
  while(cin >> n, n) {
    cout << (solve(n) ? "no" : "yes") << endl;
  }
  return 0;
}