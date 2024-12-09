#include <iostream>
#include <vector>

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

        vector<bool> visited(n);
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int curr = i;
                vector<int> cycle;
                while (!visited[curr]) {
                    visited[curr] = true;
                    cycle.push_back(curr);
                    curr = a[curr] - 1;
                }

                bool sorted = true;
                for (int j = 1; j < cycle.size(); j++) {
                    if (a[cycle[j-1]] > a[cycle[j]]) {
                        sorted = false;
                        break;
                    }
                }

                if (!sorted) {
                    possible = false;
                    break;
                }
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