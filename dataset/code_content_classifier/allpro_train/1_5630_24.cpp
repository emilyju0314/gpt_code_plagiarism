#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
using P = pair<int, int>;
int H, W;
vector<vector<int>> G;
vector<vector<int>> used;
void dfs(P v) {
  used[v.first][v.second] = true;
  if(v.first == H && v.second == W) return;

  if(G[v.first+1][v.second] && !used[v.first+1][v.second]) dfs(make_pair(v.first+1, v.second));
  if(G[v.first-1][v.second] && !used[v.first-1][v.second]) dfs(make_pair(v.first-1, v.second));
  if(G[v.first][v.second-1] && !used[v.first][v.second-1]) dfs(make_pair(v.first, v.second-1));
  if(G[v.first][v.second+1] && !used[v.first][v.second+1]) dfs(make_pair(v.first, v.second+1));
}
int main() {
  int h, w;
  cin >> h >> w;
  H = h; W = w;
  G.resize(h+2);
  rep(i, h+2) G[i].resize(w+2);
  used = G;
  rep(i, h) rep(j, w) {
    if((i+1) % 2 == 0 && (j+1) % 2 == 0) {
      char c;
      cin >> c;
    }
    else {
      char c;
      cin >> c;
      if(c == '#') G[i+1][j+1] = 0;
      else G[i+1][j+1] = c - '0';
    }
  }
  if(G[h][w] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  rep(i, h) rep(j, w) {
    if((i+1) % 2 == 0 && (j+1) % 2 == 0) continue;
    int x = (j+1) % 4;
    int y = (i+1) % 4;
    if(y == 1) {
      if(x == 1) {
        if(G[i+1][j+1] != 6) G[i+1][j+1] = 0;
      }
      else if(x == 2) {
        if(G[i+1][j+1] != 3) G[i+1][j+1] = 0;
      }
      else if(x == 3) {
        if(G[i+1][j+1] != 1) G[i+1][j+1] = 0;
      }
      else if(x == 0) {
        if(G[i+1][j+1] != 4) G[i+1][j+1] = 0;
      }
    }
    else if(y == 2) {
      if(G[i+1][j+1] != 2) G[i+1][j+1] = 0;
    }
    else if(y == 3) {
      if(x == 1) {
        if(G[i+1][j+1] != 1) G[i+1][j+1] = 0;
      }
      else if(x == 2) {
        if(G[i+1][j+1] != 3) G[i+1][j+1] = 0;
      }
      else if(x == 3) {
        if(G[i+1][j+1] != 6) G[i+1][j+1] = 0;
      }
      else if(x == 0) {
        if(G[i+1][j+1] != 4) G[i+1][j+1] = 0;
      }
    }
    else if( y == 0) {
      if(G[i+1][j+1] != 5) G[i+1][j+1] = 0;
    }
  }
  if(G[h][w] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  P init = make_pair(1, 1);
  dfs(init);
  if(used[h][w]) cout << "YES" << endl;
  else cout << "NO" << endl;
}

