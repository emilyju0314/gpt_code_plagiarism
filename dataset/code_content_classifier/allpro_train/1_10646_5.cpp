#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename Data, typename T>
struct ReRooting{
  struct Node{
    Int to,rev;
    Data data;
    Node(Int to,Int rev,Data data):to(to),rev(rev),data(data){}
  };
  
  using F1 = function<T(T,T)>;
  using F2 = function<T(T,Data)>;
  
  vector<vector<Node> > G;
  vector<vector<T> > ld,rd;
  vector<Int> lp,rp;
  
  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(Int n,const F1 f1,const F2 f2,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(Int u,Int v,Data d){
    G[u].emplace_back(v,(Int)G[v].size(),d);
    G[v].emplace_back(u,(Int)G[u].size()-1,d);
  }

  T dfs(Int v,Int p){
    while(lp[v]!=p&&lp[v]<(Int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));      
      lp[v]++;
    }
    while(rp[v]!=p&&rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(p<0) return rd[v][0];
    return f1(ld[v][p],rd[v][p+1]);    
  }

  vector<T> build(){
    for(Int i=0;i<(Int)G.size();i++){
      ld[i].assign((Int)G[i].size()+1,id);
      rd[i].assign((Int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(Int)G[i].size()-1;      
    }
    vector<T> res;
    for(Int i=0;i<(Int)G.size();i++){
      res.emplace_back(dfs(i,-1));
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n,bs;
  Int uku=0;
  while(cin>>n>>bs,n){
    using P = pair<Int, Int>;
    auto f1=[&](P a,P b){
              if(a.first!=b.first) return max(a,b);
              return P(a.first,a.second+b.second);
            };
    auto f2=[&](P a,Int b){
              if(a.second+b<=bs) return P(a.first,a.second+b);
              return P(a.first+1,b);
            };
    P ti(0,0);
    ReRooting<Int, P> G(n,f1,f2,ti);
    for(Int i=1;i<n;i++){
      Int p;
      cin>>p;
      p--;
      G.add_edge(p,i,1);
    }    
    auto ans=G.build();
    cout<<"Case "<<++uku<<":"<<endl;
    for(Int i=0;i<n;i++) cout<<f2(ans[i],1).first+1<<"\n";
    cout<<flush;
  }
  return 0;
}

