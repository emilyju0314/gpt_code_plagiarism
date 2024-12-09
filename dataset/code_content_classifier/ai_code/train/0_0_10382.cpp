#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int D, N;
    cin >> D >> N;
    
    vector<int> temperatures(D);
    vector<vector<int>> clothes(N, vector<int>(3));
    
    for (int i = 0; i < D; i++) {
        cin >> temperatures[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> clothes[i][j];
        }
    }
    
    vector<vector<int>> dp(D, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        if (clothes[i][0] <= temperatures[0] && clothes[i][1] >= temperatures[0]) {
            dp[0][i] = clothes[i][2];
        }
    }
    
    for (int i = 1; i < D; i++) {
        for (int j = 0; j < N; j++) {
            if (clothes[j][0] <= temperatures[i] && clothes[j][1] >= temperatures[i]) {
                for (int k = 0; k < N; k++) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(clothes[j][2] - clothes[k][2]));
                }
            }
        }
    }
    
    int max_diff = 0;
    for (int i = 0; i < N; i++) {
        max_diff = max(max_diff, dp[D-1][i]);
    }
    
    cout << max_diff << endl;
    
    return 0;
}