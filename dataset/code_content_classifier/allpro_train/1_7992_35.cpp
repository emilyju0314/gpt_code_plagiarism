#include "bits/stdc++.h"
#define ll long long
#define endl "\n"
using namespace std;
ll MOD = 998244353ll;
ll power(ll base,ll exp)
{
    base = base % MOD;
    if(base==0)
        return 0;
    if(exp==0)
        return 1;
    ll ans=1;
    ll temp = power(base,exp/2); 
    ans =  (temp * temp) % MOD;
    if(exp & 1)
        ans = (ans * base)%MOD;
    return ans;
}
ll inverse(ll a)
{
    return power(a,MOD-2);
}

void solve()
{
	int n;
    cin>>n;
    int b[n+2];
    ll sum =0;
    for(int i=0;i<n+2;i++)
    {
        cin>>b[i];
        sum+= b[i];
    }
    map<ll,int> mp;
    for(int i=0;i<n+2;i++)
    {
        mp[b[i]]++;
    }

    for(int i=0;i<n+2;i++)
    {

        ll y = sum - b[i];
        mp[b[i]]--;
        if(y%2==1)
        {
            mp[b[i]]++;
            continue;
        }
        if(mp.find(y/2)!=mp.end())
        {
            if(mp[y/2]>0)
            {
                // cout<<"ff";
                bool found = false;
                for(int j=0;j<n+2;j++)
                {
                    if(j==i)
                        continue;
                    else if(!found && b[j]==y/2)
                    {
                        found=true;
                    }
                    else
                        cout<<b[j]<<" ";
                }
                cout<<endl;
                return;
            }
        }
        mp[b[i]]++;
    }
    cout<<-1<<endl;return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("C:\\Users\\KAMLESH PRAJAPATI\\Desktop\\input.txt","r",stdin);
    // freopen("C:\\Users\\KAMLESH PRAJAPATI\\Desktop\\output.txt","w",stdout);
    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}

