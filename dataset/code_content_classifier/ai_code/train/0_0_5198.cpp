#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Quest {
    int a, b;
    double p;
};

double expectedValue(int n, long long t, vector<Quest>& quests) {
    vector<vector<double>> dp(n+1, vector<double>(101, 0.0));
    
    for(int i = 1; i <= n; i++) {
        Quest q = quests[i-1];
        for(int j = 0; j <= t; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            for(int k = 0; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-k] + q.a + (1.0 - pow(1.0 - q.p, k)) * q.b);
            }
        }
    }
    
    return dp[n][t];
}

int main() {
    int n;
    long long t;
    cin >> n >> t;
    
    vector<Quest> quests(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        double p;
        cin >> a >> b >> p;
        quests[i] = {a, b, p};
    }
    
    double result = expectedValue(n, t, quests);
    cout << fixed << setprecision(15) << result << endl;
    
    return 0;
}