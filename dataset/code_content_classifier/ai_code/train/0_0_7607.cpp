#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxTrainLength(string garageS, string garageT) {
    int lengthS = garageS.length();
    int lengthT = garageT.length();

    vector<vector<int>> dp(lengthS + 1, vector<int>(lengthT + 1, 0));

    for (int i = 0; i <= lengthS; i++) {
        for (int j = 0; j <= lengthT; j++) {
            if (i != 0 && j != 0) {
                if (garageS[i - 1] == garageT[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    return dp[lengthS][lengthT] * 2;
}

int main() {
    int M, N;
    string S, T;

    cin >> M >> N;
    cin >> S >> T;

    int result = maxTrainLength(S, T);
    cout << result << endl;

    return 0;
}