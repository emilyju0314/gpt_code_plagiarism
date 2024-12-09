#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> P;
signed main(){
    P a,b;
    ll n,m;
    cin>>n>>m;
    a.first=n,a.second=n*2;
    b.first=m,b.second=m*2;
    ll cnt1=0,cnt2=0;
    ll atk;
    
    while(1){
        atk=min(n,a.second);
        b.second-=atk;
        if(b.second<=0) break;
        cnt1++;
        
        
        atk=min(m,b.second/2+b.second%2);
        a.second-=atk;
        if(a.second<=0) break;
        cnt1++;
        
    }
    
    a.first=n,a.second=n*2;
    b.first=m,b.second=m*2;
    
    while(1){
        atk=min(n,a.second/2+a.second%2);
        b.second-=atk;
        if(b.second<=0) break;
        cnt2++;
        
        
        atk=min(m,b.second);
        a.second-=atk;
        if(a.second<=0) break;
        cnt2++;
        
    }
    ll ans=min(cnt1,cnt2);
    cout<<ans<<endl;
    return 0;
}


