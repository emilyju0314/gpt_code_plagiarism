#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    vector<string> goodMatrix(n, string(n, '0'));

    for (int i = 0; i < n; i++) {
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                goodMatrix[i][idx++] = '1';
            }
        }
        for (int j = idx; j < n; j++) {
            goodMatrix[i][j] = '0';
        }
    }

    vector<string> sortedMatrix = matrix;
    sort(sortedMatrix.begin(), sortedMatrix.end());

    if (sortedMatrix == goodMatrix) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << goodMatrix[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}