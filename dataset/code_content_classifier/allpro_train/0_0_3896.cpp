#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

long long calculateExpression(string exp) {
    vector<pair<char, long long>> tokens;
    long long currNum = 0;
    char currOp = '+';

    for (char c : exp) {
        if (isdigit(c)) {
            currNum = currNum * 10 + (c - '0');
        } else {
            if (currOp == '+') {
                tokens.emplace_back('+', currNum);
            } else {
                long long prevNum = tokens.back().second;
                tokens.pop_back();
                tokens.emplace_back('*', prevNum * currNum);
            }
            currNum = 0;
            currOp = c;
        }
    }

    if (currOp == '+') {
        tokens.emplace_back('+', currNum);
    } else {
        long long prevNum = tokens.back().second;
        tokens.pop_back();
        tokens.emplace_back('*', prevNum * currNum);
    }

    long long result = 0;
    for (auto& token : tokens) {
        if (token.first == '+') {
            result += token.second;
        } else {
            result *= token.second;
        }
    }

    return result;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    vector<vector<long long>> dp(H, vector<long long>(W, INT_MIN));
    dp[0][0] = (isdigit(grid[0][0])) ? grid[0][0] - '0' : 1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i + 1 < H) {
                if (isdigit(grid[i + 1][j])) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (grid[i + 1][j] - '0'));
                } else {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] * 1);
                }
            }
            if (j + 1 < W) {
                if (isdigit(grid[i][j + 1])) {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (grid[i][j + 1] - '0'));
                } else {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] * 1);
                }
            }
        }
    }

    cout << ((dp[H - 1][W - 1] >= 0 && dp[H - 1][W - 1] <= 1e15) ? dp[H - 1][W - 1] : -1) << endl;

    return 0;
}