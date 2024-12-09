#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonSubsequence(string s1, string s2, string virus) {
    int n = s1.length();
    int m = s2.length();
    int k = virus.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string result = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result = s1[i-1] + result;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    string res = "";
    int start = 0;
    for (int idx = 0; idx < result.length(); idx++) {
        if (result[idx] != virus[start]) {
            res += result[idx];
        } else {
            start++;
            if (start == k) {
                return res;
            }
        }
    }

    return "0";
}

int main() {
    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;

    string result = longestCommonSubsequence(s1, s2, virus);
    cout << result << endl;

    return 0;
}