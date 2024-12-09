#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    
    while (true) {
        cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break; // end of input
        }
        
        vector<vector<int>> scores(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> scores[i][j];
            }
        }
        
        vector<int> dp(M, 1);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (scores[i][j] >= scores[i - 1][j]) {
                    dp[j]++;
                } else {
                    dp[j] = 1;
                }
            }
        }
        
        int max_increasing = *max_element(dp.begin(), dp.end());
        cout << max_increasing << endl;
    }

    return 0;
}