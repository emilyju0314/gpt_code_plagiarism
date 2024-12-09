#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<int> a(n, 1);
    for (int i = 0; i < n; i++) {
        a[i] += l[i] + r[i];
        if (a[i] > n) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}