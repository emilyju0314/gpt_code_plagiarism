#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, k;
int a[101][101], imp[101][101], dp[101][6561], trace[101][6561], res[101][101];

int dfs(int pos, int state) {
    if (dp[pos][state] != -1) return dp[pos][state];

    if (pos == k) return 0;
    
    int x = imp[pos][0], y = imp[pos][1];
    int res = INT_MAX;

    if (state % 3 == 0) res = dfs(pos + 1, state / 3);
    else if (state % 3 == 1) res = a[x][y] + dfs(pos + 1, state / 3);
    else {
        for (int i = 0; i < pos; i++) {
            if (state % 3 == 2) {
                if (imp[i][0] == x || imp[i][1] == y) {
                    int x0 = imp[i][0], y0 = imp[i][1];
                    int cost = a[x][y] * abs(x - x0 + y - y0);
                    int temp = cost + dfs(pos + 1, state / 3);
                    if (temp < res) {
                        res = temp;
                        trace[pos][state] = i;
                    }
                }
            }
        }
    }

    return dp[pos][state] = res;
}

void printGrid(int pos, int state) {
    if (pos == k) return;

    if (state % 3 == 0) printGrid(pos + 1, state / 3);
    else if (state % 3 == 1) {
        int x = imp[pos][0], y = imp[pos][1];
        res[x][y] = 1;
        printGrid(pos + 1, state / 3);
    } else {
        int prev = trace[pos][state];
        int x = imp[pos][0], y = imp[pos][1];
        int x0 = imp[prev][0], y0 = imp[prev][1];

        if (x == x0) {
            for (int i = min(y, y0); i <= max(y, y0); i++) {
                res[x][i] = 1;
            }
        } else {
            for (int i = min(x, x0); i <= max(x, x0); i++) {
                res[i][y] = 1;
            }
        }

        printGrid(pos + 1, state / 3);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        imp[i][0] = x;
        imp[i][1] = y;
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, pow(3, k) - 1) << endl;

    printGrid(0, pow(3, k) - 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (res[i][j] == 1 ? "X" : ".");
        }
        cout << endl;
    }

    return 0;
}