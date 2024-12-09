#include <iostream>
#include <vector>

using namespace std;

int countDressPatterns(vector<vector<char>>& fabric) {
    int n = fabric.size();
    int m = fabric[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; i + k - 1 < n && j + k - 1 < m; k++) {
                char color = fabric[i][j];

                bool validPattern = true;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        if (fabric[x][y] != color) {
                            validPattern = false;
                            break;
                        }
                    }
                    if (!validPattern) break;
                }

                if (validPattern) {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> fabric(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> fabric[i][j];
        }
    }

    int ways = countDressPatterns(fabric);
    cout << ways << endl;

    return 0;
}