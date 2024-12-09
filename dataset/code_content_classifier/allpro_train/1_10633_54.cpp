#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
using ll = long long;
using namespace std;

int main(){
	ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ll answ=a,anss=0,w=0,s=0;
    double ans=0;
    rep(i,0,f/(100*a)+1){
        rep(j,0,f/(100*b)+1){
            w=i*a+j*b;
            rep(k,0,(f-w)/c+1){
                rep(l,0,(f-w)/d+1){
                    s=k*c+l*d;
                    if((w*100+s)<=f && e>=s/(double)w){
                        if(ans<(s/(double)w)){ans=(s/(double)w);answ=w;anss=s;}
                    }
                }
            }
        }
    }
    cout<<answ*100+anss<<" "<<anss;
}