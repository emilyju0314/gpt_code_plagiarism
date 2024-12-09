#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<long long> shortcuts;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        shortcuts.insert((x << 32) + y);
    }

    vector<string> result;
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;

        if (shortcuts.count((a << 32) + b)) {
            result.push_back("LOSE");
        } else {
            result.push_back("WIN");
        }
    }

    for (string r : result) {
        cout << r << endl;
    }

    return 0;
}