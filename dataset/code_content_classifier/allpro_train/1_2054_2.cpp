#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <functional>
#include <cctype>
#include <locale>
#include <numeric>
#include <array>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//2-dim:vector<vector<Type>> vv(n, vector<Type>(m, d));
//3-dim:vector<vector<vector<Type>>> vvv(n, vector<vector<Type>>(m, vector<Type>(l, d)));
template<typename T,typename E>
struct LazySegmentTree{
    using F = function<T(T,T)>;
    using G = function<T(T,E)>;
    using H = function<E(E,E)>;
    int sz_,height;
    F f; G g; H h;
    T identity_T;
    E identity_E;
    vector<T> node;
    vector<E> lazy;
    LazySegmentTree(F f_,G g_,H h_,T identity_T_,E identity_E_):
        f(f_),g(g_),h(h_),identity_T(identity_T_),identity_E(identity_E_){}
    void init(int n_){
        sz_=1; height=0;
        while(sz_<n_){ sz_<<=1; height++; }
        node.assign(2*sz_,identity_T);
        lazy.assign(2*sz_,identity_E);
    }
    void build(vector<T> &v){
        int n_=(int)v.size();
        init(n_);
        for(int i_=0;i_<sz_;i_++){
            node[sz_+i_]=v[i_];
        }
        for(int i_=sz_-1;i_;i_--){
            node[i_]=f(node[(i_<<1)|0],node[(i_<<1)|1]);
        }
    }
    inline T reflect(int k_){
        return lazy[k_]==identity_E ? node[k_] :g(node[k_],lazy[k_]);
    }
    inline void thrust(int k_){
        for(int i_=height;i_;i_--) eval(k_>>i_);
    }
    inline void recalc(int k_){
        while(k_>>=1){
            node[k_]=f(reflect((k_<<1)|0),reflect((k_<<1)|1));
        }
    }
    inline void eval(int k_){
        if(lazy[k_]==identity_E) return;
        lazy[(k_<<1)|0]=h(lazy[(k_<<1)|0],lazy[k_]);
        lazy[(k_<<1)|1]=h(lazy[(k_<<1)|1],lazy[k_]);
        node[k_]=reflect(k_);
        lazy[k_]=identity_E;
    }
    void update(int a,int b,E x_){
        thrust(a+=sz_);
        thrust(b+=sz_-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1){ lazy[l]=h(lazy[l],x_); ++l; }
            if(r&1){ --r; lazy[r]=h(lazy[r],x_); }
        }
        recalc(a);
        recalc(b);
    }
    void set_val(int a,T x){
      thrust(a+=sz_);
      node[a]=x; lazy[a]=identity_E;
      recalc(a);
    }
    T query(int a,int b){
      //assert(0<=a&&a<=b&&b<=sz_);
      thrust(a+=sz_);
      thrust(b+=sz_-1);
      T vl=identity_T,vr=identity_T;
      for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
        if(l&1) vl=f(vl,reflect(l++));
        if(r&1) vr=f(reflect(--r),vr);
      }
      return f(vl,vr);
    }
};
signed main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n,Q; cin >> n >> Q;
    struct S{
        ll zero,one,ans;
    };
    vector<S> v(n);
    rep(i,n){
        ll x; cin >> x;
        v[i] = {1-x,x,0};
    }
    auto f=[](S a,S b){
        return (S){a.zero+b.zero, a.one+b.one, a.ans+b.ans+a.one*b.zero};
    };
    auto g=[](S a,bool b){
        if(!b) return a;
        return S{a.one,a.zero,a.one*a.zero-a.ans};
    };
    auto h=[](bool a,bool b){
        return (a&&!b) || (!a&&b);
    };
    int sz=1; while(sz<n) sz*=2;
    vector<S> vec(sz);
    rep(i,sz){
        if(i<n) vec[i]=v[i];
        else vec[i]={0,0,0};
    }
    LazySegmentTree<S,bool> lst(f,g,h,{0,0,0},false);
    lst.build(vec);
    while(Q--){
        int t,l,r; cin >> t >> l >> r;
        l--;
        if(t==1){
            lst.update(l,r,true);
        }else{
            cout << lst.query(l,r).ans << "\n";
        }
    }
    
}
