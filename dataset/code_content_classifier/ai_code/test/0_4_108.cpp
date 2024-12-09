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

        vector<int> a(n), b(n), winners(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int maxA = *max_element(a.begin(), a.end());
        int maxB = *max_element(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            if (a[i] == maxA && b[i] == maxB) {
                winners[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << winners[i];
        }
        cout << endl;
    }

    return 0;
}