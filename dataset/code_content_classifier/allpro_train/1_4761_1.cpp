#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 500;

int n,m;

struct mat
{
    bitset<MAX_N> a[MAX_N];
};

mat operator*(const mat& m1,const mat& m2){
    mat ans;
    rep(i,MAX_N){
        rep(j,MAX_N){
            if(m1.a[i][j] == 0) continue;
            ans.a[i] |= m2.a[j];
        }
    }
    return ans;
}

bool possible(mat m, ll cnt)
{
    mat res;
    rep(i,n){
        res.a[i].set(i);
    }
    while(cnt){
        if(cnt & 1){
            res = res*m;
        }
        cnt >>= 1;
        m = m*m;
    }
    return ((int)res.a[0].count() == n);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    mat A;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        A.a[x-1].set(y-1);
    }
    ll l = 0, r = 50000000000LL;
    if(!possible(A,r)){
        cout << "-1\n";
        return 0;
    }
    while(r-l>1){
        ll mid = (l+r)/2;
        if(possible(A,mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r%MOD << "\n";
    return 0;
}

