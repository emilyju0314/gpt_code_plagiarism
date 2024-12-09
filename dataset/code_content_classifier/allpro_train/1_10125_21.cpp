#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define ITER(c) __typeof((c).begin())
#define PB(e) push_back(e)
#define FOREACH(i, c) for(ITER(c) i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define PARITY(n) ((n) & 1)

typedef long long ll;
typedef pair<ll, ll> P;

int H, W;
int field[52][52];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int sdx[4][2] = {
  {0, 1},
  {-1, -1},
  {0, 1},
  {2, 2},
};

int sdy[4][2] = {
  {2, 2},
  {0, 1},
  {-1, -1},
  {0, 1},
};

struct state{
  // cost, kingのupper-leftの位置、spaceの方角
  int cost, r, c, d;
  state(){}
  state(int _cost, int _r, int _c, int _d) : cost(_cost), r(_r), c(_c), d(_d){}
};

bool operator<(const state &s1, const state &s2) {return s1.cost > s2.cost;}

int bfs(int r1, int c1, int r2, int c2){
  int dist[52][52];  
  memset(dist, -1, sizeof(dist));
  dist[r1][c1] = 0;
  queue<P> que;
  que.push(P(r1, c1));
  while(!que.empty()){
    P p = que.front(); que.pop();
    int r = p.first;
    int c = p.second;
    if(r == r2 && c == c2) return dist[r2][c2];
    REP(i, 4){
      int nr = r + dx[i];
      int nc = c + dy[i];
      if(field[nr][nc] && dist[nr][nc] == -1) {
        dist[nr][nc] = dist[r][c] + 1;
        que.push(P(nr, nc));
      }
    }
  }
  return -1;
}

vector<P> get_space(int r, int c, int i){
  vector<P> ans;
  // cout << r << " " << c << endl;
  ans.PB(P(r + sdx[i][0], c + sdy[i][0]));
  ans.PB(P(r + sdx[i][1], c + sdy[i][1]));  
  return ans;
}

int calc_dist2(const vector<P> &src, const vector<P> &dst){
  int ans = -1;
  
  int d0 = bfs(src[0].first, src[0].second, dst[0].first, dst[0].second);
  int d1 = bfs(src[1].first, src[1].second, dst[1].first, dst[1].second);
  if(d0 >= 0 && d1 >= 0) ans = d0 + d1;
  
  int d2 = bfs(src[1].first, src[1].second, dst[0].first, dst[0].second);
  int d3 = bfs(src[0].first, src[0].second, dst[1].first, dst[1].second);
  if(d2 >= 0 && d3 >= 0 && (ans == -1 || ans > d2 + d3)) ans = d2 + d3;
  return ans;
}

bool ok(vector<P> &vp){
  return field[vp[0].first][vp[0].second] >0 && field[vp[1].first][vp[1].second] > 0;
}

void init(P king, vector<P> space, priority_queue<state> &que, int dist[52][52][4]){
  assert(space.size() == 2);
  int r = king.first;
  int c = king.second;
  REP(i, 2)REP(j, 2) field[r+i][c+j] = 0;
  REP(i, 4){
    vector<P> vp = get_space(r, c, i);
    if(!ok(vp)) continue;
    int cost = calc_dist2(space, vp);
    if(cost >= 0){
      dist[r][c][i] = cost;
      que.push(state(cost, r, c, i));
    }
  }
  REP(i, 2)REP(j, 2) field[r+i][c+j] = 1;
}


int calc_cost(int r, int c, int d, int i){
  if(d == i) return 0;
  vector<P> src = get_space(r, c, d);
  vector<P> dst = get_space(r, c, i);
  
  if(ok(src) && ok(dst)){
    // cout << src[0].first << " " << src[0].second  << endl;
    // cout << src[1].first << " " << src[1].second  << endl;    
    return calc_dist2(src, dst);
  }else{
    return -1;
  }
}

int dijkstra(P king, vector<P> space){
  if(king == P(1, 1)) return 0;
  
  int dist[52][52][4];
  memset(dist, -1, sizeof(dist));
  
  priority_queue<state> que;
  init(king, space, que, dist);

  while(!que.empty()){

    
  
    state s = que.top(); que.pop();
    // REP(i, H + 2){
    //   REP(j, W + 2){
    //     cout << field[i][j];
    //   }
    //   cout << endl;
    // }
    
    if(s.r == 1 && s.c == 1) return s.cost;
    
    if(s.cost > dist[s.r][s.c][s.d]) continue;
    REP(i, 2)REP(j, 2) field[s.r+i][s.c+j] = 0;
    
    REP(i, 4){
      int r2 = s.r + dx[i];
      int c2 = s.c + dy[i];
      int cost = calc_cost(s.r, s.c, s.d, i) + 1;
      int &D = dist[r2][c2][(i+2)%4];
      if(cost > 0 && (D == -1 || D > s.cost + cost)){
        D = s.cost + cost;
        que.push(state(D, r2, c2, (i+2)%4));
      }
    }
    
    REP(i, 2)REP(j, 2) field[s.r+i][s.c+j] = 1;
  }
  return -1;
}

int main(){
  char c;
  while(cin >> H >> W && H && W){
    memset(field, 0, sizeof(field));
    
    P king;
    vector<P> space;
    
    REP(i, H) REP(j, W){
      cin >> c;
      if(c == '.')  space.PB(P(i+1, j+1));
      if(c == 'X')  king = P(i + 1, j + 1);
      field[i+1][j+1] = c == '*' ? 0 : 1;
    }
    king.first--;
    king.second--;
    cout << dijkstra(king, space)<< endl;
  }
  return 0;
}