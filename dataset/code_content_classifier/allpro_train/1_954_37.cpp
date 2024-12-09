#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define rel(i,x,y) for(ll i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    ll h[n+1];
    rep(i,0,n) cin >> h[i];
    h[n] = 0;
    stack<pair<ll,ll>> S; //height, locate
    ll ma = 0;
    rep(i,0,n+1){
        if(S.empty()){ S.push(make_pair(h[i],i)); continue; }
        if(S.top().first == h[i]) continue;
        if( S.top().first < h[i]) S.push(make_pair(h[i],i)); //大きいのはstack
        else{
            ll LocateCheck = S.top().second;
            while((!S.empty()) && S.top().first >= h[i] ){
                ma = max(ma,S.top().first * (i-S.top().second));
                LocateCheck = S.top().second;
                S.pop();
            }
            S.push(make_pair(h[i],LocateCheck));
        }
    }
    cout << ma << endl;
}
