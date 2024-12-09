#include<bits/stdc++.h>
using namespace std;
namespace debug {
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) {os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template<typename T> void dbg_a(const T *a,int l,int r){cerr<<" {";for(int i = l;i<r;i++) cerr<<a[i]<<", ";cerr<<a[r]<<"}"<<endl;}
}
using namespace debug;
typedef long long ll;
#define int ll
inline int read(){
    int f(1),r(0);char c(getchar());
    while(c<'0'||c>'9'){if(c == '-') f = -1; c = getchar();}
    while(c>='0'&&c<='9'){ r = (r<<1) + (r<<3) + c - '0';c = getchar();}
    return f*r;
}
typedef pair<int,int> PII;
#define fi first
#define se second
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for(int i = a;i<=b;i++)
#define For_(i,a,b) for(int i = a;i>=b;i--)
#define _for(i,a) for(int i = 0;i<a;i++)
#define _sum(a,l,r) accumulate(a + l,a + r + 1,0)
#define All(x) x.begin(),x.end()
//    For(i,1,n) For(j,1,m) printf("f[%lld][%lld] = %lld\n",i,j,f[i][j]);
const ll INF = 0x3f3f3f3f3f3f3f3f;
//const int INF = 0x3f3f3f3f;
const int N = 5000 + 20,M = N*2 + 6;
const int mod = 998244353;
int n,m,k;
int h[N],ne[M],e[M],idx;
void add(int a,int b){
    e[++idx] = b,ne[idx] = h[a],h[a] = idx;
}
int dp[N][N],siz[N];
int tmp[N];
void dfs(int x,int pr){
    dp[x][0] = 1;
    siz[x] = 1;
    for(int i = h[x];i;i = ne[i]){
        int y = e[i];
        if(y == pr) continue;
        dfs(y,x);
        //For(i,0,max(siz[x],siz[y]+1)) tmp[i] = 0;
        mst(tmp,0);
        For(i,0,min(k,siz[x])) For(j,0,min(k,siz[y])){
            tmp[i] = (tmp[i] + 1ll*dp[x][i]*dp[y][j]%mod)%mod;
            if(i + j + 1 <= k) {
                tmp[max(i,j+1)] = (tmp[max(i,j+1)] + 1ll*dp[x][i]*dp[y][j]%mod)%mod;
            }
        }
        For(i,0,k) dp[x][i] = tmp[i];
        siz[x] += siz[y];
    }
}

void solve(){
    n = read(),k = read();
    For(i,1,n-1){
        int x = read(),y = read();
        add(x,y); add(y,x);
    }
    dfs(1,0);
    int ans = 0;
    For(i,0,k) ans = (ans + dp[1][i])%mod; 
    cout<<ans<<"\n";
}
signed main(){
    int T = 1;
    //T = read();
    while(T--) solve();
    //system("pause");
    return 0;
}