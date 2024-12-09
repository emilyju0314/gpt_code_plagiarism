#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long x;
    cin >> x;

    vector<pair<int, int>> tables;

    for (int n = 1; n*n <= x; n++) {
        if (x % n == 0) {
            int m = x / n;
            tables.push_back({n, m});
            if (n != m) {
                tables.push_back({m, n});
            }
        }
    }

    cout << tables.size() << endl;
    for (auto table : tables) {
        cout << table.first << " " << table.second << endl;
    }

    return 0;
}