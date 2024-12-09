#include <bits/stdc++.h>
using namespace std;
#define VI vector<int>

int main() {
    //ifstream cin("testE.in");
    int n; cin >> n;

    vector<int> x(n, 0), y(n, 0), a(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> a[i];
    
    vector<vector<double>> d(n, vector<double>(n, 0));

    auto getDist = [&] (int i, int j) -> double {
        double ans = sqrt(0.0 + 1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]));
        return ans;
    };
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            d[i][j] = getDist(i, j);

    auto mst = [&] (vector<int> v) {
        int m = v.size();
        vector<double> dist(m, 2e10);
        vector<int> in(m, 0);
        for(int i = 0; i < m; ++i) {
            dist[i] = d[v[i]][v[0]];
        }

        in[0] = 1;
        double ans = 0.0;

        for(int it = 0; it < m - 1; ++it) {
            double minn = 2e10;
            int who = -1;
            for(int i = 0; i < m; ++i)
                if(not in[i] and dist[i] < minn) {
                    minn = dist[i];
                    who = i;
                }
            
            ans += minn;
            in[who] = 1;
            for(int i = 0; i < m; ++i)
                if(not in[i])
                    dist[i] = min(dist[i], d[v[who]][v[i]]);
        }
        
        return ans;
    };
    
    vector<double> costComp((1 << n), 0);

    for(int mask = 1; mask < (1 << n); ++mask) {
        double cost = 0;
        vector<int> sub;
        for(int i = 0; i < n; ++i) {
            if((1 << i) & mask) {
                cost += a[i];
                sub.push_back(i);
            }
        }
        costComp[mask] = (cost - mst(sub)) / (sub.size() + 0.0);
    }
    
    vector<double> dp((1 << n), 0);
    dp[0] = 1e10;

    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int sub = mask; sub > 0; sub = ((sub - 1) & mask)) {
            dp[mask] = max(dp[mask], min(dp[mask - sub], costComp[sub]));
        }
    }

    cout.precision(15);
    cout << dp[(1 << n) - 1] << "\n";
}