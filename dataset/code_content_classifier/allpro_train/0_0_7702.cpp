#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<string, int> elementToIndex;
    vector<string> elements(N);
    for (int i = 0; i < N; i++) {
        string element;
        cin >> element;
        elements[i] = element;
        elementToIndex[element] = i;
    }

    vector<vector<bool>> compatible(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        string p, q;
        cin >> p >> q;
        compatible[elementToIndex[p]][elementToIndex[q]] = true;
        compatible[elementToIndex[q]][elementToIndex[p]] = true;
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    int totalCombinations = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (compatible[i][j]) {
                for (int k = 0; k < N; k++) {
                    if (compatible[j][k] && i != k) {
                        dp[i][k] = 1;
                        totalCombinations++;
                    }
                }
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][k] && dp[k][j] && i != j) {
                    if (!dp[i][j] || dp[i][j] < dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        totalCombinations++;
                    }
                }
            }
        }
    }

    cout << totalCombinations << endl;

    return 0;
}