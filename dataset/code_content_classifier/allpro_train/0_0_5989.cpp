#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int max_jokers = min(m, n/k);
        int other_players_max_jokers = (m - max_jokers + k - 2) / (k - 1);

        cout << max_jokers - other_players_max_jokers << endl;
    }

    return 0;
}