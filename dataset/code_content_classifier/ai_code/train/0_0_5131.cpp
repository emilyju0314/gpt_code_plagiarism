#include <iostream>
#include <string>
#include <algorithm>

int minOperationsToMakeStringsEqual(std::string a, std::string b) {
    int m = a.size();
    int n = b.size();

    int dp[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
                dp[i][j] = 1 + std::min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        std::string a, b;
        std::cin >> a >> b;

        int minOps = minOperationsToMakeStringsEqual(a, b);
        std::cout << minOps << std::endl;
    }

    return 0;
}