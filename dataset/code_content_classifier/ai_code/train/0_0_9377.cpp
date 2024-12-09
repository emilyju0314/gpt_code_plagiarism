#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        bool possible = true;

        for (int i = 1; i < n - 1; i++) {
            int min_height = max(heights[i], heights[i+1] - k + 1);
            if (heights[i-1] + k - 1 < min_height) {
                possible = false;
                break;
            }
            heights[i] = min_height;
        }

        if (heights[0] + k - 1 < heights[1] || heights[n-2] + k - 1 < heights[n-1]) {
            possible = false;
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}