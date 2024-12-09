#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define _3_ 1

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

struct Point { int x,y; };

const int IINF = INT_MAX;
const char PATH = '$';

int h,w,s_size,c_size,bitIndex[12][12];
char c[12][12];
Point source[12],city[12],path[12];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int mini,blocks;
int bc[1<<9];

void dfs(int sp,int bitmask,int prev,int step,int depth){

  if( step+(c_size-bc[bitmask]) >= mini ) return;
  
  if( sp >= s_size ) return;

  if( bitmask == ((1<<c_size)-1) ) { mini = step; return; }

  bool next = 1;
  rep(dir,4){
    if( prev != -1 && ( prev + 2 ) % 4 == dir ) continue;
    int nx = path[sp].x + dx[dir], ny = path[sp].y + dy[dir];

    if( c[ny][nx] == 'P' || c[ny][nx] == '#' || c[ny][nx] == PATH ) continue;

    bool success = true;
    int cnt = 0;
    rep(i,4){
      int nx2 = nx + dx[i], ny2 = ny + dy[i];
      if( c[ny2][nx2] == PATH || c[ny2][nx2] == 'P' ) ++cnt;
    }
    if( cnt != 1 ) success = false;
    if( !success ) continue;
    
    Point pp = path[sp];
    char pc = c[ny][nx];
    int nbitmask = bitmask;
    bool fin = false;
    if( c[ny][nx] == '*' ) nbitmask |= (1<<bitIndex[ny][nx]), fin = true;

    path[sp] = (Point){nx,ny};
    c[ny][nx] = PATH;

    next = 0;
    dfs(sp,nbitmask,dir,step+1,depth+1);
    if( fin )dfs(sp+1,nbitmask,-1,step+1,0);

    path[sp] = pp;
    c[ny][nx] = pc;

    /*
     '*'?????£??\??????????????´????????????????????????????????????????????????????????????????????????????????????
     ????????§??¨???????????¨??????'*'????????????????????¨?????????
     */
    if( fin ) return; 

  }

  if( depth == 0 )  dfs(sp+1,bitmask,-1,step,0);  
} 

int compute(){
  mini = h*w-s_size - blocks;
  dfs(0,0,-1,0,0);
  return mini;
}



int main(){
  rep(i,(1<<9)) bc[i] = __builtin_popcount(i);
  while( scanf(" %d %d",&h,&w), h|w ){
    s_size = c_size = 0;
    blocks = 0;
    rep(i,h) rep(j,w) {
      scanf(" %c",&c[i][j]);
      if( c[i][j] == 'P' ) { source[s_size] = path[s_size] = (Point){j,i}; s_size++; }
      if( c[i][j] == '*' ) { city[c_size]   = (Point){j,i}; bitIndex[i][j] = c_size++; }
      if( c[i][j] == '#' ) ++blocks;
    }
    printf("%d\n",compute());
    //print_field(); puts("");
  }
  return 0;
}