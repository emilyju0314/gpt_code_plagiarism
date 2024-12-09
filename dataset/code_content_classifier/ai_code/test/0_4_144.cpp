#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int eachTable = n / m;
    int extraPlayers = n % m;

    int extraTables = m - extraPlayers;
    
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < m; j++) {
            int players = (j < extraTables) ? eachTable : eachTable + 1;
            cout << players;
            for(int p = 0; p < players; p++) {
                int playerNum = j + p * m + 1 + (j < extraTables ? 0 : extraTables);
                cout << " " << playerNum;
            }
            cout << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
        cout << endl; // Separate responses to different sets of inputs
    }

    return 0;
}