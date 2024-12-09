#include <iostream>
#include <vector>

using namespace std;

int eggDrop(int eggs, long long floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));
    
    for (int i = 1; i <= eggs; i++) {
        for (int j = 1; j <= floors; j++) {
            if (i == 1) {
                dp[i][j] = j;
            } else if (j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;
            }
        }
    }
    
    int minDrops = 0;
    for (int k = 1; k <= floors; k++) {
        if (dp[eggs][k] >= floors) {
            minDrops = k;
            break;
        }
    }
    
    return minDrops;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        long long N;
        int E;
        cin >> N >> E;
        
        cout << eggDrop(E, N) << endl;
    }
    
    return 0;
}