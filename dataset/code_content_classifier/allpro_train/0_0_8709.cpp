#include <iostream>
#include <vector>

using namespace std;

bool canUnlockDoors(int n, int m, vector<int>& doorStatus, vector<vector<int>>& switches) {
    vector<int> doorStatusCopy = doorStatus;

    for (int i = 0; i < (1 << m); i++) {
        vector<bool> switchState(m, false);
        
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                switchState[j] = true;
            }
        }

        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < 2; k++) {
                if (switchState[switches[j][k] - 1]) {
                    count++;
                }
            }
            if (count % 2 != doorStatusCopy[j]) {
                doorStatusCopy[j] = 1 - doorStatusCopy[j];
            }
        }
    }

    for (int door : doorStatusCopy) {
        if (door == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> doorStatus(n);
    for (int i = 0; i < n; i++) {
        cin >> doorStatus[i];
    }

    vector<vector<int>> switches(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> switches[i][0] >> switches[i][1];
    }

    if (canUnlockDoors(n, m, doorStatus, switches)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}