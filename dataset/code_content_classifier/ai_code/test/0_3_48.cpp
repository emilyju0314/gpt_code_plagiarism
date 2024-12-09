#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool sorted = is_sorted(a.begin(), a.end());

        if (sorted) {
            cout << "YES" << endl;
        } else {
            // Check if it is possible to sort using only 3-cycles
            // Count the number of cycles needed to sort the array
            int cycles = 0;
            vector<bool> visited(n, false);
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    cycles++;
                    int j = i;
                    while (!visited[j]) {
                        visited[j] = true;
                        j = a[j] - 1;
                    }
                }
            }

            if (cycles == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}