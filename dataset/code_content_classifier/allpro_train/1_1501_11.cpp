#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);

    ll T;
    cin>>T;
    //cout<<T<<endl;
    for(ll I=1; I<=T; I++) {
        ll n,low,high;
        cin>>n>>low>>high;

        vector<ll>vv;
        for(ll i=0,x; i<n; i++) {
            cin>>x;
            vv.push_back(x);
        }

        sort(vv.begin(),vv.end());
        ll ans=0;

        for(ll i=0; i<n-1 && vv[i]<high ; i++) {
            ll st=lower_bound(vv.begin()+i+1,vv.end(),low-vv[i])-vv.begin();
            ll en=upper_bound(vv.begin()+i+1, vv.end(),high-vv[i])-vv.begin();
            if(vv[en]!=high-vv[i]) {
            }

            ans+=(en-st);
        }

        cout<<ans<<endl;
    }
}