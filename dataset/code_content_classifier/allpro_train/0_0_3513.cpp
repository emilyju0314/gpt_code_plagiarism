#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<long long> dp(n, 0);
    
    for (int i = 0; i < n; i++) {
        dp[i] = p[i];
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + p[i] - (j == 0 ? 0 : s[j-1]) - c*(i-j-1));
        }
    }
    
    long long max_sold = 0;
    for (int i = 0; i < n; i++) {
        max_sold = max(max_sold, dp[i]);
    }
    
    cout << max_sold << endl;
    
    return 0;
}