#include<bits/stdc++.h>
#define ll long long
#define mod 998244353ll
using namespace std;
vector<int>vec[50001];
ll fact[22], inv[22];
ll ncr(int n, int r)
{
    if(r>n)return 0;
    ll nume= fact[n];
    ll deno= (inv[r]*inv[n-r])%mod;
    return (nume*deno)%mod;
}
int n, m;
ll bad(int i)
{
    sort(vec[i].begin(), vec[i].end());
    ll ret= 1ll;
    for(int j=0; j<n; j++)
    ret= (ret*max(0, (vec[i][j]-1)-j))%mod;
    return ret;
}
ll bigmod(ll b, ll p)
{
    if(!p)return 1ll;
    ll ret= bigmod(b, p/2);
    ret= (ret*ret)%mod;
    if(p&1ll)ret= (ret*b)%mod;
    return ret;
}
int main()
{
    fact[0]= 1ll;
    for(int i=1; i<22; i++)
    fact[i]= (fact[i-1]*i)%mod, inv[i]= bigmod(fact[i], mod-2);

    int x;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    scanf("%d", &x), vec[j].push_back(x);

    ll res= 0;
    for(int i=0; i<m; i++)
    res+= (fact[n]-bad(i)+mod), res%= mod;

    res= (res*inv[n])%mod;
    printf("%lld\n", res);

    return 0;
}
