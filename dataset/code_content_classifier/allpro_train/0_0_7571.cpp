#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    vector<pair<int, int>> operations;

    for (int i = 0; i < n; i++) {
        if ((x[i] % 2) != (y[i] % 2)) {
            cout << -1 << endl;
            return 0;
        }
        while (x[i] > y[i]) {
            int j = i+1;
            while ((x[j] % 2) == (y[j] % 2)) {
                j++;
            }
            for (int k = j; k > i; k--) {
                x[k] ^= x[k-1];
                operations.push_back({k, k});
            }
        }
    }

    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}