#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> q(n);

    for (int i = 0; i < n; i++) {
        q[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            q[p[i] - 1] = i + 1;
        } else {
            q[p[i] - 1] = q[p[i - 1] - 1];
        }
    }

    vector<int> count(n + 1, 0);
    for (int i : q) {
        count[i]++;
    }

    bool valid = true;
    for (int c : count) {
        if (c != 1) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << -1 << endl;
    } else {
        for (int i : q) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}