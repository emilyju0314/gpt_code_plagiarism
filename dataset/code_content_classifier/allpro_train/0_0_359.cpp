#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] != c[i]) {
                p[i] = a[i];
            } else if (b[i] != a[i] && b[i] != c[i]) {
                p[i] = b[i];
            } else {
                p[i] = c[i];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}