#include<iostream>
#include<algorithm>
#include<complex>
#include<queue>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back
#define mp         make_pair
#define ALL(C)     (C).begin(),(C).end()

const double eps = 1e-10;
#define EQ(a,b) (fabs((a)-(b))<eps)

typedef complex<double>P;

class Edge{
public:
  int to,prev,from,bit;
  int rot;
  double dist;
  bool turnedge;
  bool operator<(const Edge & a)const{
    if (to != a.to)return to < a.to;
    if (prev != a.prev)return prev < a.prev;
    if (from != from)return from < a.from;
    if (bit != a.bit)return bit < a.bit;
    if (dist != a.dist)return dist < a.dist;
    if (turnedge != a.turnedge)return turnedge < a.turnedge;
    return false;
  }
  bool operator==(const Edge &a)const{
    return to == a.to &&
      prev == a.prev&&
      from == from &&
      bit  == a.bit &&
      dist == a.dist&&
      turnedge == a.turnedge;
  }
};

class state{
public:
  int now,prev,bit;
  int rot;
  double dist;
  bool operator<(const state &a)const{
    if (rot != a.rot)return rot > a.rot;
    return dist > a.dist;
  }
};

double dot(P a,P b){
  return a.real()*b.real()+a.imag()*b.imag();
}

double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

bool is_parallel(P a1,P a2,P b1,P b2){
  return EQ( cross(a1-a2,b1-b2),0.0);
}

bool isp(P a,P b,P c){
  return abs(a-c)+abs(b-c)<abs(a-b)+eps;
}

P intersection_ll(P a1,P a2,P b1,P b2){
  P a=a2-a1,b=b2-b1;
  return a1+a*cross(b,b1-a1)/cross(b,a);
}

vector<Edge> edge[10];
void make_edge(P a,P b,P c,P d,
	       int ai,int bi,int ci,int di,
	       int n,P *in){
  if (is_parallel(a,b,c,d))return;
  rep(i,n){
    if (ai == i || bi == i)continue;
    if (isp(in[ai],in[bi],in[i]))return;
  }
  
  rep(i,n){
    if (ci == i ||di == i)continue;
    if (isp(in[ci],in[di],in[i]))return;
  }

  P tmp=intersection_ll(a,b,c,d);
  if (isp(a,b,tmp)||isp(c,d,tmp))return;

  rep(i,n){
    if (abs(in[i]-tmp)<eps)return;
  }

  if (abs(a-tmp) < abs(b-tmp))swap(a,b),swap(ai,bi);
  if (abs(d-tmp) < abs(c-tmp))swap(c,d),swap(ci,di);
  
  edge[bi].pb((Edge){di,ci,ai,(1<<bi)|(1<<ci)|(1<<di),1,abs(b-tmp)+abs(d-tmp),true});
  edge[ci].pb((Edge){ai,bi,di,(1<<ai)|(1<<bi)|(1<<ci),1,abs(c-tmp)+abs(a-tmp),true});
}

const int rotinf = 6;
const double distinf=(1<<21);
int     rot[10][11][(1<<11)];
double dist[10][11][(1<<11)];

pair<int,double> dijkstra(int ini,P *in,int n){
  rep(k,(1<<n)){
    rep(i,10){
      rep(j,11){
	rot[i][j][k]=rotinf;
	dist[i][j][k]=distinf;
      }
    }
  }
  
  priority_queue<state> Q;
  Q.push((state){ini,10,(1<<ini),0,0});
  rot[ini][10][(1<<ini)]=0;
  dist[ini][10][(1<<ini)]=0;
  while(!Q.empty()){
    state now = Q.top();Q.pop();
    
    if ( now.bit == ((1<<n)-1)){
      return mp(now.rot,now.dist);
    }

    if (now.rot >=5)continue;

    rep(i,edge[now.now].size()){
      if (edge[now.now][i].turnedge){
	
	if (now.prev != edge[now.now][i].from)continue;
	
	int nerot=now.rot+edge[now.now][i].rot;
	double nedist=now.dist+edge[now.now][i].dist;
	int nenow=edge[now.now][i].to,neprev=edge[now.now][i].prev;
	int nestate=(now.bit|edge[now.now][i].bit);
	if (rot[nenow][neprev][nestate] < nerot)continue;
	else if (rot[nenow][neprev][nestate]==nerot &&
		 dist[nenow][neprev][nestate] <nedist)continue;
	
	rot[nenow][neprev][nestate] =nerot;
	dist[nenow][neprev][nestate]=nedist;
	Q.push((state){
	  edge[now.now][i].to,
	    edge[now.now][i].prev,
	    (now.bit|edge[now.now][i].bit),
	    now.rot+edge[now.now][i].rot,
	    now.dist+edge[now.now][i].dist});
      }else {
	int cnt=0;
	
	if (now.prev == 10);
	else if (!isp(in[now.prev],in[edge[now.now][i].to],in[now.now]))cnt++;
	
	int nerot=now.rot+edge[now.now][i].rot+cnt;
	double nedist=now.dist+edge[now.now][i].dist;
	int nenow=edge[now.now][i].to,neprev=edge[now.now][i].prev;
	int nestate=(now.bit|edge[now.now][i].bit);
	
	if (rot[nenow][neprev][nestate] < nerot)continue;
	else if (rot[nenow][neprev][nestate]==nerot &&
		 dist[nenow][neprev][nestate] <nedist)continue;
	
	rot[nenow][neprev][nestate] =nerot;
	dist[nenow][neprev][nestate]=nedist;
	
	Q.push((state){
	  edge[now.now][i].to,
	    edge[now.now][i].prev,
	    (now.bit|edge[now.now][i].bit),
	    now.rot+edge[now.now][i].rot+cnt,
	    now.dist+edge[now.now][i].dist});
      }
    }
  }
  return mp(rotinf,distinf);
}

void solve(int n,P *in){
  rep(i,n){
    REP(j,i+1,n){
      int newstate=(1<<i)|(1<<j);
      double dist =abs(in[i]-in[j]);
      bool isok=true;
      rep(k,n){
	if (i == k||j==k)continue;
	if (isp(in[i],in[j],in[k])){
	  isok=false;
	  break;
	}
      }
      if (!isok)continue;
      edge[i].pb((Edge){j,i,-1,newstate,0,dist,false});
      edge[j].pb((Edge){i,j,-1,newstate,0,dist,false});
    }
  }

  rep(i,n){
    REP(j,i+1,n){
      if (i == j)continue;
      rep(k,n){
    	if (i == k || j == k)continue;
	REP(l,k+1,n){
	  if (i == l || j == l || k == l)continue;
	  make_edge(in[i],in[j],in[k],in[l],
		    i,j,k,l,
		    n,in);
	}
      }
    }
  }

  rep(i,n){
    sort(ALL(edge[i]));
    edge[i].erase(unique(ALL(edge[i])),edge[i].end());
  }

  pair<int,double> ans=mp(rotinf,distinf);
  rep(i,n){
    pair<int,double> tmp = dijkstra(i,in,n);
    ans=min(ans,tmp);
  }
  printf("%d %.8lf\n",ans.first,ans.second);
}

int main(){
  int n;
  while(cin>>n && n){
    rep(i,n)edge[i].clear();
    P in[n];
    rep(i,n){
      double x,y;
      cin>>x>>y;
      in[i]=P(x,y);
    }
    solve(n,in);
  }
}