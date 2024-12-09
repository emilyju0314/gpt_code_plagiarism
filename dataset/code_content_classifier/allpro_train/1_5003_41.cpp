#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;

signed main(){
    long long H,W;cin>>H>>W;
    long long ans=LLONG_MAX;
    long long Sx,Sy,Sz;
    REP(i,W-1){
        Sx=(i+1)*H;
        Sy=(H/2)*(W-i-1);
        Sz=((H+1)/2)*(W-i-1);
        ans=min(ans,max({Sx,Sy,Sz})-min({Sx,Sy,Sz}));
    }
    REP(i,H-1){
        Sx=(i+1)*W;
        Sy=(W/2)*(H-i-1);
        Sz=((W+1)/2)*(H-i-1);
        ans=min(ans,max({Sx,Sy,Sz})-min({Sx,Sy,Sz}));
    }
    ans=min(ans,min(((W+2)/3)*H-(W/3)*H,((H+2)/3)*W-(H/3)*W));
    cout<<ans<<endl;
}