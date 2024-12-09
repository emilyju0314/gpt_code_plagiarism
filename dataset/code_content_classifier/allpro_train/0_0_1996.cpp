#include <iostream>
#include <string>
#include <vector>

#define MOD 998244353

using namespace std;

int countBeautifulPartitions(string num, int l, int r) {
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int curDigit = num[i-1] - '0';
            for(int k = i - 1; k >= max(0, i - r); k--) {
                int prevSum = stoi(num.substr(k, i - k));
                if(prevSum >= l && curDigit)
                    dp[i][j] = (dp[i][j] + dp[k][j-1]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + dp[n][i]) % MOD;
    }

    return result;
}

int main() {
    string a;
    cin >> a;
    int l, r;
    cin >> l >> r;

    int result = countBeautifulPartitions(a, l, r);
    cout << result << endl;

    return 0;
}