#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ll long long
#define int long long

#define ld double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define INF 1000000000000000
#define MOD 1000000007
int dsu[100005];
int w[100005];
int pend[100005];
int findp(int i)
{
    return (dsu[i]<0)?i:(dsu[i]=findp(dsu[i]));
}
void merge(int i,int j)
{
    if((i=findp(i))!=(j=findp(j)))
    {
        if(dsu[i]>dsu[j])
        {
            swap(i,j);
        }
        w[i]+=w[j];
        pend[i]+=pend[j];
        dsu[i]+=dsu[j];
        dsu[j]=i;
    }
}
signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(11);
        ll n,m;
        cin>>n>>m;
        rep(i,100005)
            dsu[i]=-1;
        rep(i,n)
        {
            cin>>w[i+1];
        }
        vector<pair<int,pair<int,int>>>v;
        rep(i,m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            v.pb(mp(c,mp(a,b)));
        }
        sort(all(v));
        ll ans=0;
        rep(i,m)
        {
            int a=v[i].ss.ff;
            int b=v[i].ss.ss;
            int c=v[i].ff;
            merge(a,b);
            int x=findp(a);
            if(w[x]>=c)
            {
                ans+=pend[x]+1;
                pend[x]=0;
            }
            else
            {
                pend[x]++;
            }
        }
        cout<<m-ans;
            return 0;
}