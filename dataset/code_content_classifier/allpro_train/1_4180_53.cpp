#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define msa memset(a,0,sizeof a)
#define msb memset(b,0,sizeof b)
#define pi pair<int,int>
#define INF 1<<60
#define test cout<<"test_rounds "<<endl
#define pai acos(-1)
#define msc memset(c,0,sizeof c)
#define ull unsigned long long int
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
map<pair<ll,ll>,ll>mp,mp4;
map<ll,ll>mp1,mp2;
ll mp3[200005];
struct s
{
    ll a,b;
} q[200005];
bool cmp(s n,s m)
{
    if(n.a==m.a)return n.b<m.b;
    return n.a<m.a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        ll m,k=0,k1=0;
        cin>>n;
        ll sum=0;
        ll cnt=0;
        vector<pi>v;
        vector<ll>v1;
        for(int i=1; i<=n; i++)
        {
            ll x,y;
            cin>>x>>y;
            if(x>y) swap(x,y);
            v.pb({x,y});
            q[i].a=x;
            q[i].b=y;
            mp4[{x,y}]=i;
        }
        //test;
//        for(int i=1; i<=n; i++)
//        {
//         cout<<q[i].a<<' '<<q[i].b<<endl;
//        }
        sort(q+1,q+n+1,cmp);
        //test;
        for(int i=1; i<=n; i++)
        {
            //cout<<q[i].a<<' '<<q[i].b<<endl;
        }
        ll mn=INT_MAX;
        ll pos=0;
        for(int i=1; i<=n; i++)
        {
            ll x=q[i].a;
            ll y=q[i].b;

            if(mp1[x]==0)
            {
                mp2[i-1]=mn;
                mp3[i-1]=pos;
                if(mn<y)
                {
                    mp[{x,y}]=mp3[i-1];
                }
                else
                    mp[{x,y}]=0;
                    mp1[x]=i;
            }
            else
            {
                if(mp2[mp1[x]-1]<y)
                {
                    mp[{x,y}]=mp3[mp1[x]-1];
                }
            }
            if(mn>y)
            {
                mn=y;
                pos=i;
            }
        }
        for(auto i:v)
        {
            if(mp[i]==0)cout<<-1<<' ';
            else
            {
                ll x=mp[i];
                ll l=q[x].a,r=q[x].b;
                cout<<mp4[{l,r}]<<' ';
            }
        }
        mp.clear();
        mp1.clear();
        mp2.clear();
        mp4.clear();
        cout<<endl;



    }
}
