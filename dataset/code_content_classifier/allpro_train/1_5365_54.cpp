#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

char F[20][16];
int sx, sy;
unordered_map<int, int> umap;

constexpr int to_num(int x, int y) {
  return x+y*16;
}

struct state {
  int x, y, used;
  state(int x, int y, int used) : x(x), y(y), used(used) {}
  bool operator == (state const& s) const { return x==s.x && y==s.y && used==s.used; }
};

struct state_hash
{
  size_t operator()(state const& s) const {
    return hash<int>()(to_num(s.x, s.y)) ^ hash<int>()(s.used);
  }
};


constexpr int dx[8] = {-1, 0, 1, 0,-1, 1, 1,-1};
constexpr int dy[8] = {0, -1, 0, 1,-1,-1, 1, 1};

constexpr bool inrange(int x, int y) {
  return 0<=x && x<16 && 0<=y && y<20;
}

bool is_used_xy(int used, int x, int y) {
  if(umap[to_num(x, y)] == -1) { return false; }
  return used >> umap[to_num(x, y)] & 1;
}

void debugger(int used, int cx, int cy) {
  rep(i, 20) {
    rep(j, 16) {
      if(cx == j && cy == i) {
        assert((F[i][j] == 'X' && is_used_xy(used, j, i)) || (F[i][j] == '.') || (F[i][j] == 'G'));
        cout << 'O';
      }
      else {
        cout << (is_used_xy(used, j, i) ? 'U' : F[i][j]);
      }
    }
    cout << endl;
  }
}

int dijkstra() {
  unordered_map<state, int, state_hash> dist;
  queue<state> q;
  q.emplace(sx, sy, 0);
  dist[state{sx, sy, 0}] = 0;
  while(!q.empty()) {
    int const x = q.front().x, y = q.front().y, used = q.front().used;
    int& cost = dist[state{x,y,used}];
    q.pop();
    if(x == -1 && y == 19) { return cost; }
    if(F[y][x] == 'G') { return cost; }
    rep(i, 8) {
      int nx = x+dx[i], ny = y+dy[i];
      int nused = used;
      if(!inrange(nx, ny)) { continue; }
      if(F[ny][nx] != 'X') { continue; }
      if(is_used_xy(used, nx, ny)) { continue; }
      bool ng = false;
      for(;;) {
        if(!inrange(nx, ny)) { ng = true; break; }
        if(F[ny][nx] != 'X') { break; }
        if(is_used_xy(used, nx, ny)) { break; }
        nused |= 1<<umap[to_num(nx, ny)];
        nx += dx[i], ny += dy[i];
      }
      if(ng && !(nx == -1 && ny == 19)) { continue; }
      if(inrange(nx, ny) && F[ny][nx] == 'A') { continue; }
      if(dist.find(state{nx, ny, nused})!=dist.end()) { continue; }
      dist[state{nx, ny, nused}] = cost+1;
      q.emplace(nx, ny, nused);
    }
  }
  return -1;
}

int main() {

  rep(i, 20) rep(j, 16) umap[to_num(j, i)] = -1;
  int bcnt = 0;
  rep(i, 19) rep(j, 15) {
    cin >> F[i][j];
    if(F[i][j] == 'O') {
      F[i][j] = '.';
      sx = j, sy = i;
    }
    if(F[i][j] == 'X') {
      umap[to_num(j,i)] = bcnt++;
    }
  }

  rep(i, 20) { F[i][15] = 'A'; }
  rep(i, 16) {
    if(i < 15 && F[18][i] != 'X') { F[18][i] = 'G'; }
    F[19][i] = 'G';
  }

  cout << dijkstra() << endl;

  return 0;
}