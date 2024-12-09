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
    int currentValue = 1;
    vector<int> valueMapping(1e9 + 1);

    for (int i = 0; i < sortedValues.size(); i++) {
        if (valueMapping[sortedValues[i]] == 0) {
            valueMapping[sortedValues[i]] = currentValue;
            currentValue++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << valueMapping[table[i][j]] << " ";
        }
        cout << endl;
    }

    return 0;
}