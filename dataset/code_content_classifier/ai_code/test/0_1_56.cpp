#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int k, n;
map<int, string> nodes;

int dp[5000][4][4][4][4];

int add(int a, int b) {
    return (a + b) % MOD;
}

int main() {
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int v;
        string s;
        cin >> v >> s;
        nodes[v] = s;
    }

    dp[0][0][0][0][0] = 1;

    for (int i = 1; i < (1 << k); i++) {
        if (nodes.find(i) != nodes.end()) {
            string color = nodes[i];
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    for (int c = 0; c < 4; c++) {
                        for (int d = 0; d < 4; d++) {
                            if (a == b || a == c || a == d || b == c || b == d || c == d || (color == "white" && (a == 0 || b == 0 || c == 0 || d == 0)) || (color == "yellow" && (a == 3 || b == 3 || c == 3 || d == 3)) || (color == "green" && (a == 1 || b == 1 || c == 1 || d == 1)) || (color == "blue" && (a == 2 || b == 2 || c == 2 || d == 2)) || (color == "red" && (a == 1 || b == 1 || c == 1 || d == 1)) || (color == "orange" && (a == 2 || b == 2 || c == 2 || d == 2))) {
                                dp[i][a][b][c][d] = 0;
                            }
                        }
                    }
                }
            }
            continue;
        }

        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                for (int c = 0; c < 4; c++) {
                    for (int d = 0; d < 4; d++) {
                        for (int ap = 0; ap < 4; ap++) {
                            for (int bp = 0; bp < 4; bp++) {
                                dp[i][b][c][d][ap] = add(dp[i][b][c][d][ap], dp[i-1][a][b][c][d]);
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    ans = add(ans, dp[(1 << k) - 1][a][b][c][d]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}