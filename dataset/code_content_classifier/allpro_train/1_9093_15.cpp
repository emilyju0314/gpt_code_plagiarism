#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct LinkCutTreeBase{
  static array<Node, LIM> pool;
  size_t ptr;

  LinkCutTreeBase():ptr(0){}

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(Node v){
    return &(pool[ptr++]=v);
  }

  virtual void toggle(Node *t) = 0;
  virtual void eval(Node *t) = 0;
  virtual void pushup(Node *t) = 0;

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    x->sz-=t->sz;
    t->sz+=x->sz;
    if((x->l=t->r)) t->r->p=x,x->sz+=x->l->sz;
    t->r=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    x->sz-=t->sz;
    t->sz+=x->sz;
    if((x->r=t->l)) t->l->p=x,x->sz+=x->r->sz;
    t->l=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  bool is_root(Node *t){
    return !t->p||(t->p->l!=t&&t->p->r!=t);
  }

  void splay(Node *t){
    eval(t);
    while(!is_root(t)){
      Node *q=t->p;
      if(is_root(q)){
        eval(q);eval(t);
        if(q->l==t) rotR(t);
        else rotL(t);
      }else{
        auto *r=q->p;
        eval(r);eval(q);eval(t);
        if(r->l==q){
          if(q->l==t) rotR(q),rotR(t);
          else rotL(t),rotR(t);
        }else{
          if(q->r==t) rotL(q),rotL(t);
          else rotR(t),rotL(t);
        }
      }
    }
  }

  Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      c->r=rp;
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }

  void link(Node *par,Node *c){
    expose(c);
    expose(par);
    c->p=par;
    par->r=c;
    par->sz+=c->sz;
    pushup(par);
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    pushup(c);
    par->p=nullptr;
    c->sz-=par->sz;
  }

  void evert(Node *t){
    expose(t);
    toggle(t);
    eval(t);
  }

  Node *root(Node *t){
    expose(t);
    while(t->l) t=t->l;
    splay(t);
    return t;
  }

  bool is_connected(Node *a,Node *b){
    return root(a)==root(b);
  }

  Node *lca(Node *a,Node *b){
    expose(a);
    return expose(b);
  }
};
template<typename Node, size_t LIM>
array<Node, LIM> LinkCutTreeBase<Node, LIM>::pool;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp,typename Ep>
struct NodeBase{
  using T = Tp;
  using E = Ep;
  NodeBase *l,*r,*p;
  size_t sz;// tree size (only for root)
  int idx;
  bool rev;
  T val,dat;
  E laz;
  NodeBase():sz(1){}
  NodeBase(int idx,T val,E laz):
    sz(1),idx(idx),rev(0),val(val),dat(val),laz(laz){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct Path : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using T = typename Node::T;
  using E = typename Node::E;

  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  using S = function<T(T)>;
  F f;
  G g;
  H h;
  S flip;
  T ti;
  E ei;

  Path(F f,G g,H h,T ti,E ei):
    super(),f(f),g(g),h(h),ti(ti),ei(ei){
    flip=[](T a){return a;};
  }

  Path(F f,G g,H h,S flip,T ti,E ei):
    super(),f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}

  Node* create(int idx,T val){
    return super::create(Node(idx,val,ei));
  }

  void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
  }

  void toggle(Node *t){
    swap(t->l,t->r);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  void eval(Node *t){
    if(t->laz!=ei){
      if(t->l) propagate(t->l,t->laz);
      if(t->r) propagate(t->r,t->laz);
      t->laz=ei;
    }
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
  }

  void pushup(Node *t){
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
  }

  using super::expose;

  T query(Node *t){
    expose(t);
    return t->dat;
  }

  void update(Node *t,E v){
    expose(t);
    propagate(t,v);
    eval(t);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../mod/mint.cpp"
#include "../linearalgebra/squarematrix.cpp"
#undef call_from_test

//INSERT ABOVE HERE

signed YUKI_650(){
  using M = Mint<int>;
  using SM = SquareMatrix<M, 2>;
  using SM2 = pair<SM, SM>;
  using Node = NodeBase<SM2, SM2>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](SM2 x,SM2 y){return SM2(x.first*y.first,y.second*x.second);};
  auto g=[](SM2 x,SM2 y){(void)x;return y;};
  auto flip=[](SM2 x){swap(x.first,x.second);return x;};

  SM ti=SM::mul_identity();
  SM ei=SM::mul_identity();
  SM2 ti2(ti,ti),ei2(ei,ei);
  LCT lct(f,g,g,flip,ti2,ei2);

  int n;
  cin>>n;
  vector< vector<int> > G(n);
  vector<int> X,Y;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    X.emplace_back(a);
    Y.emplace_back(b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<LCT::Node*> vs(n*2-1);
  for(int i=0;i<(int)vs.size();i++)
    vs[i]=lct.create(i,ti2);

  vector< map<int, int> > rev(n);
  int idx=n;
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      if(~p){
        lct.link(vs[p],vs[idx]);
        lct.link(vs[idx],vs[v]);
        rev[p][v]=rev[v][p]=idx++;
      }
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    char c;
    cin>>c;
    if(c=='x'){
      int v,a,b,c,d;
      cin>>v>>a>>b>>c>>d;
      int z=rev[X[v]][Y[v]];
      lct.expose(vs[z]);
      SM sm;
      sm[0][0]=a;sm[0][1]=b;
      sm[1][0]=c;sm[1][1]=d;
      vs[z]->val=SM2(sm,sm);
      lct.pushup(vs[z]);
    }
    if(c=='g'){
      int x,y;
      cin>>x>>y;
      lct.evert(vs[x]);
      SM ans=lct.query(vs[y]).first;
      cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
      cout<<ans[1][0]<<" "<<ans[1][1]<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://yukicoder.me/problems/no/650
*/

signed SPOJ_DYNACON1(){
  int n,m;
  cin>>n>>m;
  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0,0);
  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,0);

  for(int i=0;i<m;i++){
    string s;
    int a,b;
    cin>>s>>a>>b;
    a--;b--;
    if(s=="add"s){
      lct.evert(vs[b]);
      lct.link(vs[a],vs[b]);
    }
    if(s=="rem"s){
      auto v=lct.lca(vs[a],vs[b])==vs[a]?vs[b]:vs[a];
      lct.cut(v);
    }
    if(s=="conn"s)
      cout<<(lct.is_connected(vs[a],vs[b])?"YES\n":"NO\n");
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://www.spoj.com/problems/DYNACON1/
*/

signed main(){
  //YUKI_650();
  //SPOJ_DYNACON1();
  return 0;
}
#endif

#undef call_from_test

signed main(){
  using ll = long long;

  int n;
  cin>>n;

  using P = pair<ll, ll>;
  using Node = NodeBase<P, ll>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,int b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  LCT lct(f,g,h,P(0,0),0);

  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,P(0,1));
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lct.link(vs[i],vs[c]);
    }
  }

  int q;
  cin>>q;
  ll sum=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      lct.update(vs[a],b);
      sum+=b;
    }
    if(t==1){
      int a;
      cin>>a;
      cout<<lct.query(vs[a]).first-sum<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

