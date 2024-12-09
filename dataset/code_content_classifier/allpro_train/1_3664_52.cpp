#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#include<iomanip>
#include<ctime>
#define maxn 1000005
#define inf 0x7fffffffffff
#define mod 1000000007
#define mst(a,x) memset(a,x,sizeof(a))
#define endl "\n"
#define hh cout<<endl
#define up(l,r,i) for(LL i=l;i<=r;i++)
#define down(l,r,i) for(LL i=l;i>=r;i--)
#define in(l,r,a) for(LL i=l;i<=r;i++)cin>>a[i]
#define out(l,r,a) for(LL i=l;i<=r;i++)cout<<a[i]<<" ";hh;
#define injz(n,m,a) for(LL i=1;i<=n;i++)for(LL j=1;j<=m;j++)cin>>a[i][j]
#define st(a,n) sort(a+1,a+n+1)
#define sta(v) sort(v.begin(),v.end())
#define pb push_back
#define cf cin>>T;while(T--)
#define xh(n) U=n;while(U--)
#define cfout(x) cout<<(x?"YES":"NO")<<endl
#define cs cerr<<"qaq"<<endl
#define dbg(n) cerr<<n<<endl
typedef long long LL;LL T,U;
typedef double db;
using namespace std;
vector<LL>bian[maxn];
LL a[maxn],b[maxn],vis[maxn],ans;
void go(LL now)
{
    vis[now]=1;
    for(LL i:bian[now])
    {
        if(!vis[i])go(i);
    }
    return;
}
LL fastpower(LL base,LL power)
{
    LL result=1;
    while(power)
    {
        if(power&1)result=result*base%mod;
        power>>=1;
        base=(base*base)%mod;
    }
    return result%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef ONLINE_JUDGE
    #else
    freopen("bwxnQAQin.txt","r",stdin);
    //freopen("bwxnQAQout.txt","w",stdout);
    #endif
    cf
    {
        ans=0;
        LL n;
        cin>>n;
        up(1,n,i)
        {
            vis[i]=0;
            bian[i].clear();
        }
        in(1,n,a);
        in(1,n,b);
        up(1,n,i)
        {
            bian[a[i]].pb(b[i]);
            bian[b[i]].pb(a[i]);
        }
        up(1,n,i)
        {
            if(vis[a[i]])continue;
            go(a[i]);
            ans++;
        }
        cout<<fastpower(2,ans)<<endl;
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms";
    return 0;
}
