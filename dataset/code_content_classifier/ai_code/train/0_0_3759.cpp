#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> table(n);
    for(int i = 0; i < n; i++) {
        cin >> table[i];
    }

    vector<vector<int>> dp(2*n, vector<int>(2*n, -1));

    function<int(int, int)> dfs = [&](int a, int b) {
        if(a + b == 2*n - 1) {
            return 0;
        }

        if(dp[a][b] != -1) {
            return dp[a][b];
        }

        if(a != b) {
            if(table[a][b] == 'a') {
                if(dfs(a+1, b) == 0) {
                    dp[a][b] = 1;
                    return 1;
                }
                if(b + 1 < 2*n - 1 && dfs(a, b+1) == 0) {
                    dp[a][b] = 1;
                    return 1;
                }
                dp[a][b] = 0;
                return 0;
            } else {
                if(dfs(a+1, b) == 0 || (b + 1 < 2*n - 1 && dfs(a, b+1) == 0)) {
                    dp[a][b] = 0;
                    return 0;
                }
                dp[a][b] = 1;
                return 1;
            }
        }

        if(table[a][b] == 'a') {
            if(dfs(a+1, b) == 0 && dfs(a, b+1) == 0) {
                dp[a][b] = 0;
                return 0;
            }
            dp[a][b] = 1;
            return 1;
        } else {
            if(dfs(a+1, b) == 0 || dfs(a, b+1) == 0) {
                dp[a][b] = 0;
                return 0;
            }
            dp[a][b] = 1;
            return 1;
        }
    };

    if(dfs(0, 0) == 1) {
        cout << "FIRST" << endl;
    } else if(dfs(0, 0) == 0) {
        cout << "SECOND" << endl;
    } else {
        cout << "DRAW" << endl;
    }

    return 0;
}