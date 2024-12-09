#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> black(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                black[x-1][y-1] = true;
            }
        }
    }

    int total_cost = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (black[x][y]) {
                total_cost++;
            }
        }
    }

    cout << n*n - total_cost << endl;

    return 0;
}