#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> operations;

        for (int i = 2; i < n; ++i) {
            operations.push_back({i, n});
        }

        for (int i = n - 1; i > 2; --i) {
            operations.push_back({i, 2});
        }

        cout << operations.size() << endl;

        for (auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }

    return 0;
}