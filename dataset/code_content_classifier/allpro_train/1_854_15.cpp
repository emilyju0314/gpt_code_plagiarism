#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600

class UnionFind {
public:
  vector<int> par, rank; // parent(negative := its root and abs-value is its size), depth
  UnionFind(int sz) : par(sz, -1), rank(sz, 0){}
  int find(int x){
    if(par[x]<0) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y){
    x=find(x); y=find(y);
    if(x==y) return;  // already belong to same tree
    if(rank[x] < rank[y]){  // y becomes parent node
      par[y] += par[x];
      par[x] = y;
    } else {  // x becomes parent node
      par[x] += par[y];
      par[y] = x;
      if(rank[x]==rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int size(int x){ return -par[find(x)]; }
}; // END class UnionFind


int main(){
  int n,m;
  while(cin>>n>>m, n|m){
    vector<pair<int,pair<int,int>>> vec;
    rep(i,n)rep(j,m){
      int d;
      cin>>d;
      if(d>0) vec.pb(mp(d,mp(m,j)));
    }
    rep(i,m)rep(j,m-i-1){
      int d;
      cin>>d;
      if(d>0) vec.pb(mp(d,mp(i, i+j+1)));
    }

    UnionFind uf(m+1);
    sort(all(vec));
    int res = 0;
    for(auto p : vec){
      int a = p.se.fi, b = p.se.se;
      if(!uf.same(a,b)){
        res += p.fi;
        uf.unite(a,b);
      }
    }
    cout << res << endl;
  }

  return 0;
}