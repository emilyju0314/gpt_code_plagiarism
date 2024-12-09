#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (a[i] + b[i] > x) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}