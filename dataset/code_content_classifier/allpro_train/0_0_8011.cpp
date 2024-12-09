#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define MOD 1000000007

std::vector<std::vector<int>> dp;
std::string topRow, bottomRow, word;

int countDistinctSolutions(int k, int i, int j) {
    if (k == word.size()) return 1;
    if (dp[k][i] != -1) return dp[k][i];

    int count = 0;
    if (topRow[i] == word[k]) {
        for (int x = j - 1; x <= j + 1; x++) {
            if (x >= 0 && x < bottomRow.size() && bottomRow[x] == word[k]) {
                count = (count + countDistinctSolutions(k + 1, x, i)) % MOD;
            }
        }
    }
    dp[k][i] = count;
    return count;
}

int main() {
    std::cin >> topRow >> bottomRow >> word;

    dp.assign(word.size(), std::vector<int>(topRow.size(), -1));

    int ans = 0;
    for (int i = 0; i < topRow.size(); i++) {
        if (topRow[i] == word[0]) {
            ans = (ans + countDistinctSolutions(1, i, -1)) % MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}