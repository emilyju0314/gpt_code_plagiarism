#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
using ll = long long;
using ld = long double;
ll MOD = 998244353;
const ll root = 3;
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 1001;
ll dp[mxN][mxN][4];
string x, y;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    x = "?" + s;
    cin>>s;
    y = "?" + s;
    ll ans = 0;
    owo(i, 0, x.size()) {
        owo(j, 0, y.size()) {
            //add one from x
            if(i > 0) {
                dp[i][j][2] = 1;
                if(x[i]!=x[i-1]) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][0])%MOD;
                    dp[i][j][2] = (dp[i][j][2] + dp[i-1][j][2])%MOD;
                }
                if(x[i]!=y[j]) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][1])%MOD;
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][3])%MOD;
                }
            }
            if(j > 0) {
                dp[i][j][3] = 1;
                if(y[j]!=y[j-1]) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][1])%MOD;
                    dp[i][j][3] = (dp[i][j][3] + dp[i][j-1][3])%MOD;
                }
                if(x[i]!=y[j]) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][0])%MOD;
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][2])%MOD;
                }
            }
            ans = (ans + dp[i][j][0] + dp[i][j][1])%MOD;
            //cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<dp[i][j][2]<<" "<<dp[i][j][3]<<" "<<x[i]<<" "<<y[j]<<"\n";
        }
    }
    cout<<ans<<"\n";
    return 0;
}