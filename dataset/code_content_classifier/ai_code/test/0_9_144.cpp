#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> schedule(k, vector<int>(m));
        int curPlayer = 1;

        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                if (curPlayer <= n) {
                    schedule[j][l] = curPlayer;
                    curPlayer++;
                }
            }
        }
        
        int bigTableSize = (n + m - 1) / m; // Ceiling division
        int curBigTable = 0;

        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                if (l < bigTableSize) {
                    cout << bigTableSize << " " << schedule[j][l] << " ";
                } else {
                    cout << (n / m) << " " << schedule[j][l] << " ";
                }
            }
            cout << endl;
            curBigTable = 1 - curBigTable; // Alternate between big and small tables
        }
        cout << endl;
    }

    return 0;
}