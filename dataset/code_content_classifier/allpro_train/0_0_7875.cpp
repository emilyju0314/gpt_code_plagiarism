#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<pair<int, int>> books(N);
        int total_read_time = 0;
        int total_write_time = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> books[i].first >> books[i].second;
            total_read_time += books[i].first;
            total_write_time += books[i].second;
        }
        
        int max_read_time = 0;
        vector<vector<int>> dp(N+1, vector<int>(total_read_time/2+1, 1e9));
        dp[0][0] = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= total_read_time/2; j++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                if (j + books[i].first <= total_read_time/2) {
                    dp[i+1][j+books[i].first] = min(dp[i+1][j+books[i].first], dp[i][j] + books[i].second);
                    max_read_time = max(max_read_time, j+books[i].first);
                }
            }
        }
        
        cout << max(total_read_time - max_read_time, total_write_time) << endl;
    }
    
    return 0;
}