#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> jewels(N);
    vector<vector<int>> colors(K+1);
    for(int i=0; i<N; i++) {
        cin >> jewels[i].first >> jewels[i].second;
        colors[jewels[i].first].push_back(jewels[i].second);
    }
    
    for(int i=1; i<=K; i++) {
        sort(colors[i].begin(), colors[i].end(), greater<int>());
    }
    
    vector<long long> prefix_sum(N+1, 0);
    for(int i=1; i<=K; i++) {
        for(int j=0; j<colors[i].size(); j++) {
            prefix_sum[j+1] = prefix_sum[j] + colors[i][j];
        }
    }
    
    for(int i=1; i<=N; i++) {
        long long ans = 0;
        for(int j=1; j<=K; j++) {
            if(i-2*j < 0) continue;
            ans = max(ans, prefix_sum[j] + prefix_sum[i-2*j]);
        }
        cout << (ans == 0 ? -1 : ans) << endl;
    }
    
    return 0;
}