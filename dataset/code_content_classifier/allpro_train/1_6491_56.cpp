#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll Q;
    cin >> Q;

    vector<ll> f(100001);
    FOR(i, 1, 100001){
        ll divisorCount = 0;
        for(int j=2; j*j<=i; j++){
            if(i%j==0) divisorCount++;
        }
        if(divisorCount>=2){
            f[i] = 1;
        }
    }
    // 累積和
    FOR(i, 1, 100001){
        f[i] += f[i-1];
    }

    while(Q--){
        ll N; cin >> N;

        ll ans = f[N];
        p(ans);
    }
    
    return 0;
}
