#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> playerTable(n, 0);
        for (int j = 0; j < n; j++) {
            playerTable[j] = j % m; // Distribute players among tables
        }

        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                int minPlayers = n / m;
                int extraPlayers = n % m;
                if (l < extraPlayers) {
                    cout << minPlayers + 1 << " ";
                } else {
                    cout << minPlayers << " ";
                }
                for (int p = 0; p < n; p++) {
                    if (playerTable[p] == l) {
                        cout << p + 1 << " ";
                    }
                }
                cout << endl;
            }
        }

        if (i < t - 1) {
            cout << endl;
        }
    }

    return 0;
}