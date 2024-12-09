#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<int> sortedValues;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sortedValues.push_back(table[i][j]);
        }
    }

    sort(sortedValues.begin(), sortedValues.end());
    

    vector<vector<int>> compressedTable(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int index = lower_bound(sortedValues.begin(), sortedValues.end(), table[i][j]) - sortedValues.begin();
            compressedTable[i][j] = index + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << compressedTable[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}