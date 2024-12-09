#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read input
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arrays(n);

    // Process queries
    for (int i = 0; i < q; i++) {
        int query, t, x;
        cin >> query >> t;

        if (query == 0) {
            cin >> x;
            arrays[t].push_back(x);
        } else if (query == 1) {
            for (int element : arrays[t]) {
                cout << element << " ";
            }
            cout << endl;
        } else if (query == 2) {
            arrays[t].clear();
        }
    }

    return 0;
}