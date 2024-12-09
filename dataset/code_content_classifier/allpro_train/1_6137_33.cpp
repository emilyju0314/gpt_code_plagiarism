#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i< n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
typedef pair<int, int> P;

int dp[310][310];
int parx[310][310];
int pary[310][310];

int main(){
  string s;
  while(cin >> s && s != "#END"){
    int n = s.size();
    string res;
    for(int i = 1; i < n; i++){
      string a(s.begin(), s.begin() + i);
      string b(s.begin() + i, s.end());
      int sza = a.size(), szb = b.size();
      if(min(sza,szb) <= (int)res.size())continue;

      memset(dp, 0, sizeof(dp));
      memset(parx, -1, sizeof(parx));
      memset(pary, -1, sizeof(pary));

      rep2(i,1,sza+1)rep2(j,1,szb+1){
	if(dp[i][j] < dp[i-1][j]){
	  dp[i][j] = dp[i-1][j];
	  parx[i][j] = i-1;
	  pary[i][j] = j;
	}
	if(dp[i][j] < dp[i][j-1]){
	  dp[i][j] = dp[i][j-1];
	  parx[i][j] = i;
	  pary[i][j] = j-1;
	}
	if(a[i-1] == b[j-1] && dp[i][j] < dp[i-1][j-1] + 1){
	  dp[i][j] = dp[i-1][j-1] + 1;
	  parx[i][j] = i-1;
	  pary[i][j] = j-1;
	}
      }
      string lss;
      int x = sza;
      int y = szb;
      while(x != -1){
	int nx = parx[x][y];
	int ny = pary[x][y];
	if(x - nx == 1 && y - ny == 1 && x > 0)lss.push_back(a[x-1]);
	x = nx;
	y = ny;
      }
      reverse(lss.begin(), lss.end());
      if(lss.size() > res.size()) res = lss;
    }
    cout << res << endl;
  }
  return 0;
}