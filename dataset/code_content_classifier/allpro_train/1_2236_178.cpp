#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;




int main(){
    ll H,W;cin>>H>>W;
    ll c[10][10],w[210][210],ans=0;
    rep(i,0,10)rep(j,0,10)cin>>c[i][j];
    rep(i,0,H)rep(j,0,W)cin>>w[i][j];
    rep(k,0,10)rep(i,0,10)rep(j,0,10)c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
    rep(i,0,H){
        rep(j,0,W){
            if(w[i][j]!=-1)ans+=c[w[i][j]][1];
        }
    }
    cout<<ans<<endl;
}





