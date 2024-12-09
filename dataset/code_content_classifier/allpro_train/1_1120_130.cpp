#include<iostream>
#include<queue>

using namespace std;

struct S{
  int x,p,v;
  double t;
  bool operator<(S s)const{
    return t>s.t;
  }
};

int main(){
  for(int n,m;cin>>n>>m,n;){
    int s,g;
    cin>>s>>g;
    int d[31][31];
    int l[31][31]={};
    for(int i=0;i<m;i++){
      int x,y,di,c;
      cin>>x>>y>>di>>c;
      d[x][y]=d[y][x]=di;
      l[x][y]=l[y][x]=c;
    }
    bool p[31][31][31]={};
    priority_queue<S> que;
    que.push({s,0,0,0});
    while(!que.empty()){
      S cs=que.top();
      if(cs.x==g&&cs.v==1)break;
      que.pop();
      if(p[cs.x][cs.p][cs.v]++)continue;
      for(int i=0;i<=n;i++){
	if(cs.p==i)continue;
	for(int j=-1;j<=1;j++){
	  int nv=cs.v+j;
	  if(nv<=0||l[cs.x][i]<nv)continue;
	  que.push({i,cs.x,nv,cs.t+d[cs.x][i]*1./nv});
	}
      }
    }
    if(que.empty()){
      cout<<"unreachable"<<endl;
    }else{
      cout<<fixed<<que.top().t<<endl;
    }
  }
}