#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= a[i];
    }

    if (n % 2 == 0 && xr != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        if (n % 2 == 0) {
            cout << n - 1 << endl;
            for (int i = 0; i < n - 1; i++) {
                cout << 1 << " " << i + 2 << " " << i + 3 << endl;
            }
        } else {
            cout << n - 2 << endl;
            for (int i = 0; i < n - 2; i++) {
                cout << 1 << " " << i + 2 << " " << i + 3 << endl;
            }
            cout << 1 << " " << n - 1 << " " << n << endl;
        }
    }

    return 0;
}