#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isBlocked(int x, int y, vector<pair<pair<int, int>, pair<int, int>>> blockedSections) {
    for (auto section : blockedSections) {
        if ((x >= section.first.first && x <= section.second.first) && (y >= section.first.second && y <= section.second.second)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int gx, gy;
        cin >> gx >> gy;

        int p;
        cin >> p;

        vector<pair<pair<int, int>, pair<int, int>>> blockedSections;
        for (int i = 0; i < p; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            blockedSections.push_back({{x1, y1}, {x2, y2}});
        }

        vector<vector<int>> dp(gx+1, vector<int>(gy+1, 0));
        dp[0][0] = 1;

        for (int i = 0; i <= gx; i++) {
            for (int j = 0; j <= gy; j++) {
                if (isBlocked(i, j, blockedSections)) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }

        if (dp[gx][gy] == 0) {
            cout << "Miserable Hokusai!" << endl;
        } else {
            cout << dp[gx][gy] << endl;
        }
    }
    return 0;
}