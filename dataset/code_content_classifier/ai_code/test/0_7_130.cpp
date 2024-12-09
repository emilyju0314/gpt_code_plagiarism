#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> impostors;

        // Find impostors by checking groups of 3 players
        for (int i = 1; i <= n; i += 3) {
            if (impostors.size() >= n/3) break;

            cout << "? " << i << " " << i+1 << " " << i+2 << endl;
            fflush(stdout);

            int res;
            cin >> res;
            if (res == 0) {
                impostors.push_back(i);
                impostors.push_back(i+1);
                impostors.push_back(i+2);
            }
        }

        // Print the result
        cout << "! " << impostors.size() << " ";
        for (int idx : impostors) {
            cout << idx << " ";
        }
        cout << endl;
        fflush(stdout);
    }
    return 0;
}