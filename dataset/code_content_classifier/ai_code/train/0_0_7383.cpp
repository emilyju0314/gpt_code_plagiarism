#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int diff = 0;
        vector<pair<int, int>> operations;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (a[i] < b[i]) {
                    diff = b[i] - a[i];
                    for (int j = 0; j < n; j++) {
                        if (a[j] > b[j]) {
                            int dec = min(a[j] - b[j], diff);
                            a[j] -= dec;
                            a[i] += dec;
                            diff -= dec;
                            operations.push_back({j + 1, i + 1});
                            if (diff == 0) break;
                        }
                    }
                }
                if (diff > 0) {
                    cout << "-1\n";
                    break;
                }
            }
        }

        if (diff == 0) {
            cout << operations.size() << endl;
            for (auto& op : operations) {
                cout << op.first << " " << op.second << endl;
            }
        }
    }

    return 0;
}