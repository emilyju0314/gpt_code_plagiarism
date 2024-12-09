#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> households(n);
        vector<int> capacities(n);

        for (int i = 0; i < n; i++) {
            cin >> households[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> capacities[i];
        }

        bool possible = true;
        int remaining = 0, total = households[0];

        for (int i = 0; i < n; i++) {
            remaining = max(0, capacities[i] - (households[i] + remaining));
            if (i < n - 1) {
                total += households[i + 1];
            }
            if (total > capacities[i]) {
                possible = false;
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