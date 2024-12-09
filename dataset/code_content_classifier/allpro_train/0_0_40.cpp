#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> bulbs(m + 1, false);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int bulb;
            cin >> bulb;
            bulbs[bulb] = true;
        }
    }

    bool allOn = true;
    for (int i = 1; i <= m; i++) {
        if (!bulbs[i]) {
            allOn = false;
            break;
        }
    }

    if (allOn) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}