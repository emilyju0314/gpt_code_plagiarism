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

        int minA = *min_element(a.begin(), a.end());
        int minB = *min_element(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            if (a[i] > minA && b[i] > minB) {
                cout << "0";
            } else {
                cout << "1";
            }
        }

        cout << endl;
    }

    return 0;
}