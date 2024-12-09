#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back

const int N = 1000;
const int inf =(1<<20);
class Edge{
public:
  int st,gt;
  int to;
};

class Rail{
public:
  int p,t;
};

class state{
public:
  int now;
  int time;
  bool operator<(const state & a)const{
    return time > a.time;
  }
  bool operator>(const state & a)const{
    return time < a.time;
  }
};


void go(int n,int s,int st,vector<Edge> *edge,bool isrev,int *cost){
  priority_queue<state> Q;
  priority_queue<state,vector<state>,greater<state> > RQ;
  if (!isrev)Q.push((state){s,st});
  else RQ.push((state){s,st});
  
  while(!Q.empty() || !RQ.empty()){
    state now;
    if (!isrev){
      now=Q.top(),Q.pop();
    }else{
      now = RQ.top(),RQ.pop();
    }
    if (cost[now.now] != inf)continue;
    //if (cost[now.now] == inf)
      cost[now.now] = now.time;
    /*
    else {
      if (isrev){
	
	if (now.time > cost[now.now])exit(1);
	else continue;
      }else {
	//	cout << now.now+1 <<" " <<now.time <<" " << cost[now.now] << endl;
	if (now.time < cost[now.now])exit(1);
	else continue;
      }
    }
    */
    rep(i,edge[now.now].size()){
      if (isrev){
	if (now.time < edge[now.now][i].st)continue;
	RQ.push((state){edge[now.now][i].to,edge[now.now][i].gt});
      }else{
	if (now.time > edge[now.now][i].st)continue;
	Q.push((state){ edge[now.now][i].to,edge[now.now][i].gt});
      }
    }
  }
}

int main(){
  int n;
  int line;
  int scost[N],tcost[N];
  vector<Edge> edge[N];
  vector<Edge> rev[N];
  vector<Rail > in[100]; 
  while(cin>>n>>line && n){
    rep(i,n)tcost[i]=inf,scost[i]=inf;
    rep(i,n)edge[i].clear(),rev[i].clear();
    rep(i,line)in[i].clear();
    int s,sh,sm,d,dh,dm;
    char dummy;
    cin>>s>>sh>>dummy>>sm>> d>>dh>>dummy>>dm;
    
    sh=sh*60+sm;
    dh=dh*60+dm;
    s--;
    d--;
    
    rep(i,line){
      int m;
      cin>>m;
      rep(j,m){
	int now,nh,nm;
	cin>>now>>nh>>dummy>>nm;
	now--;
	nh = nh*60+nm;
	in[i].push_back((Rail){now,nh});
      }
      
      rep(j,in[i].size()-1){
	edge[in[i][j  ].p].pb((Edge){in[i][j  ].t,in[i][j+1].t,in[i][j+1].p});
	rev[ in[i][j+1].p].pb((Edge){in[i][j+1].t,in[i][j  ].t,in[i][j  ].p});
      }
    }
    

    go(n,s,sh,edge,false,scost);
    go(n,d,dh,rev ,true ,tcost);

    /*
      cout << "begint"<<endl;
      cout << n << endl;
      cout <<"go"<<endl;
      rep(i,n)cout << scost[i] <<" ";cout << endl;
      cout << "rev " << endl;
      rep(i,n)cout << tcost[i] <<" ";cout << endl;
      cout << endl;
    */

    int ans = -1;
    if (scost[d] == inf){
      cout << "impossible"<<endl;
      continue;
    }
    if (s == d && sh <= dh)ans = 0;

    rep(i,line){
      int scan=-1,dcan=-1;
      rep(j,in[i].size()){
	if (scost[in[i][j].p] == inf)continue;
	if (scost[in[i][j].p] <= in[i][j].t){
	  scan=j;
	  break;
	}
      }
      
      for(int j=in[i].size()-1;j>=0 && j >scan;j--){
	if (tcost[in[i][j].p] == inf)continue;
	if (tcost[in[i][j].p] >= in[i][j].t){
	  dcan=j;
	  break;
	}
      }

      if (scan == -1 || dcan == -1)continue;

      ans = max(ans,in[i][dcan].t-in[i][scan].t);
    }
    
    if (ans == -1)cout << "impossible"<<endl;
    else cout << ans << endl;
    
  }
}