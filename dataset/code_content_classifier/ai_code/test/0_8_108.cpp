#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        // Find the maximum strength of each player
        vector<int> max_strength(n);
        for(int i = 0; i < n; i++) {
            max_strength[i] = max(a[i], b[i]);
        }

        // Find the minimum maximum strength among all players
        int min_max_strength = *min_element(max_strength.begin(), max_strength.end());

        // Check if a player can win the tournament based on their strength
        for(int i = 0; i < n; i++) {
            if(max(a[i], b[i]) == min_max_strength) {
                cout << "1";
            } else {
                cout << "0";
            }
        }

        cout << "\n";
    }

    return 0;
}