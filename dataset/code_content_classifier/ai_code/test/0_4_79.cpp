#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    vector<int> b(n+1);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 0; j--) {
            if(dp[j] != -1 && j + a[j] >= i) {
                dp[i] = j;
                break;
            }
        }
    }
    
    if(dp[n] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> jumps;
        int curr = n;
        while(curr > 0) {
            jumps.push_back(curr);
            curr = dp[curr];
        }
        
        cout << jumps.size() << endl;
        for(int i = jumps.size() - 1; i >= 0; i--) {
            cout << jumps[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}