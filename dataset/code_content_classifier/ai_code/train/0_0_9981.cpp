#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> grid(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "0 ";
        }
        cout << endl;
    }
    cout.flush();

    int q;
    cin >> q;

    while (q--) {
        long long k;
        cin >> k;

        int x = 0, y = 0;

        for (int i = 0; i < 2 * n - 1; i++) {
            if (y < n - 1 && (k - grid[x][y+1]) >= 0) {
                y++;
            } else {
                x++;
            }
            cout << x+1 << " " << y+1 << endl;
            cout.flush();

            k -= grid[x][y];
        }
    }

    return 0;
}