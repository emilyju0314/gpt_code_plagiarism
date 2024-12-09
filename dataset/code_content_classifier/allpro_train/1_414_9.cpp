#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

int getId(char c){
  if(c == 'S') return 30;
  if(c == 'T') return 31;
  if(isdigit(c)) return c - '0';
  if(isupper(c)) return c - 'A' + 10;
  if(islower(c)) return c - 'a' + 20;
  return -1;
}

int w, h;
char maze[1010][1010];
int posY[32], posX[32], pos[32];

int connected[32][32];

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
char dirchar[] = "DURL"; // "SNWE"

void bfs(int id){
  bool visited[1010][1010] = {};
  queue<pair<int,int> > que;

  que.push({posY[id], posX[id]});

  for(int j=0;que.size();j++){
    queue<pair<int,int> > que2;
    while(que.size()){
      auto p = que.front(); que.pop();
      
      int y = p.first;
      int x = p.second;
      
      if(y < 0 || h <= y || x < 0 || w <= x) continue;
      if(maze[y][x] == '#') continue;
      
      if(visited[y][x]) continue;
      visited[y][x] = true;

      if(getId(maze[y][x]) >= 0 && id != getId(maze[y][x])){
        connected[id][getId(maze[y][x])] = j;
        continue;
      }
      
      for(int i=0;i<4;i++){
        que2.push({y+dy[i], x+dx[i]});
      }
    }
    que = que2;
  }
}

int visited[32][1024][11] = {};

int main(){
  int score[11][11] = {};
  
  scanf("%d%d", &w, &h);
  
  for(int i=0;i<h;i++){
    scanf("%s", maze[i]);

    for(int j=0;j<w;j++){
      if(getId(maze[i][j]) >= 0){
        posY[getId(maze[i][j])] = i;
        posX[getId(maze[i][j])] = j;
        pos[getId(maze[i][j])] = 1;
      }
    }
  }

  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      scanf("%d", score[i]+j);

  for(int i=0;i<32;i++){
    if(pos[i]) bfs(i);
  }

  priority_queue<pair<pair<int, pair<int, int> >,pair<int,int> > > que;
  que.push({{0, {0, getId('S')}}, {0, 10}});
 
  while(que.size()){
    auto p = que.top();
    que.pop();

    int dist = p.first.first;
    int s = p.first.second.first;
    int now = p.first.second.second;
    int q = p.second.first;
    int prev = p.second.second;
    
    if(now == getId('T') && q == (1<<10)-1){
      printf("%d %d\n", -dist, s);
      return 0;
    }
    
    if(visited[now][q][prev]) continue;
    visited[now][q][prev] = true;
    
    for(int i=0;i<32;i++){
      if(!connected[now][i]) continue;
      int ndist = dist-connected[now][i];
      
      if(0 <= i && i < 10){
        if(!((q>>i)&1)) que.push({{ndist, {s+score[prev][i], i}}, {q | (1 << i), i}});
        que.push({{ndist, {s, i}}, {q, prev}});
      }
      if(10 <= i && i < 20 && !((q>>(i-10))&1))
        que.push({{ndist,{s, i}}, {q, prev}});
      if(20 <= i && i < 30 && ((q>>(i-20))&1))
        que.push({{ndist, {s, i}}, {q, prev}});
      if(30 <= i)
        que.push({{ndist, {s, i}},{q, prev}});
    }
  }

  puts("-1");
  
  return 0;
}



