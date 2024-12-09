#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T,bool isMin>
struct NonmonotonicConvexHullTrick {
  using number = double;
  static constexpr number INF = numeric_limits<T>::max();
  struct Line {
    T m,b,val;
    number x;
    bool q;
    Line(T m=0,T b=0):m(m),b(b),val(0),x(-INF),q(false){}

    T eval(T x) const{return m*x+b;}
    bool parallel(const Line &l) const{return m==l.m;}
    number intersect(const Line &l) const{
      return parallel(l)?number(INF):number(l.b-b)/number(m-l.m);
    }
    bool operator<(const Line &l) const{
      if(l.q) return x<l.val;
      return m<l.m;
    }
  };

  set<Line> hull;
  using iter = typename set<Line>::iterator;

  bool cPrev(iter it){return it!=hull.begin();}
  bool cNext(iter it){return it!=hull.end()&&next(it)!=hull.end();}

  bool bad(const Line &l1,const Line &l2,const Line &l3){
    return l1.intersect(l3) <= l1.intersect(l2);
  }
  bool bad(iter it){
    return cPrev(it)&&cNext(it)&&bad(*prev(it),*it,*next(it));
  }

  iter update(iter it){
    if(!cPrev(it)) return it;
    number x=it->intersect(*prev(it));
    Line tmp(*it);
    tmp.x=x;
    it=hull.erase(it);
    return hull.insert(it,tmp);
  }

  void addLine(T m,T b){
    if(isMin) m=-m,b=-b;
    Line l(m,b);
    iter it=hull.lower_bound(l);
    if(it!=hull.end()&&l.parallel(*it)){
      if(it->b<b) it=hull.erase(it);
      else return;
    }
    it=hull.insert(it,l);
    if(bad(it)){
      hull.erase(it);
      return;
    }
    while(cPrev(it)&&bad(prev(it))) hull.erase(prev(it));
    while(cNext(it)&&bad(next(it))) hull.erase(next(it));

    it=update(it);
    if(cPrev(it)) update(prev(it));
    if(cNext(it)) update(next(it));
  }

  bool empty() const{
    return hull.empty();
  }

  T query(T x){
    assert(!empty());
    Line q;
    q.val=x;q.q=1;
    iter it=--hull.lower_bound(q);
    if(isMin) return -(it->eval(x));
    return it->eval(x);
  }
} ;

//INSERT ABOVE HERE
signed main(){
  Int n,m,q;
  cin>>n>>m>>q;

  vector<Int> ds(n);
  for(Int i=0;i<n;i++) cin>>ds[i];
  for(Int i=0;i<n;i++) ds.emplace_back(Int(ds[i]));
  for(Int i=0;i<n;i++) ds.emplace_back(Int(ds[i]));

  vector<Int> sm(n*3+1,0);
  for(Int i=0;i<n*3;i++) sm[i+1]=sm[i]+ds[i];

  vector<char> cs(m);
  vector<Int> bs(m),ts(m);
  for(Int i=0;i<m;i++) cin>>cs[i]>>bs[i]>>ts[i],bs[i]--;

  vector< vector<Int> > G(n*3);
  vector<Int> xs(q),ys(q);
  for(Int i=0;i<q;i++){
    cin>>xs[i]>>ys[i];
    xs[i]--,ys[i]--;
    xs[i]+=n,ys[i]+=n;
     G[xs[i]].emplace_back(i);
  }

  const Int INF = 1e18;
  vector<Int> R(n*3,INF),L(n*3,INF);
  Int exR=0,exL=0;
  for(Int i=0;i<m;i++){
    if(cs[i]=='R'){
      exR=1;
      chmin(R[bs[i]+n*0],ts[i]);
      chmin(R[bs[i]+n*1],ts[i]);
      chmin(R[bs[i]+n*2],ts[i]);
    }
    if(cs[i]=='L'){
      exL=1;
      chmin(L[bs[i]+n*0],ts[i]);
      chmin(L[bs[i]+n*1],ts[i]);
      chmin(L[bs[i]+n*2],ts[i]);
    }
  }

  vector<Int> ans(q,INF);
  // use R
  if(exR){
    NonmonotonicConvexHullTrick<Int, true> cht;
    for(Int x=0;x<n*2;x++){
      if(R[x]!=INF) cht.addLine(R[x],-R[x]*sm[x]);
      for(Int i:G[x]){
        Int y=ys[i];
        if(x>y) y+=n;
        chmin(ans[i],cht.query(sm[y]));
      }
    }
  }
  // use L
  if(exL){
    NonmonotonicConvexHullTrick<Int, true> cht;
    for(Int x=n*3-1;x>=n;x--){
      if(L[x]!=INF) cht.addLine(-L[x],L[x]*sm[x]);
      for(Int i:G[x]){
        Int y=ys[i];
        if(x<y) y-=n;
        chmin(ans[i],cht.query(sm[y]));
      }
    }
  }

  for(Int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}

