#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        bool possible = true;
        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i+1] - heights[i];
            int moves_needed = max(0, diff - k);
            if (m < moves_needed) {
                possible = false;
                break;
            } else {
                m -= moves_needed;
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