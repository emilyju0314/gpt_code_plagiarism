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

    vector<int> b(n);
    int max_hats = 0;
    for (int i = 0; i < n; i++) {
        b[i] = a[i] + i;
        max_hats = max(max_hats, b[i]);
    }

    for (int i = 0; i < n; i++) {
        if (max_hats > n || b[i] <= 0 || b[i] > n) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}