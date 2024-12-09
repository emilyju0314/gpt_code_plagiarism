#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define mus         multiset<ll>
#define itr         :: iterator
#define pi          3.141592653589793238462
#define setp(x)     fixed << setprecision(x)
#define RU(v)       v.resize(distance(v.begin(), unique(all(v))))
#define M1          1000000007
#define NO          cout<<"NO\n"
#define YES         cout<<"YES\n"
#define MOD         998244353
#define N           200005
#define inf         10e17
using namespace std;
void blowback()
{
    ll i,j,l,k,q,n,m,x,y,r,ans=0,sum=inf,flag=0;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)cin>>a[i];
    mus m1;
    l=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==l)continue;
        if(m1.find(a[i])==m1.end())
        {
            m1.insert(l);
            l=a[i];
            ans++;
            continue;
        }
        m1.clear();
        m1.insert(l);
        l=a[i];
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long int t=1;
    //cin>>t;
    while(t--)
    {
        blowback();
    }
    return 0;
}
