#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main() {
  int s,d,m;
  while(cin>>s>>d>>m) {
    vector<vector<int>> dp(s);
    REP(i,s) {
      int k;
      cin>>k;
      vector<vector<int>> dpi(k+1, vector<int>(m+1));
      REP(j,k) {
        int w, p;
        cin>>w>>p;
        for (int l=0; l<min(p,m+1); ++l) {
          dpi[j+1][l] = dpi[j][l];
        }
        for (int l=p; l<=m; ++l) {
          dpi[j+1][l] = max(dpi[j][l-p] + w, dpi[j][l]);
        }
      }
      dp[i] = dpi[k];
    }
    vector<vector<int>> dp2(d+1, vector<int>(m+1));
    REP(i,d) {
      int f;
      cin>>f;
      REP(j,m+1) {
        dp2[i+1][j] = dp2[i][j];
        REP(k,j+1) {
          dp2[i+1][j] = max(dp2[i][k] + dp[f][j-k], dp2[i+1][j]);
        }
      }
    }
    int maxef = 0;
    int ati = 0;
    REP(i,m+1) {
      if (maxef < dp2[d][i]) {
        maxef = dp2[d][i];
        ati = i;
      }
    }
    cout << maxef << ' ' << ati << endl;
  }
  return 0;
}