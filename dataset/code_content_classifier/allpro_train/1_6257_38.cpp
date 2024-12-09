#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef map<ll,ll> mii;
#define pb push_back
#define mp make_pair
#define mod 998244353


bool check(ll a,ll b,ll c){
    if(b>=a and b<=c)
        return false;

    if(b>=c and b<=a)
        return false;

    return true;
}

int main()
{

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r",stdin);
    //for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

ll t;
cin>>t;
    while (t--){
        
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }    
        ll ans=0;
        ans=2*n-1;
        // for 3elements
        for(ll i=0;i<n-2;i++){
            if(check(a[i],a[i+1],a[i+2]))
                ans++;
        }
        // for 4 elements
        for(ll i=0;i<n-3;i++){
            if(check(a[i],a[i+1],a[i+2]) and check(a[i],a[i+1],a[i+3]) and check(a[i],a[i+2],a[i+3]) and check(a[i+1],a[i+2],a[i+3])){
            ans++;
            // cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<" "<<a[i+3]<<endl;
        }

        }
        cout<<ans<<endl;   

    }

}





