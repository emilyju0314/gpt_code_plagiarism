#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T>
struct Kruskal{
  
  struct edge{
    int from,to;
    T cost;
    int used;
    edge(){}
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  int n;
  vector<int> p,r;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(int n):n(n){}

  void init(int n){
    r.assign(n,1);
    p.resize(n);
    iota(p.begin(),p.end(),0);
  }
  
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(int u,int v,T c){
    edges.emplace_back(u,v,c);
  }
  
  T build(){
    sort(edges.begin(),edges.end());
    init(n);
    T res=0;
    for(auto &e:edges){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};

struct Point{
  int x,y,idx,idy;
  Point(){}
  Point(int x,int y,int idx):x(x),y(y),idx(idx),idy(-1){}
  bool operator<(const Point &a)const{
    if(y!=a.y) return y>a.y;
    return x<a.x;
  }
};

const int MAX = 114514;
Point ps[MAX],bk[MAX];
int xs[MAX],ys[MAX];

void chk(int idx,int j){
  if(idx<0) return;
  int &idy=ps[j].idy;
  if(idy<0||xs[idy]<xs[idx]) idy=idx;
}

void upd(int &idx,int i){
  if(idx<0||xs[idx]<ps[i].x) idx=ps[i].idx;
}

void dfs(int l,int r){
  if(l+1==r) return;
  int m=(l+r)>>1;
  dfs(l,m);dfs(m,r);
  
  {
    int i=l,j=m,idx=-1;
    while(i<m||j<r){
      if(i==m||j==r){
        if(i==m) chk(idx,j++);
        if(j==r) upd(idx,i++);
        continue;
      }      
      ps[i].x+ps[i].y<=ps[j].x+ps[j].y?upd(idx,i++):chk(idx,j++);
    }
  }

  {
    int i=l,j=m,k=l;
    for(int i=l;i<r;i++) bk[i]=ps[i];
    while(i<m||j<r){
      if(i==m||j==r) ps[k++]=bk[(j==r?i:j)++];
      else ps[k++]=bk[(bk[i].x+bk[i].y<=bk[j].x+bk[j].y?i:j)++];
    }
  }
}

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  using P = pair<int, int>;
  vector<P> es;

  for(int b=0;b<4;b++){
    for(int i=0;i<n;i++){
      if(b&1) swap(xs[i],ys[i]);
      if(b&2) xs[i]*=-1;
      ps[i]=Point(xs[i],ys[i],i);
    }
    
    sort(ps,ps+n);
    dfs(0,n);

    for(int i=0;i<n;i++){   
      if(b&1) swap(xs[i],ys[i]);
      if(b&2) xs[i]*=-1;
      
      if(ps[i].idy<0) continue;
      int u=ps[i].idx,v=ps[i].idy;
      if(u>v) swap(u,v);
      es.emplace_back(u,v);      
    }
  }
  
  Kruskal<Int> ks(n);
  for(P e:es){
    int u,v;
    tie(u,v)=e;
    int c=max(abs(xs[u]-xs[v]),abs(ys[u]-ys[v]));
    ks.add_edge(u,v,c);
  }

  cout<<ks.build()<<endl;
  return 0;
}


