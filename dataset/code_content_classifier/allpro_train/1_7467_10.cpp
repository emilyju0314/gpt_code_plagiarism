#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define PI acos(-1)
#define pb push_back
#define int long long
#define ld long double
#define sp fixed<<setprecision
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int M = (1e9)+7;
const int N = 200005;
const int INF = 1e12;

int n,k;
int memo[1005][1005][2];

int solve(int nn, int kk, int dir)
{
    if(kk == 1) return 1;
    if(memo[nn][kk][dir] != -1)return memo[nn][kk][dir];
    int res = 1;
    if(dir)
        for(int i=1;i<nn;i++) res += solve(i, kk-1, 1-dir), res %= M;
    else
        for(int i=nn+1;i<=n;i++) res += solve(i, kk-1, 1-dir), res %= M;
    memo[nn][kk][dir] = res;
    return res;
}

signed main()
{
    FAST
    int tc=1;
    cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        cin>>n>>k;
        for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)memo[i][j][0] = memo[i][j][1] = 0;
        for(int i=1;i<=n;i++)memo[i][1][0] = memo[i][1][1] = i;
        for(int j=2;j<=k;j++)
        {
            for(int i=1;i<=n;i++)
            {
                memo[i][j][0] = (1 + memo[n][j-1][1] - memo[i][j-1][1] + M)%M;
                memo[i][j][1] = (1 + memo[i-1][j-1][0])%M;
                memo[i][j][0] += memo[i-1][j][0], memo[i][j][0] %= M;
                memo[i][j][1] += memo[i-1][j][1], memo[i][j][1] %= M;

            }
        }
        int ans = 1;
        for(int i=1;i<=n;i++)ans += (memo[i][k-1][1] - memo[i-1][k-1][1] + M)%M, ans %= M;
        cout<<ans<<endl;
    
    }
    return 0;
}