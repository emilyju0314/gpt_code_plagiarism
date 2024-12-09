#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> targets(n);
    for (int i = 0; i < n; i++) {
        cin >> targets[i];
    }

    int totalTargets = 0;
    for (int i = 0; i < n; i++) {
        totalTargets += targets[i];
    }

    if (totalTargets > 2 * n) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> result;
    for (int i = 0; i < n; i++) {
        if (targets[i] == 0) continue;

        if (targets[i] == 1) {
            result.push_back({i+1, i+1});
        } else if (targets[i] == 2) {
            if (i < n-1 && targets[i+1] > 0) {
                result.push_back({i+1, i+2});
            } else {
                result.push_back({i+1, i+1});
            }
        } else {
            if (i < n-2 && targets[i+1] > 0 && targets[i+2] > 0) {
                result.push_back({i+1, i+2});
                result.push_back({i+1, i+3});
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << result.size() << endl;
    for (auto p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}