#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> initial_state(n);
    vector<string> desired_state(n);

    for (int i = 0; i < n; i++) {
        cin >> initial_state[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> desired_state[i];
    }

    string magic_bar;
    cin >> magic_bar;

    vector<string> instructions;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (initial_state[i] != desired_state[i]) {
            count++;
            instructions.push_back("row " + to_string(i));
        }
    }

    for (int i = 0; i < n; i++) {
        int same_count = 0;
        for (int j = 0; j < n; j++) {
            if (initial_state[j][i] == desired_state[j][i]) {
                same_count++;
            }
        }
        if (same_count != n) {
            count++;
            instructions.push_back("col " + to_string(i));
        }
    }

    if (count == 0) {
        cout << 0 << endl;
    } else if (count > 0) {
        cout << count << endl;
        for (string instruction : instructions) {
            cout << instruction << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}