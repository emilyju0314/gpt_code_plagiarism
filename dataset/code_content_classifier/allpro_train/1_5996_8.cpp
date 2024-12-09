#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) {os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template<typename T> void dbg_a(const T *a,int l,int r){cerr<<" {";for(int i = l;i<r;i++) cerr<<a[i]<<", ";cerr<<a[r]<<"}"<<endl;}
typedef long long ll;
#define int ll
inline int read(){
    int f(1),r(0);char c(getchar());
    while(c<'0'||c>'9'){if(c == '-') f = -1; c = getchar();}
    while(c>='0'&&c<='9'){ r = (r<<1) + (r<<3) + c - '0';c = getchar();}
    return f*r;
}
void read(int &x){ x = read();}
template<class Head, class... Tail> void read(Head &head, Tail &... tail) { read(head); read(tail...); }
typedef pair<int,int> PII;
#define fi first
#define se second
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for(int i = a;i<=b;i++)
#define For_(i,a,b) for(int i = a;i>=b;i--)
#define _for(i,a) for(int i = 0;i<a;i++)
#define Sum(a,l,r) accumulate(a + l,a + r + 1,0)
#define All(x) x.begin(),x.end()

//    For(i,1,n) For(j,1,m) printf("f[%lld][%lld] = %lld\n",i,j,f[i][j]);
//const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9 + 1;
const int N = 3e5 + 6,M = N*2 + 6;
const int mod = 998244353;
struct node{
    int to,id;
    node(int to,int id):to(to),id(id) {}
};
vector<node> G[N];
int n,m,k;
int a[N];
bool vis[N];
int ans[N],l,r;
void dfs(int x){
    vis[x] = 1;
    for(auto e:G[x]){
        int y = e.to,id = e.id;
        if(vis[y]) continue;
        dfs(y);
        if(a[x] + a[y] >= k){
            a[x] += a[y] - k;
            ans[l++] = id;
        }
        else ans[r--] = id;
    }
}
void solve(){
    n = read();m = read(),k = read();
    int sum = 0;
    For(i,1,n) a[i] = read(),sum += a[i];
    if(sum < (n-1)*k){
        cout<<"NO\n";
        return;
    }
    For(i,1,m){
        int x,y;
        read(x,y);
        //cin>>x>>y;
        G[x].emplace_back(y,i);
        G[y].emplace_back(x,i);
    }
    l = 1,r = n-1;
    dfs(1);
    cout<<"YES\n";
    For(i,1,n-1) cout<<ans[i]<<"\n";
}
signed main(){
    int Tt = 1;
    //Tt = read();
    while(Tt--) solve();
    return 0;
}