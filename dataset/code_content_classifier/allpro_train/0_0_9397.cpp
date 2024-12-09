#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dollars(n);
    for (int i = 0; i < n; i++) {
        cin >> dollars[i];
    }

    vector<int> result(n, -1);
    int cur_max = 0;
    for (int i = n-1; i >= 0; i--) {
        if (dollars[i] <= cur_max) {
            cur_max++;
            result[i] = cur_max;
        }
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (result[i] == -1) {
            possible = false;
            break;
        }
    }

    if (possible) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}