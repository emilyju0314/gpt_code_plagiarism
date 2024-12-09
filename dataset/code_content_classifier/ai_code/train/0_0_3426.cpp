#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> plates(n);
    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    vector<pair<int, int>> operations;
    vector<int> intermediary_stack;
    vector<int> dryer_stack;

    for (int i = 0; i < a; i++) {
        intermediary_stack.push_back(plates[i]);
        operations.push_back({1, 1});
    }

    for (int i = a - 1; i >= 0; i--) {
        dryer_stack.push_back(intermediary_stack[i]);
        operations.push_back({2, 1});
    }

    for (int i = a; i < n; i++) {
        if (!intermediary_stack.empty() && intermediary_stack.back() == plates[i]) {
            dryer_stack.push_back(intermediary_stack.back());
            intermediary_stack.pop_back();
            operations.push_back({2, 1});
        } else {
            intermediary_stack.push_back(plates[i]);
            operations.push_back({1, 1});
        }
    }

    if (dryer_stack.size() == n) {
        cout << "YES" << endl;
        cout << operations.size() << endl;
        for (auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}