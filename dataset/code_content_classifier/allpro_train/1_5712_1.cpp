#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(kbrni,n)cout<<" "<<a[kbrni];cout<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define svecp(v) cout<<#v<<":";each(kbrni,v)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

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

const int MAX_N = 100005;

P t[MAX_N];
vector<int> G[MAX_N];
bool dp[MAX_N][2][2][2];

int opr(int pos,int pre,int x,int y)
{
    if(t[pos].se == 0){
        if(t[pos].fi == 0){
            return (pre|x);
        }else if(t[pos].fi == 1){
            return (pre&x);
        }else{
            return (pre^x);
        }
    }else{
        if(t[pos].fi == 0){
            return (pre|y);
        }else if(t[pos].fi == 1){
            return (pre&y);
        }else{
            return (pre^y);
        }
    }
}

int dfs(int u,int p,int nw,int x,int y,int d)
{
    if(len(G[u]) == 1 && G[u][0] == p){
        return nw;
    }
    int ans;
    if(d%2){
        ans = (x|y);
    }else{
        ans = 0;
    }
    for(int v : G[u]){
        if(v != p){
            int res = opr(v,nw,x,y);
            if(d % 2){
                cmn(ans,dfs(v,u,res,x,y,d+1));
            }else{
                cmx(ans,dfs(v,u,res,x,y,d+1));
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    string s;
    rep(i,n-1){
        cin >> s;
        if(s[3] == '|'){
            t[i+1].fi = 0;
        }else if(s[3] == '&'){
            t[i+1].fi = 1;
        }else{
            t[i+1].fi = 2;
        }
        if(s[4] == 'X'){
            t[i+1].se = 0;
        }else{
            t[i+1].se = 1;
        }
    }
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        G[a].pb(b),G[b].pb(a);
    }
    map<vi,int> mp;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        vector<P> vec;
        vector<int> hoge(8);
        vec.pb(P(0,0)),vec.pb(P(a&b,1)),vec.pb(P(a|b,2)),vec.pb(P(a^b,3));
        vec.pb(P((a&b)^a,4)),vec.pb(P((a&b)^b,5)),vec.pb(P(a,6)),vec.pb(P(b,7));
        rep(j,8){
            hoge[j] = vec[j].fi;
        }
        sort(all(vec));
        vector<int> id;
        rep(j,8){
            id.pb(vec[j].se);
        }
        if(mp.find(id) == mp.end()){
            int res = dfs(0,-1,0,a,b,0);
            rep(j,len(vec)){
                if(res == vec[j].fi){
                    mp[id] = vec[j].se;
                    break;
                }
            }
            cout << res << "\n";
        }else{
            cout << hoge[mp[id]] << "\n";
        }
    }
    return 0;
}

