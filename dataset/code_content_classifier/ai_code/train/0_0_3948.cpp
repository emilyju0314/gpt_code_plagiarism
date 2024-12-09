#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    vector<int> c(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i] | c[i];
    }

    for (int i = 0; i < n; i++) {
        if ((a[i] & b[i]) != b[i] || (a[i] & c[i]) != c[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}