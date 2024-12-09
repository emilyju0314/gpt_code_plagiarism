#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


template <typename T = i64>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template <typename T = i64>
bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int x, y, z, n, m, s, t;
    cin >> x >> y >> z >> n >> m >> s >> t;
    --s, --t;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    vector<int> c(m), d(m);
    for(int i = 0; i < m; ++i){
        cin >> c[i] >> d[i];
        --c[i], --d[i];
    }
    int num = x + y + z + n + m;
    vector<i64> range(num, MOD);
    range[x + y + z + s] = 0;

    vector<vector<pair<i64, i64>>> edges(num);
    for(int i = 0; i < n; ++i){
        int idx = x + y + z + i;
        int a_idx = a[i];
        int b_idx = b[i] + x;
        edges[idx].emplace_back(a_idx, 0);
        edges[idx].emplace_back(b_idx, 0);
        edges[a_idx].emplace_back(idx, 1);
        edges[b_idx].emplace_back(idx, 1);
    }
    for(int i = 0; i < m; ++i){
        int idx = x + y + z + n + i;
        int a_idx = c[i] + x;
        int b_idx = d[i] + x + y;
        edges[idx].emplace_back(a_idx, 0);
        edges[idx].emplace_back(b_idx, 0);
        edges[a_idx].emplace_back(idx, 1);
        edges[b_idx].emplace_back(idx, 1);
    }

    priority_queue<pair<i64,i64>, vector<pair<i64,i64>>, greater<pair<i64,i64>>> que;
    que.emplace(0, x + y + z + s);
    while(!que.empty()){
        i64 dist, top;
        tie(dist, top) = que.top();
        que.pop();
        if(dist != range[top])
            continue;
        for(auto& p : edges[top]){
            i64 nex = p.first;
            i64 n_dist = dist + p.second;
            if(chmin(range[nex], n_dist))
                que.emplace(range[nex], nex);
        }
    }

    i64 ans = range[x + y + z + n + t];
    if(ans == MOD){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}

