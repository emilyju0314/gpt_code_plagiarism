#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

unordered_map<int, string> buttonMap = {
    {1, "aiueo"},
    {2, "kakikukeko"},
    {5, "What is it?"},
    {6, "hahifuheho"},
    {7, "mamimumemo"},
    {8, "yayuyo"},
    {9, "Larry Lero"},
    {0, "Won"}
};

int getNumCombinations(string input) {
    vector<int> dp(input.length() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= input.length(); i++) {
        for (int j = 1; j <= 10 && i - j >= 0; j++) {
            if (input[i-1] == '0' && j != 1) break;
            if (buttonMap.find(input[i-1] - '0') != buttonMap.end()) {
                for (char c : buttonMap[input[i-1] - '0']) {
                    dp[i] = (dp[i] + dp[i-j]) % MOD;
                }
            }
        }
    }

    return dp[input.length()];
}

int main() {
    string input;
    while (getline(cin, input) && input != "#") {
        int result = getNumCombinations(input);
        cout << result << endl;
    }
    return 0;
}