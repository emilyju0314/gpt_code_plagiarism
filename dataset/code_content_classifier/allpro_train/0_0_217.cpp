#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> password(n, 0);
    vector<int> req_panels(k);
    vector<int> operations(l);

    for (int i = 0; i < k; i++) {
        cin >> req_panels[i];
        password[req_panels[i] - 1] = 1; // Setting required panels to ON state
    }

    for (int i = 0; i < l; i++) {
        cin >> operations[i];
    }

    int moves = 0;
    for (int i = 0; i < l; i++) {
        int panel_state = password[operations[i] - 1];
        if (panel_state == 1) {
            // Perform the flip operation
            for (int j = 0; j < operations[i]; j++) {
                password[j] = 1 - password[j]; // Toggle the state of the panel
            }
            moves++;
        }
    }

    bool entered = true;
    for (int i = 0; i < n; i++) {
        if (password[i] != 1) {
            entered = false;
            break;
        }
    }

    if (entered) {
        cout << moves << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}