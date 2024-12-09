#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
template <typename T> T inf;
template <> const int inf<int> = 1e9;
template <> const ll inf<ll> = 1e18;
 
int main() {
    int N, H, W;
    cin >> N >> H >> W;
    vector<int> imos(N * (W + 1));
    for(int i = 0; i < N; ++i) {
        int x; cin >> x;
        int p = i * W + (i & 1 ? -x : x);
        p = max(0, min(p, W * (N - 1)));
        for(int i = 0; i < W; ++i) {
            imos[i + p]++;
        }
    }
    int cnt = 0;
    for(int i = 0; i < N * W; ++i) {
        cnt += imos[i] == 0;
    }
    cout << cnt * H << endl;
}

