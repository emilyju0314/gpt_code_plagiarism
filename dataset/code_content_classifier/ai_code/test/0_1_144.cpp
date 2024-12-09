#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int players_per_table = (n + m - 1) / m;
        int remaining_players = n % m;

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < m; j++) {
                int players_this_table = (j < remaining_players) ? players_per_table : players_per_table - 1;
                cout << players_this_table << " ";
                int start = j * players_per_table + min(j, remaining_players);
                for(int p = 0; p < players_this_table; p++) {
                    cout << (start + p + 1) << " ";
                }
                cout << endl;
            }
        }
        if(t > 0) {
            cout << endl;
        }
    }

    return 0;
}