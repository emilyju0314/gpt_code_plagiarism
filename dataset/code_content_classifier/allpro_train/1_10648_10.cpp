#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<typeinfo>
#include<functional>
#include<complex>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


/*
 O(QlogN+N)
 追加する直線の傾きが狭義単調減少であること
 maxを求めるときは値と傾きに-1をかけること
 */
template<typename T>
class Comvex_Hull_Trick{
private:
    typedef pair<T,T> line; //y切片,傾き
    deque<line> D;
    
    inline T point(const line &L,const T &x) const {return L.F+L.S*x;}
    
    inline bool is_need(const line &A,const line &B,const line &C) const {
        return (C.F-A.F)*(A.S-B.S)>(B.F-A.F)*(A.S-C.S);
    }
    
public:
    Comvex_Hull_Trick(){}
    
    void add_line(const line &L){
        while(!D.empty() && D.back().F>=L.F){D.pop_back();}
        while(D.size()>=2 && !is_need(D[D.size()-2],D.back(),L)){D.pop_back();}
        D.push_back(L);
    }
    
    T search(const T &x) const {
        ll l=0;
        ll r=D.size()-1;
        while(l+1<r){
            ll m=l+(r-l)/2;
            if(point(D[m],x)<point(D[m+1],x)){r=m;}
            else{l=m+1;}
        }
        for(ll i=l;i<r;i++){
            if(point(D[i],x)<point(D[i+1],x)){return point(D[i],x);}
        }
        return point(D[r],x);
    }
    
    pair<T,T> search_line(const T &x) const {
        ll l=0;
        ll r=D.size()-1;
        while(l+1<r){
            ll m=l+(r-l)/2;
            if(point(D[m],x)<point(D[m+1],x)){r=m;}
            else{l=m+1;}
        }
        for(ll i=l;i<r;i++){
            if(point(D[i],x)<point(D[i+1],x)){return D[i];}
        }
        return D[r];
    }
    
    pair<T,T> back() const {return D.back();}
    
    unsigned long size() const {return D.size();}
    
    bool empty() const {return D.empty();}
};





int main(){
    ll n,t;
    cin>>n>>t;
    vector<vector<ll>> dp(n,vector<ll>(t+1,0));
    Comvex_Hull_Trick<ll> C[t+1];
    vector<pair<pll,ll>> S(n);
    for(int i=0;i<n;i++){
        ll t,p,f;
        cin>>t>>p>>f;
        S[i]={{f,p},t};
    }
    sort(S.begin(),S.end());
    ll mx=0;
    for(int i=0;i<n;i++){
        const pair<pll,ll> &W=S[i];
        if(W.S>t){continue;}
        for(ll j=t-W.S;j>=1;j--){
            if(C[j].empty()){continue;}
            ll P=C[j].search(W.F.F);
            P*=-1;
            P-=W.F.F*W.F.F;
            P+=W.F.S;
            dp[i][j+W.S]=max(dp[i][j+W.S],P);
            mx=max(mx,dp[i][j+W.S]);
            C[j+W.S].add_line({(dp[i][j+W.S]-W.F.F*W.F.F)*-1,-2*W.F.F});
        }
        dp[i][W.S]=max(dp[i][W.S],W.F.S);
        mx=max(mx,dp[i][W.S]);
        C[W.S].add_line({(dp[i][W.S]-W.F.F*W.F.F)*-1,-2*W.F.F});
    }
    cout<<mx<<endl;
    
    
    return 0;
}

