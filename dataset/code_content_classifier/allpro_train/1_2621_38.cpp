#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mp make_pair
#define pb push_back
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define fr1(j,a,b) for(ll j=a;j<b;j++)
#define fr2(v,a,b) for(ll v = a -1;v>=0;v--)
void solve()
{ 
    ll n;
    cin>>n;
    vector<ll> arr(n);
    fr(i,0,n)
    cin>>arr[i];
    
    ll sum =0;
    for(ll i =0;i<n-1;i++)
    sum+= abs(arr[i]-arr[i+1]);
    
    ll ans = sum;
    for(ll i =0;i<n;i++)
    {  
        if(i!=n-1)
         {   
             if(i==0)
             {
                 ll p = sum - abs(arr[i]-arr[i+1]);
                 ans = p;
             }
             else
             {
                 ll p = sum - abs(arr[i]-arr[i-1]);
                 p-= abs(arr[i]-arr[i+1]);
                 p+= abs(arr[i+1]-arr[i-1]);
                 
                 if(p<ans)
                 ans = p;
             }
             
         }
         else
         {
             ll p = sum - abs(arr[i]-arr[i-1]);
             if(p<ans)
             ans = p;
         }
    }
    cout<<ans;
    return;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}
