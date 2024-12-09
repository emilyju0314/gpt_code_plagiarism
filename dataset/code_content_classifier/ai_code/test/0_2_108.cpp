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
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int min_b = *min_element(b.begin(), b.end());

        vector<int> winners(n);

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i] || a[i] > min_b) {
                winners[i] = 1;
            } else {
                winners[i] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << winners[i];
        }

        cout << endl;
    }

    return 0;
}