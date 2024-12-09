#include <iostream>
#include <vector>

using namespace std;

bool isRectangle(vector<vector<int>>& table, int x1, int y1, int x2, int y2) {
    int count_1 = 0;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (table[i][j] == 1) {
                count_1++;
            }
        }
    }
    
    return count_1 == 0 || count_1 == (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    
    int min_changes = INT_MAX;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < m; y2++) {
                    if (isRectangle(table, x1, y1, x2, y2)) {
                        int count_changes = 0;
                        for (int i = x1; i <= x2; i++) {
                            for (int j = y1; j <= y2; j++) {
                                if (table[i][j] == 0) {
                                    count_changes++;
                                }
                            }
                        }
                        if (count_changes <= k) {
                            min_changes = min(min_changes, count_changes);
                        }
                    }
                }
            }
        }
    }
    
    if (min_changes == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_changes << endl;
    }
    
    return 0;
}