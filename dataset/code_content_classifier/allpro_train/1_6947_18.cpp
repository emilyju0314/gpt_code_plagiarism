#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nline "\n"
const ll M=1e9+7;
const ll N=5e6+5;
ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()         
{    
    ios_base::sync_with_stdio(false);            
    cin.tie(NULL);        
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);                      
    freopen("output.txt", "w", stdout);          
    #endif   
    ll t; cin>>t;    
    while(t--){
        ll n,k; cin>>n>>k;
        ll x,y; cin>>x>>y;   
        ll check=abs(x-y);
        for(ll i=2;i<n;i++){
            cin>>y;  
            check=gcd(check,abs(x-y));
        }
        k=abs(k-x);
        if(k%check==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;                 
}                                