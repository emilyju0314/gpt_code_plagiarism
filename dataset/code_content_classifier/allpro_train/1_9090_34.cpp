/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

struct BIT2D { //1-indexed
private:
    ll h,w;
    vector< vector<ll> > dat;

public:
    BIT2D(ll H, ll W){
        h = H; w = W;
        dat.assign(h+10, vector<ll>(w+10, 0));
    }

    void update(ll x, ll y, ll v){
        for(ll i = x; i <= h; i += i & -i) for( ll j = y; j <= w; j += j & -j) dat[i][j] += v;
    }

    ll qsum(ll x, ll y){
        ll res = 0;
        for(ll i = x; i > 0; i -= i & -i) for(ll j = y; j > 0; j -= j & -j) res += dat[ i ][ j ];
        return res;
    }

    ll qsum(ll x0,  ll y0,  ll x1,  ll y1){
        return qsum(x1, y1) - qsum(x0-1, y1) - qsum(x1, y0-1) + qsum(x0-1, y0-1);
    }

    ll get(ll x, ll y){
        return qsum(x, y, x, y);
    }
};

typedef struct {
    ll h;
    ll w;
    ll t;
} P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W,T,Q;
    cin >> H >> W >> T >> Q;
    BIT2D bit_fin(H,W), bit_mada(H,W);
    queue<P> que;
    while(Q--){
        ll t,c,h1,w1,h2,w2;
        cin >> t >> c >> h1 >> w1;
        if(c == 2) cin >> h2 >> w2;
        while(not que.empty()){
            P p = que.front();
            if(t - p.t >= T){
                que.pop();
                bit_fin.update(p.h, p.w, 1);
                bit_mada.update(p.h, p.w, -1);
            }else{
                break;
            }
        }
        if(c == 0){
            bit_mada.update(h1, w1, 1);
            que.push((P){h1,w1,t});
        }else if(c == 1){
            if(bit_fin.get(h1,w1) >= 1){
                bit_fin.update(h1,w1,-1);
            }

        }else{
            ll v1 = bit_fin.qsum(h1,w1,h2,w2);
            ll v2 = bit_mada.qsum(h1,w1,h2,w2);
            cout << v1 << " " << v2 << endl;
        }

    }
    

}

