#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        int playersPerTable = n/m;
        int bigTables = n%m;
        int smallTables = m - bigTables;

        for (int j = 0; j < k; j++) {
            int smallTablePlayers = 0, bigTablePlayers = 0;
            for (int p = 0; p < m; p++) {
                if (p < smallTables) {
                    cout << playersPerTable << " ";
                    for (int x = 0; x < playersPerTable; x++) {
                        cout << smallTablePlayers + 1 << " ";
                        smallTablePlayers++;
                    }
                    cout << endl;
                } else {
                    cout << playersPerTable + 1 << " ";
                    for (int x = 0; x < playersPerTable + 1; x++) {
                        cout << bigTablePlayers + 1 << " ";
                        bigTablePlayers++;
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
    }

    return 0;
}