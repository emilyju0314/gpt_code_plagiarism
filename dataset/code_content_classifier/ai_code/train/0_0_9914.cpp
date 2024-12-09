#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<int>> matrix(n, vector<int>(m));
    vector<long long> rowSum(n, 0), colSum(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    sort(rowSum.begin(), rowSum.end());
    sort(colSum.begin(), colSum.end());

    long long maxPleasure = 0;

    for (int i = 0; i <= k; i++) {
        long long currPleasure = 0;
        currPleasure += (long long)i * rowSum.back();
        currPleasure += (long long)(k - i) * colSum.back();
        maxPleasure = max(maxPleasure, currPleasure);
        
        rowSum.back() -= m * p;
        colSum.back() -= n * p;
        if (rowSum.back() < rowSum.front()) {
            rowSum.pop_back();
        }
        if (colSum.back() < colSum.front()) {
            colSum.pop_back();
        }
    }

    cout << maxPleasure << endl;

    return 0;
}