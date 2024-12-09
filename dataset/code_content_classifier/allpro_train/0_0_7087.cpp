#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numProblems;
    
    while (cin >> numProblems) {
        vector<int> times(numProblems);
        vector<int> dp(numProblems + 1, 0);
        
        for (int i = 0; i < numProblems; i++) {
            cin >> times[i];
        }
        
        sort(times.begin(), times.end());
        
        dp[1] = times[0];
        
        for (int i = 2; i <= numProblems; i++) {
            dp[i] = min(dp[i-1] + times[i-1], dp[i-2] + times[i-1] + times[i-2]);
        }
        
        cout << dp[numProblems] << endl;
    }
    
    return 0;
}