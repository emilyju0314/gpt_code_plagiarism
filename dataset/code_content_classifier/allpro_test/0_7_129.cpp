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

        int operations = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > i + 1) {
                operations = -1;
                break;
            }
            operations = max(operations, i + 1 - a[i]);
        }

        cout << operations << endl;
    }

    return 0;
}