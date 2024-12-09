#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(2);
        for (int i = 0; i < 2; i++) {
            cin >> grid[i];
        }

        // Check if it is possible to reach cell (2, n)
        bool possible = false;
        for (int i = 0; i < n - 1; i++) {
            if (grid[1][i] == '0' && grid[0][i+1] == '0') {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}