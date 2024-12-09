#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    string s;
    cin >> s;
    
    vector<int> dp(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + a;
        
        for(int j = i-1; j >= 1; j--) {
            string sub = s.substr(j-1, i-j+1);
            if(s.substr(0, j).find(sub) != string::npos) {
                dp[i] = min(dp[i], dp[j-1] + b);
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}