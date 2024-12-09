#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> lemmings(n);
    for(int i = 0; i < n; i++) {
        cin >> lemmings[i];
    }
    
    vector<int> shields(n);
    int total_pairs = n * (n - 1) / 2;
    
    vector<int> max_protection(total_pairs + 1);
    
    for(int k = 0; k <= total_pairs; k++) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        
        for(int i = 1; i <= k; i++) {
            int left = max(1, i - (n-1)) + 1;
            for(int j = 1; j <= n; j++) {
                for(int l = left; l < i && l < j; l++) {
                    if(dp[l] != -1 && lemmings[j-1] == 0 && shields[l] == 1 && shields[j-1] == 0) {
                        dp[i] = max(dp[i], dp[l] + 1);
                    }
                }
            }
        }
        
        max_protection[k] = dp[k];
        
        if(max_protection[k] == 0) {
            break;
        }
        
        for(int i = 0; i < n; i++) {
            if(lemmings[i] == 1) {
                for(int j = 0; j < n; j++) {
                    if(i > j && lemmings[j] == 0 && shields[j] == 0) {
                        shields[j] = 1;
                        break;
                    } else if(i < j && lemmings[j] == 0 && shields[j] == 0) {
                        shields[j] = 1;
                        break;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i <= total_pairs; i++) {
        cout << max_protection[i] << " ";
    }
    
    return 0;
}