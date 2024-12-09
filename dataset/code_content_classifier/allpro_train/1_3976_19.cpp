#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i,n) for(ll i=0; i<(n); i++)
template<class T> inline void chmax(T &a, T b){if(a<b)a=b;}
template<class T> inline void chmin(T &a, T b){if(a>b)a=b;}
const ll inf=1LL<<60;
int main(){
    ll H,W,N,ans=0,f=0;
    cin>>H>>W>>N;
    vector<ll> x(N),y(N),z(N);
    vector<vector<ll>> v(H,vector<ll>(W,-inf));
    rep(k,N){
        cin>>x[k]>>y[k]>>z[k];
        x[k]--;y[k]--;
        rep(i,H)rep(j,W){
            chmax(v[i][j],z[k]-(labs(x[k]-i)+labs(y[k]-j)));
        }
    }
    rep(i,N){
        if(v[x[i]][y[i]]!=z[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    rep(i,H)rep(j,W){
        ans+=v[i][j];
        if(i)if(labs(v[i-1][j]-v[i][j])>1)f=1;
        if(j)if(labs(v[i][j-1]-v[i][j])>1)f=1;
        if(f){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}
