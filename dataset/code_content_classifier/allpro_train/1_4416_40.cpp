//
// Created by yamunaku on 2019/07/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

class UnionFind{
    vi node;
public:
    UnionFind(int n){
        node=vi(n,-1);
    }
    int root(int x){
        if(node[x]<0) return x;
        return node[x]=root(node[x]);
    }
    bool uni(int x, int y){
        x=root(x);
        y=root(y);
        if(x==y) return false;
        if(-node[x]<-node[y]) swap(x,y);
        node[x]+=node[y];
        node[y]=x;
        return true;
    }
};

int main(){
    int n,r;
    cin >> n >> r;
    vi p(n);
    UnionFind uf(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
        uf.uni(i,p[i]);
    }
    vi c(n);
    rep(i,n){
        c[uf.root(i)]++;
    }
    vi v;
    v.reserve(n);
    rep(i,n){
        if(c[i]>0) v.push_back(c[i]);
    }
    n=v.size();
//    sort(all(v));
    rep(i,n){
        if(v[i]==r){
            CYES;
            return 0;
        }
    }
    random_device seed_gen;
    mt19937 engine(seed_gen());
    int q=1e8/n;
    rep(_,q){
        shuffle(all(v), engine);
        int k=0,idx=0;
        while(k<r){
            k+=v[idx];
            idx++;
        }
        if(k==r){
            CYES;
            return 0;
        }
    }
    CNO;
    return 0;
}


