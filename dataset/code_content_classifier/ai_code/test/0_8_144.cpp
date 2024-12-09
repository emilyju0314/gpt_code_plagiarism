#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int numBigTables = n % m;
        int numSmallTables = m - numBigTables;

        for(int i = 0; i < k; i++) {
            vector<vector<int>> tables(m);
            int playerIndex = 1;

            for(int j = 0; j < numBigTables; j++) {
                tables[j].push_back(playerIndex++);
            }

            for(int j = numBigTables; j < m; j++) {
                tables[j].push_back(playerIndex++);
            }

            for(int j = 0; j < m; j++) {
                int tableSize = tables[j].size();
                cout << tableSize << " ";
                for(int idx : tables[j]) {
                    cout << idx << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }

    return 0;
}