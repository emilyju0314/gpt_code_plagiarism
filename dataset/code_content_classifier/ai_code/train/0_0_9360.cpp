#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, s;

bool check(double diameter) {
    double totalSum = 0, maxDist = 0;
    for (int i = 1; i <= n; i++) {
        int sz = adj[i].size();
        if (sz == 1) continue;
        
        double sum = 0;
        for (auto v : adj[i]) {
            if (adj[v].size() == 1) continue;
            double dist = diameter - 1;
            sum += dist;
            maxDist = max(maxDist, dist);
        }
        totalSum += sum;
    }
    
    return totalSum <= s && maxDist <= diameter;
}

int main() {
    cin >> n >> s;
    adj.resize(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    double low = 0, high = s, ans;
    while (high - low > 1e-9) {
        double mid = (low + high) / 2;
        
        if (check(mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    
    cout << fixed << setprecision(9) << ans << "\n";
    
    return 0;
}