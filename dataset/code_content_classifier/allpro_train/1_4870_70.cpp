#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll>pll;
typedef long double ld;
ll bin_pow(ll a,ll b){
    if(b==0)return 1;
    if(b%2==0){
        ll t=bin_pow(a,b/2);
        return t*t%MOD;
    }
    else return a*bin_pow(a,b-1)%MOD;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1,n,m,k=0,sum=0,l=0,r=0,x=0,y=0,z=0,ans=0,mn=LLONG_MAX,mx=LLONG_MIN;
    string s;
    cin>>t;
    while(t--){
            z=ans=0;
        cin>>n>>k;
        s="";
        for(int i=0;i<n;i++){
            s+='a'+i%3;
        }
        cout<<s;
        cout<<"\n";
    }
    return 0;
}
