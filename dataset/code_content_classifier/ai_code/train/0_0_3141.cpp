#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int sz = 3; sz <= min(n, m); sz += 2) {
                int sum = 0;

                for (int k = 0; k < sz; k++) {
                    sum += table[i][j + k]; 
                    sum += table[i + k][j + sz - 1]; 
                    sum += table[i + sz - 1][j + sz - 1 - k]; 
                    sum += table[i + sz - 1 - k][j]; 
                }

                sum -= table[i][j] + table[i + sz - 1][j] + table[i][j + sz - 1] + table[i + sz - 1][j + sz - 1];

                maxSum = max(maxSum, sum);
            }
        }
    }

    cout << maxSum << endl;

    return 0;
}