#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
#include <ctime>
#include <list>
#include <numeric>
using namespace std;
static const double EPS = 1e-6;
typedef long long ll;
typedef pair<int,int> PI;
#ifndef M_PI
const double M_PI=acos(-1);
#endif
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int((a).size()))
#define F first
#define S second
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};


int w,h;
int sx,sy;
map<PI,int> pos2num;
string in[100];

int cost[20][20];
bool vis[100][100][5];

bool canjump(int cx,int cy,int nx,int ny,int dir){
  rep(i,2){
    int nd=dir+(i?3:1)&3;
    for(int tx=cx,ty=cy;;
        tx+=dx[dir],ty+=dy[dir]){
      if(in[tx+dx[nd]][ty+dy[nd]]!='#')
        break;
      if(tx==nx && ty==ny) return true;
    }
  }
  return false;
}

void bfs(PI st){
  int sv=pos2num[st];
  rep(i,SZ(pos2num)) cost[sv][i] = -1;
  memset(vis,0,sizeof(vis));
  priority_queue<pair<PI,PI> > q;
  q.push(mp(mp(0,4),st));
  while(!q.empty()){
    int cc=-q.top().F.F;
    int dir=q.top().F.S;
    int cx=q.top().S.F;
    int cy=q.top().S.S;
    q.pop();
    if(vis[cx][cy][dir]) continue;
    vis[cx][cy][dir] = true;
    
    if((in[cx][cy]=='%' || in[cx][cy]=='*') &&
       cost[sv][pos2num[mp(cx,cy)]]==-1)
      cost[sv][pos2num[mp(cx,cy)]] = cc;

    rep(i,4){
      int nx=cx,ny=cy;
      bool jump = false;
      rep(j,2){
        nx+=dx[i],ny+=dy[i];
        if(in[nx][ny]=='#') break;
        if(in[nx][ny]=='^'){
          jump = true;
          continue;
        }
        int nextdir = 4;
        if(!jump && j==1) nextdir = i;
        q.push(mp(mp(-cc-j-1,nextdir),mp(nx,ny)));
      }
    }
    
    if(dir<4){
      rep(i,3){
        int nx=cx+(i+1)*dx[dir],ny=cy+(i+1)*dy[dir];
        if(in[nx][ny]=='#') break;
        if(in[nx][ny]=='^') continue;
        q.push(mp(mp(-cc-i-1,dir),mp(nx,ny)));
      }

      rep(i,5){
        int nx=cx+(i+1)*dx[dir],ny=cy+(i+1)*dy[dir];
        if(in[nx][ny]=='#') break;
        if(in[nx][ny]=='^') continue;
        if(canjump(cx,cy,nx,ny,dir))
          q.push(mp(mp(-cc-i-1,4),mp(nx,ny)));
        else break;
      }
    }
  }
}

int dp[17][1<<17];
int popcount[1<<17];

void solve(){
  pos2num.clear();
  int sv;
  int tv=1;
  rep(i,h){
    cin>>in[i];
    rep(j,w){
      if(in[i][j]=='%'){
        sx=i,sy=j;
        sv=0;
        pos2num[mp(i,j)] = 0;
      }
      if(in[i][j]=='*')
        pos2num[mp(i,j)] = tv++;
    }
  }

  int n=SZ(pos2num);

  FOR(it,pos2num)
    bfs(it->F);

  
  vector<PI> G[n];
  rep(i,n){
    //cout<<i<<" ver ";
    rep(j,n)if(cost[i][j]>0){
      //cout<<j<<" "<<cost[i][j]<<"  ";
      G[i].pb(mp(j,cost[i][j]));
    }
    //cout<<endl;
  }


  /*
  priority_queue<pair<int,PI> > q;
  memset(dp,0,sizeof(dp));
  q.push(mp(0,mp(sv,1<<sv)));
  */

  int ansv=0,ansc=0;

  int inf=1000000;
  rep(i,(1<<n))rep(j,n) dp[j][i] = inf;
  dp[0][1] = 0;



  for(int i = 0;i<(1<<n);++i)
    for(int cv=n-1;cv>=0;--cv){
      if(dp[cv][i]==inf) continue;
      if(cv==0 &&
         popcount[ansv] < popcount[i]){
        ansv = i;
        ansc = dp[cv][i];
      }
      FOR(it,G[cv]){
        if(it->F && ((i>>it->F)&1)) continue;
        int nst=i|(1<<it->F);
        int to=it->F;
        dp[to][nst] = min(dp[to][nst],
                          dp[cv][i]+it->S);
      }
    }

  

  /*
  while(!q.empty()){
    int cc=-q.top().F;
    int cv=q.top().S.F;
    int cst=q.top().S.S;
    q.pop();
    if(dp[cv][cst]) continue;
    dp[cv][cst] = true;
    if(cv==sv &&
       __builtin_popcount(ansv) < __builtin_popcount(cst)){
      ansv=cst;
      ansc=cc;
    }
    FOR(it,G[cv]){
      if(it->F != sv && (cst>>it->F)&1) continue;
      q.push(mp(-cc-it->S,mp(it->F,cst|1<<it->F)));
    }
  }
  */

  cout<<__builtin_popcount(ansv)-1<<' '<<ansc<<endl;
  //cout << rand() % 20 << " " << rand() % 500 << endl;
}

int main(){
  rep(i,(1<<17))popcount[i]=__builtin_popcount(i);
  while(cin>>h>>w,w)
    solve();
}