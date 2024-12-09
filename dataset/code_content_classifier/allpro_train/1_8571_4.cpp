#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N, M;
vector<ll> A, B;
set<ll> searched;
map<ll, ll> mp;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += A[i];
    ans *= M;
    for(int i = 0; i < M; i++) {
        ll mod = B[i];
        if(searched.find(mod) != searched.end()) {
            ans -= mp[mod];
            continue;
        }
        searched.insert(mod);
        ll nowval = 0;
        for(ll j = 1; j * mod <= A.back(); j++) {
            auto itr = lower_bound(A.begin(), A.end(), j * mod);
            ll factor = distance(itr, A.end());
            //cerr << mod << " " << j << " " << factor << endl;
            nowval += factor;
        }
        mp[mod] = nowval * mod;
        ans -= nowval * mod;
    }
    cout << ans << endl;
    return 0;
}

