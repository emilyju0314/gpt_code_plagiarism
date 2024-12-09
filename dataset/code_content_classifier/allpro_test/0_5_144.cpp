#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int players_per_table_lower = n / m;
        int players_per_table_upper = n % m;

        for(int i = 0; i < k; i++) {
            int remaining_players = n;
            for(int j = 0; j < m; j++) {
                int players_at_table = (j < players_per_table_upper) ? players_per_table_lower + 1 : players_per_table_lower;

                cout << players_at_table;
                for(int p = 0; p < players_at_table; p++) {
                    cout << " " << (p*m + (j+1));
                }
                cout << endl;

                remaining_players -= players_at_table;
            }
        }
        if(t > 0) {
            cout << endl; // Output extra line to separate responses
        }
    }

    return 0;
}