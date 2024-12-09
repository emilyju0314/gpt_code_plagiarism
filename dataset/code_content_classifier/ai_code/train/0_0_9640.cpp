#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        bool possible = true;
        vector<char> direction(n);
        fill(direction.begin(), direction.end(), ' ');

        int leftMost = 0, rightMost = 0;
        for (int i = 0; i < n; i++) {
            if (i - p[i] > leftMost) {
                leftMost = i - p[i];
                direction[i] = 'L';
            }
            if (i + p[i] < rightMost) {
                rightMost = i + p[i];
                direction[i] = 'R';
            }
        }

        for (int i = 0; i < n; i++) {
            if (direction[i] == ' ') {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << direction[i];
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}