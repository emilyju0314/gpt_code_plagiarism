#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> intervals(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int l, r;
            cin >> l >> r;

            for (int x = l - 1; x <= r - 1; x++) {
                intervals[i][x] = 1;
            }
        }
    }

    long long maxQuality = 0;

    for (int j = 0; j < m; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += intervals[i][j];
        }
        maxQuality += colSum * colSum;
    }

    cout << maxQuality << endl;

    return 0;
}