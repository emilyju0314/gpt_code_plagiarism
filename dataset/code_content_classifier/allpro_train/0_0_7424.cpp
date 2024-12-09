#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    
    vector<long long> dp(N, 1e18);
    dp[0] = 0;
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + pow(h[i] - h[j], 2) + C);
        }
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}