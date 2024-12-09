#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int N, M;
vector<vector<int>> conditions;
int dp[305][305][305];

int countWays(int idx, int redCount, int greenCount, int blueCount) {
    if(idx == N + 1) {
        // Check if all conditions are satisfied
        for(auto& c : conditions) {
            int differentColors = 0;
            if(redCount >= c[0]) differentColors++;
            if(greenCount >= c[0]) differentColors++;
            if(blueCount >= c[0]) differentColors++;
            if(differentColors != c[1]) return 0;
        }
        return 1;
    }

    int& ret = dp[idx][redCount][greenCount];
    if(ret != -1) return ret;

    long long ways = 0;
    ways = (ways + countWays(idx + 1, redCount + 1, greenCount, blueCount)) % MOD;
    ways = (ways + countWays(idx + 1, redCount, greenCount + 1, blueCount)) % MOD;
    ways = (ways + countWays(idx + 1, redCount, greenCount, blueCount + 1)) % MOD;

    return ret = ways;
}

int main() {
    cin >> N >> M;
    
    conditions.resize(M, vector<int>(3));
    for(int i = 0; i < M; i++) {
        cin >> conditions[i][0] >> conditions[i][1] >> conditions[i][2];
    }

    memset(dp, -1, sizeof(dp));
    cout << countWays(1, 0, 0, 0) << endl;

    return 0;
}