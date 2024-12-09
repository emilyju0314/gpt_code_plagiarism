#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> bus(n);
    for (int i = 0; i < n; i++) {
        cin >> bus[i];
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (bus[i][0] == 'O' && bus[i][1] == 'O') {
            bus[i][0] = '+';
            bus[i][1] = '+';
            cout << "YES" << endl;
            for (int j = 0; j < n; j++) {
                cout << bus[j] << endl;
            }
            found = true;
            break;
        }
        if (bus[i][3] == 'O' && bus[i][4] == 'O') {
            bus[i][3] = '+';
            bus[i][4] = '+';
            cout << "YES" << endl;
            for (int j = 0; j < n; j++) {
                cout << bus[j] << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "NO" << endl;
    }

    return 0;
}