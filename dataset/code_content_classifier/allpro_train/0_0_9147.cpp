#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n, -1);
    sort(a.begin(), a.end());

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    for (int i = 3; i < n; i++) {
        b[i] = -1;
    }

    for (int i = n - 1, j = 2; i >= 0 && a[i] > a[2]; i--) {
        if (b[i] == -1) {
            b[i] = 3;
            j--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}