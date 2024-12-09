#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void constructTree(int n, int m, vector<vector<int>>& restrictions) {
    vector<int> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.push_back(i);
    }

    sort(nodes.begin(), nodes.end());

    for (int i = 1; i < n; i++) {
        cout << nodes[i-1] << " " << nodes[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> restrictions(m, vector<int>(3));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> restrictions[j][k];
            }
        }

        constructTree(n, m, restrictions);
    }

    return 0;
}