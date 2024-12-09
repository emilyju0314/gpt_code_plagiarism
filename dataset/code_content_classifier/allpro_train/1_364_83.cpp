#include<bits/stdc++.h>
using namespace std;

#define inf 1001000009
#define infmx 1e18
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define MP make_pair
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define all(x) x.begin(),x.end()

typedef pair<int,int>pi;
typedef pair<long long,long long>pll;
typedef pair<pi,int>ppi;
typedef pair<int,pi>pip;
typedef vector<int>vi;
typedef vector<pi>vpi;
const int mod=1e9+7;
const int N=5005;
int ara[N];
int dp[N][N];
int one[N]; ///position of ith one
int k,n;
int call(int i,int tk)
{
    if(tk==k)return 0;
    if(i>=n+1)return inf;
    if(dp[i][tk]!=-1)return dp[i][tk];
    int f1 = inf,f2=inf;
    if(ara[i]==0)       ///take the ith 0
        f1 = abs(i-one[tk+1])+call(i+1,tk+1);
    f2 = call(i+1,tk);
    return dp[i][tk]=min(f1,f2);
}
int main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        if(ara[i]==1)
            one[++k] = i;
    }
    memset(dp,-1,sizeof dp);
    int ans = call(1,0);
    cout<<ans<<endl;
}

