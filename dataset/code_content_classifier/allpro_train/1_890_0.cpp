#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

#define ll long long int
#define pb push_back
#define CR7                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define pii pair<ll, ll>
#define MOD 1000000007
#define vi vector<ll>
#define vii vector<pii>
#define mi map<ll, ll>
//RRMMMMMMMMMRRRRRRRRRR!!
ll a[100000];
ll k;
// ll ans(ll n, ll sum)
// {
//     ll dp[n + 1][sum + 1];
//     for (ll i = 0; i <= n; i++)
//     {
//         for (ll j = 0; j <= sum; j++)
//         {
//             if (i == 0)
//                 dp[0][j] = 0;
//         }
//     }
//     for (ll i = 0; i <= n; i++)
//     {
//         for (ll j = 0; j <= sum; j++)
//         {
//             if (j == 0)
//                 dp[i][j] = 1;
//         }
//     }

//     for (ll i = 1; i <= n; i++)
//     {
//         for (ll j = 1; j <= sum; j++)
//         {
//             if (a[i - 1] <= j)
//                 dp[i][j] = ((dp[i - 1][j - a[i - 1]] % mod) + (dp[i - 1][j] % mod)) % mod;
//             else
//                 dp[i][j] = (dp[i - 1][j]) % mod;
//         }
//     }
//     return dp[k][sum] % mod;
// }

const int N = 1005;
ll fact[N];
ll mod_pow(ll a , ll n , ll mod){
    if(n == 0){
        return 1;
    }
    ll res = mod_pow((a*a)%mod , n/2 , mod);
    if(n % 2){
        res = (res*a)%mod;
    }
    return res;
}
ll mod_inv(ll x , ll mod){
    return mod_pow(x , mod - 2 , mod);
}
ll nCr(ll n , ll r , ll mod){
    return ((fact[n]*mod_inv(fact[r] , mod) % mod)* (mod_inv(fact[n - r] , mod) % mod))%mod;
}
void factorial(ll mod){
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (i*fact[i - 1]);
        fact[i] %= mod;
    }
}

int main()
{
    CR7;
    ll t;
    cin >> t;
    factorial(MOD);
    while (t--)
    {
        ll n;
        cin >> n >> k;
        ll b[n];
        mi ma, mk;
        for (ll i = 0; i < n; i++)
            cin >> a[i], b[i] = a[i], ma[a[i]]++;

        sort(b, b + n);
        reverse(b, b + n);
        ll sum = 0;
        for (ll i = 0; i < k; i++)
        {
            sum += b[i];
            mk[b[i]]++;
        }
        ll mxans = 1;
        for (auto g : mk)
        {
           mxans = ((mxans % MOD) * nCr(ma[g.first], g.second,MOD) % MOD)%MOD;
           if(mxans<0)
             mxans+=MOD;
        }
        if(mxans<0)
             mxans+=MOD;
        cout << mxans%MOD<< endl;
    }
    return 0;
}