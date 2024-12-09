#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> schedule(k, vector<int>(m+1));
        int cnt = 1;

        for (int i = 0; i < k; i++) {
            int players = n / m + (n % m >= (i+1) ? 1 : 0);
            cout << players;
            for (int j = 0; j < players; j++) {
                cout << " " << cnt++;
            }
            cout << endl;
        }

        cout << endl; // Output an additional blank line after each test case
    }

    return 0;
}