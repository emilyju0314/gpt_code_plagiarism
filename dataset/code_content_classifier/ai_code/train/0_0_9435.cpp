#include <iostream>
#include <vector>

using namespace std;

int calculateCost(vector<int>& words, int w) {
    int n = words.size();
    vector<int> dp(n, 1000000000); // Initialize with a large number
    vector<int> sum(n);
    sum[0] = words[0];
    dp[0] = (w - sum[0]) * (w - sum[0]);
    
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + words[i];
    }
    
    for (int i = 1; i < n; i++) {
        dp[i] = (w - sum[i]) * (w - sum[i]);
        
        for (int j = i - 1; j >= 0; j--) {
            int cost = (w - (sum[i] - sum[j])) * (w - (sum[i] - sum[j])) + dp[j];
            dp[i] = min(dp[i], cost);
        }
    }
    
    return dp[n-1];
}

int main() {
    int n, w, caseNum = 1;
    
    while (true) {
        cin >> n >> w;
        if (n == 0 && w == 0) break;
        
        vector<int> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        
        int minCost = calculateCost(words, w);
        cout << "Case " << caseNum << ": " << minCost << endl;
        caseNum++;
    }
    
    return 0;
}