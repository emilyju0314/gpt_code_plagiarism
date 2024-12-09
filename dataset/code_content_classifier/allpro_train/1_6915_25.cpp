#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lli;

const int MAXR = 10;
const int MAXC = 10;
const int DPSIZE = 60000;
const lli MOD = 100000007LL;


int R, C;
int G[MAXR][MAXC];

int three[MAXC+1];
lli dp[2][3][DPSIZE]; // pos, need from left, need from top

void init() {
  three[0] = 1;
  for(int i = 1; i < MAXC+1; ++i) {
    three[i] = three[i-1] * 3;
  }
}

int main() {
  init();
  while(cin >> R >> C) {
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < C; ++j) {
        char c;
        cin >> c;
        if(c == '.') G[i][j] = 0;
        else G[i][j] = c - '0';
      }
    }

    fill(dp[0][0], dp[2][0], 0LL);
    dp[0][0][0] = 1LL;
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < C; ++j) {
        int p = (i*C+j) % 2;
        int q = 1-p;
        for(int l = 0; l < 3; ++l)
          for(int b = 0; b < three[C]; ++b)
            dp[q][l][b] = 0LL;

        for(int l = 0; l < 3; ++l) {
          for(int b = 0; b < three[C]; ++b) {
            if(dp[p][l][b] == 0LL) continue;
            int t = b % 3;
            if(G[i][j] == 0) {
              int k = l;
              if(j+1 == C && k != 0) continue;
              int u = t;
              if(k * u != 0) continue;
              int nb = ( b + three[C] * u ) / 3;
              dp[q][k][nb] = ( dp[q][k][nb] + dp[p][l][b] ) % MOD;
            } else {
              int r = G[i][j] - (l + t);
              if(r < 0) continue;
              for(int k = 0; k <= 2; ++k) {
                if(j+1 == C && k != 0) break;
                int u = r-k;
                if(u < 0 || u > 2) continue;
                int nb = ( b + three[C] * u ) / 3;
                dp[q][k][nb] = ( dp[q][k][nb] + dp[p][l][b] ) % MOD;
              }
            }
          }
        }
      }
    }
    cout << dp[R*C%2][0][0] << endl;
  }
  return 0;
}