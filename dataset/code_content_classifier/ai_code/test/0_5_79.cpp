#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> max_jump(n+1);
    vector<int> slip_distance(n+1);
    
    for(int i = 1; i <= n; i++) {
        cin >> max_jump[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> slip_distance[i];
    }
    
    vector<int> dp(n+1, -1); // Initialize dp table with -1
    
    dp[0] = 0; // Base case
    
    for(int i = 1; i <= n; i++) {
        if(dp[i-1] != -1) {
            dp[i] = i;
        }
        for(int j = i-1; j >= max(0, i - max_jump[i]); j--) {
            if(dp[j] != -1 && j + max_jump[j] >= i) {
                dp[i] = j;
                break;
            }
        }
    }
    
    if(dp[n] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> jumps;
        int current = n;
        while(current != 0) {
            jumps.push_back(current);
            current = dp[current];
        }
        cout << jumps.size()-1 << endl;
        for(int i = jumps.size()-1; i >= 0; i--) {
            cout << jumps[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}