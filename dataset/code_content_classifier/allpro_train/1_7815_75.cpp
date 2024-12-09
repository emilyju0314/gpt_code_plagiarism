#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 998244353
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

ll p_even[N];
ll p_odd[N];
ll ans[N];

ll bigmod(ll a,ll n)
{
    if(n==0) return 1;
    ll ans=bigmod(a,n/2);
    ans=(ans*ans)%M;
    if(n%2==1)
        ans=(ans*a)%M;
    return ans;
}




int main()
{
   // cout<<(4*bigmod(32,M-2))%M<<endl;
    int n;
    cin>>n;

    ans[n+1]=1;
    if(n%2==1) p_even[n+1]=1;
    else p_odd[n+1]=1;

    for(int i=n;i>=1;i--)
    {
        if(i%2==1)
        {
            ans[i]=p_even[i+1]%M;
            p_odd[i]=p_odd[i+2]+ans[i];
            p_odd[i]%=M;
        }
        else
        {
            ans[i]=p_odd[i+1]%M;
            p_even[i]=p_even[i+2]+ans[i];
            p_even[i]%=M;
        }
    }
    cout<<(ans[1]*bigmod(bigmod(2,n),M-2))%M;

}

