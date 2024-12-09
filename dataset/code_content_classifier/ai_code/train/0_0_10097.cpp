#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPermutation(vector<vector<int>>& table) {
    for(auto row : table) {
        sort(row.begin(), row.end());
        if(row != vector<int>(row.size(), 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    if(checkPermutation(table)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}