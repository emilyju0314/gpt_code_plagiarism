#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
#define mod 1000000007

struct state{
  int d;
  P p;
};
bool operator<(const state& a,const state& b){
  return a.d > b.d;
}

int w,h,n;
int x[101],y[101];
int dist[105][1001];

int main(){
  scanf("%d%d%d",&w,&h,&n);
  rep(i,n)scanf("%d%d",x+i,y+i);
  priority_queue<state> que;
  rep(i,n+1)rep(j,w+h+1)dist[i][j]=INF;
  que.push((state){0,P(n,0)});
  int res=INF;
  while(que.size()){
    P p=que.top().p;
    int d=que.top().d;
    que.pop();
    if(dist[p.fi][p.se]!=INF)continue;
    dist[p.fi][p.se]=d;
    if(p.fi==n){ // start
      rep(i,n){
        int md=abs(x[i]-1)+abs(y[i]-1);
        que.push((state){d+md,P(i,md)});
      }
    }else{ // light
      rep(i,n){
        if(x[i]<x[p.fi]&&y[i]<y[p.fi])continue;
        if(i==p.fi)continue;
        int md=abs(x[i]-x[p.fi])+abs(y[i]-y[p.fi]);
        if(md<=p.se+1){
          que.push((state){d,P(i,0)});
        }else{
          md-=p.se+1;
          que.push((state){d+md,P(i,md)});
        }
      }
      { // -> end
        int md=abs(x[p.fi]-w)+abs(y[p.fi]-h);
        if(md<=p.se){
          minch(res,d);
        }else{
          md-=p.se;
          minch(res,d+md);
        }
      }
    }
  }
  cout<<res<<endl;
  return 0;
}

