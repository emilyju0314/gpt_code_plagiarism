#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        vector<int> r(b);
        int total_freeways = 0;

        for (int i = 0; i < b; i++) {
            cin >> r[i];
            total_freeways += r[i];
        }

        if (total_freeways != a + b - 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        int current_algoland = 1;
        int current_berland = 1;

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < r[i]; j++) {
                cout << current_berland << " " << current_algoland << endl;
                current_algoland++;
            }
            current_berland++;
        }
    }

    return 0;
}