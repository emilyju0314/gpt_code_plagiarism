#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
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
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
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

const int MAX_N = 2005;

ll dp[MAX_N][MAX_N];

ll add(ll x,ll y)
{
    return (x + y)%MOD;
}

ll sub(ll x,ll y)
{
    return (x+MOD-y)%MOD;
}

ll mul(ll x,ll y)
{
    return x*y%MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<char> vec(n);
    rep(i,n){
        cin >> vec[i];
    }
    // svec(vec);
    dp[0][0] = 1;
    rep(i,n){
        rep(j,i+1){
            if(vec[i] == '-'){
                dp[i+1][j] = add(dp[i+1][j],dp[i][j]);
            }else if(vec[i] == 'D'){
                dp[i+1][j] = add(dp[i+1][j],mul(j,dp[i][j]));
                if(j != 0){
                    dp[i+1][j-1] = add(dp[i+1][j-1],mul(j*j,dp[i][j]));
                }
            }else{
                dp[i+1][j] = add(dp[i+1][j],mul(j,dp[i][j]));
                dp[i+1][j+1] = add(dp[i+1][j+1],dp[i][j]);
            }
        }
    }
    // rep(i,n+1){
    //     rep(j,i+1){
    //         cout << i << " " << j << " " << dp[i][j] << "\n";
    //     }
    // }
    cout << dp[n][0] << "\n";
    return 0;
}