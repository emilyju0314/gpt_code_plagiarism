#include<bits/stdc++.h>
#define N 10005
#define rank raljfds
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P2;
 
class UF{
public:
  int V;
  vector<int> par, rank, mil;
  UF(){}
  UF(int V):V(V),par(V),rank(V,0),mil(V,-1){for(int i=0;i<V;i++) par[i]=i;}
 
  int find(int x){
    assert(x<V);
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
  }
   
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    
    if(mil[x]!=-1) mil[y]=mil[x];
    if(mil[y]!=-1) mil[x]=mil[y];
    
    if(rank[x]<rank[y]){
      par[x]=y;
    }
    else{
      par[y]=x;
      if(rank[x]<rank[y]) rank[x]++;
    }
  }
   
  bool same(int x,int y){return find(x)==find(y);}
   
  void add_mil(int num){
    mil[num]=num;
  }
   
  int get_mil(int x){
    return mil[find(x)];
  }
};
 
int n,t,k;
vector<P2> G;
UF uf;
 
int solve(){
   
  uf=UF(n);
   
  int milnum;
   
  for(int i=0;i<t;i++){
 
    cin>>milnum;
     
    uf.add_mil(milnum-1);
  }
   
  vector<int> ans;
   
  for(int idx=0;idx<G.size();idx++){
     
    int cost=G[idx].first;
    int A=G[idx].second.first;
    int B=G[idx].second.second;
    
    if(!(uf.get_mil(A)!=-1&&uf.get_mil(B)!=-1)) uf.unite(A,B);
    else ans.push_back(cost);
    
  }
 
  sort(ans.begin(),ans.end());
 
  int res=0;

  for(int i=0;i<k;i++) res+=ans[i];
   
  return res;
}
 
int main(){
 
  int T=1;
   
  while(1){
 
    cin>>n>>t>>k;
    if(!n&&!t&&!k) break;
 
    int a,b,cost;
     
    for(int i=0;i<n-1;i++){
       
      cin>>a>>b>>cost;
       
      a--, b--;
 
      G.push_back(P2(cost,P(a,b)));
    }
     
    sort(G.begin(),G.end(),greater<P2>());
     
    cout<<"Case "<<T<<": ";
     
    cout<<solve()<<endl;
 
    G.clear();
     
    T++;
  }
   
  return 0;
}