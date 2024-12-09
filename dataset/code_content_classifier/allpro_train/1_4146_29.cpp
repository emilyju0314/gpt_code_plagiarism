#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)

bool in_range(int i, int j) {
  return 0 <= i && i < 4 && 0 <= j && j < 4; 
}

vector<int> x(4), y(4);

bool G[4][4];

int rec(int i, int j) {
  
  int ni = i, nj = j + 1;
    
  if(nj == 4) {
    ni ++;
    nj = 0;
  }
  
  if(ni == 4) return G[i][j];

  if(G[i][j]) return rec(ni, nj);
  
  int ret = 0;

  G[i][j] = 1;
  
  rep(k, 4) {
    int pi = i + y[k], pj = j + x[k];
    if(!in_range(pi, pj)) continue;
    if(G[pi][pj]) continue; // iranai ?
    G[pi][pj] = 1;
    ret += rec(ni, nj);
    G[pi][pj] = 0;
  }
  
  G[i][j] = 0;
  
  return ret;
}

int main() {

  while(1) {
    rep(i, 4) {
      cin >> x[i] >> y[i];
      if(cin.eof()) exit(0);
    }
    
    rep(i, 4) rep(j, 4) G[i][j] = 0;
    cout << rec(0, 0) << endl;
  }
  
  return 0;
}