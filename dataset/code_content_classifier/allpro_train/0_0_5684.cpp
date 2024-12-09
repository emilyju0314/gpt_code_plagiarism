#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<string> changes;

    // Try to find a cycle by increasing each parameter by 1
    bool cycle = true;
    for (int i = 0; i < m; i++) {
        int diff = (a[i] - b[i]) % 2;
        if (diff != 0) {
            cycle = false;
            break;
        }
        int num_changes = (a[i] - b[i]) / 2;
        for (int j = 0; j < abs(num_changes); j++) {
            if (num_changes > 0) {
                changes.push_back("inc " + to_string(i+1));
            } else {
                changes.push_back("dec " + to_string(i+1));
            }
        }
    }

    if (cycle) {
        cout << "Cycle" << endl;
        for (string change : changes) {
            cout << change << endl;
        }
    } else {
        // Try to find a path by increasing each parameter by 1 except the last one
        changes.clear();
        for (int i = 0; i < m-1; i++) {
            if (b[i] < a[i]) {
                changes.push_back("inc " + to_string(i+1));
                b[i]++;
            } else if (b[i] > a[i]) {
                changes.push_back("dec " + to_string(i+1));
                b[i]--;
            }
        }

        bool path = true;
        if (b[m-1] < a[m-1]) {
            path = false;
        }

        if (path) {
            cout << "Path" << endl;
            for (string change : changes) {
                cout << change << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}