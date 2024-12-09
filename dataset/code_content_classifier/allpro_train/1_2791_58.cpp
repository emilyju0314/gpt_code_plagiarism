#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        if(n%2==0){
            ll ans=k%n;
            if(ans==0)
            ans+=n;
            cout<<ans<<endl;
        }
        else{
            ll miss=n/2;
            miss=(k-1)/miss;
            ll ans=(k+miss)%n;
            if(ans==0)
            ans+=n;
            cout<<ans<<endl;
        }
        
        
    }
	return 0;
}
