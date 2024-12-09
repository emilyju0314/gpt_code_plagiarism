#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,h,w;

struct unionFind{
  unionFind(int n){
    init(n);
  }
  vector<int> par,size;
  int grup;
  void init(int n){
    grup=n;
    par.resize(n);
    size.resize(n);
    for(int i=0;i<n;i++){
      par[i]=i;
      size[i]=1;
    }
  }
  int find(int x){
    if(par[x] == x) return x;
    return par[x]=find(par[x]);
  }
  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(size[x]<size[y]) swap(x,y);
    par[y] = x;
    size[x]+=size[y];
    grup--;
  }
  bool same(int x,int y){return find(x) == find(y);}
  int getg(){return grup;}
};

map<int,vector<int> > xx;
map<int,vector<int> > yy;
int main(){
  cin>>n>>w>>h;
  bool f=0;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    if(x==1 || y==1 || x==w || y==h) f=1;
    xx[x].push_back(i);
    yy[y].push_back(i);
  }
  unionFind u(n);
  
  map<int,vector<int> >::iterator it;
  for(it=xx.begin();it!=xx.end();it++){
    vector<int> &vec = it->second;
    for(int i=0;i<(int)vec.size()-1;i++){
      u.unite(vec[i],vec[i+1]);
    }
  }
  for(it=yy.begin();it!=yy.end();it++){
    vector<int> &vec = it->second;
    for(int i=0;i<(int)vec.size()-1;i++){
      u.unite(vec[i],vec[i+1]);
    }
  }
  int cnt=u.getg();
  if(cnt==1) cout<<n-cnt<<endl;
  else cout<<n+cnt-1-f<<endl;     
  return 0;
}