#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << n+1 << endl;

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << 1;
        } else {
            cout << "0";
        }
    }
    cout << endl;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j <= i) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }

    return 0;
}