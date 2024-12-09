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

        vector<int> a(n), b(n), m(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> m[i];
        }

        int minVariety = n;
        cout << minVariety << endl;

        for (int i = 0; i < n; i++) {
            cout << m[i] - min(a[i], m[i]) << " " << m[i] - max(0, m[i] - b[i]) << endl;
        }
    }

    return 0;
}