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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int minOps = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > i + 1) {
                minOps = -1;
                break;
            } else {
                minOps = max(minOps, i + 1 - a[i]);
            }
        }

        cout << minOps << endl;
    }

    return 0;
}