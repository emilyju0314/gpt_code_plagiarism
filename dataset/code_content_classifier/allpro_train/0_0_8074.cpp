#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, q;
    cin >> k;
    vector<int> F(6);
    for(int i = 0; i < 6; i++) {
        cin >> F[i];
    }
    
    cin >> q;
    
    vector<int> dp(1000001, -1);
    dp[0] = 0;
    
    for(int i = 1; i <= 9; i++) {
        for(int j = i; j < 1000001; j++) {
            if(dp[j - i] != -1) {
                dp[j] = max(dp[j], dp[j - i] + F[(i - 1) % 3]);
            }
        }
    }
    
    int n;
    for(int l = 0; l < q; l++) {
        cin >> n;
        long long ans = 0;
        while(n > 0) {
            ans = max(ans, (long long)dp[n % 1000000]);
            n /= 10;
        }
        cout << ans << "\n";
    }
    
    return 0;
}