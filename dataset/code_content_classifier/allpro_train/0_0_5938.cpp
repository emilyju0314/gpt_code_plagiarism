#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> notes(n);
    for(int i = 0; i < n; i++) {
        cin >> notes[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            dp[i][j] = 1;
            for(int k = 0; k < i; k++) {
                if(abs(notes[i] - notes[k]) == 1 || abs(notes[i] - notes[k]) == 6) {
                    dp[i][j] = max(dp[i][j], dp[k][j-1] + 1);
                }
            }
        }
    }
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, dp[i][3]);
    }
    
    cout << result << endl;
    
    return 0;
}