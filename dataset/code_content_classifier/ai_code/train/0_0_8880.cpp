#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> topResults(n);
    for (int i = 0; i < n; i++) {
        cin >> topResults[i];
    }

    vector<vector<char>> table(m, vector<char>(m, 'D'));

    sort(topResults.begin(), topResults.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        if (topResults[i] >= m) {
            cout << "no" << endl;
            return 0;
        }
        for (int j = 0; j < topResults[i]; j++) {
            table[i][j] = 'W';
            table[j][i] = 'L';
        }
        for (int j = topResults[i]; j < m-1; j++) {
            table[j][i] = 'W';
            table[i][j] = 'L';
        }
    }

    cout << "yes" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}