#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> animals(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> animals[i][j];
        }
    }

    int maxSum = 0;

    for(int mask = 0; mask < (1 << k); mask++) {
        if(__builtin_popcount(mask) != k) continue;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= m-k; j++) {
                int tempSum = 0;
                for(int p = 0; p < k; p++) {
                    if((mask & (1 << p)) != 0) {
                        tempSum += animals[i][j + p];
                    }
                }
                sum += tempSum;
            }
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}