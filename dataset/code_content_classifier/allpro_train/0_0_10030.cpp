#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<pair<int, int>> items(N);
    for(int i = 0; i < N; i++) {
        int weight, value;
        cin >> weight >> value;
        items[i] = make_pair(weight, value);
    }
    
    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= W; j++) {
            if(items[i-1].first <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].first] + items[i-1].second);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[N][W] << endl;
    
    return 0;
}