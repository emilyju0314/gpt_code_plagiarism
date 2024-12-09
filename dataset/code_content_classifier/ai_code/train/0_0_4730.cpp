#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << -1 << endl;
    } else {
        vector<vector<int>> cycles;

        int count = n / 2;
        for (int i = 1; i <= n; i++) {
            cycles.push_back({3, i, (i % n) + 1, (i + count) % n + 1});
            cycles.push_back({3, i, (i + 1) % n + 1, (i + count) % n + 1});
        }

        cout << cycles.size() << endl;
        for (auto cycle : cycles) {
            cout << cycle[0];
            for (int i = 1; i < cycle.size(); i++) {
                cout << " " << cycle[i];
            }
            cout << endl;
        }
    }

    return 0;
}