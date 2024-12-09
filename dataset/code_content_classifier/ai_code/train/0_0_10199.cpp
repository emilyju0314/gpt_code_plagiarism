#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> dp(2 * N + 1, 0);
    dp[1] = 1;

    // Dynamic programming to calculate number of possible sets
    for(int i = 1; i < N; i++){
        vector<int> tmp(2 * N + 1, 0);
        for(int j = 1; j <= 2 * N; j++){
            if(dp[j] != 0){
                int nj = (j - 2 + N) % N + 1;
                if(nj >= 1 && nj <= N){
                    tmp[nj] += dp[j];
                    tmp[nj] %= M;
                }

                nj = (j + K) % N + 1;
                if(nj >= 1 && nj <= N){
                    tmp[nj] += dp[j];
                    tmp[nj] %= M;
                }
            }
        }
        dp = tmp;
    }

    int result = accumulate(dp.begin() + 1, dp.end(), 0);
    cout << result % M << endl;

    return 0;
}