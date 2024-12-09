#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }

    vector<int> v(n+1); // to store values after each iteration

    // Calculate initial value of v
    for (int i = 0; i < n; i++) {
        v[i] = a[i] | a[i+1];
    }

    // Perform queries
    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
        a[p-1] = b;

        // Recalculate value of v after each query
        for (int j = 0; j < n; j++) {
            v[j] = a[j] | a[j+1];
        }

        // Print value of v after each query
        for (int j = 0; j < n; j++) {
            a[j] = v[j];
            v[j+1] = v[j] ^ v[j+1];
            cout << v[j] << " ";
        }
        cout << endl;
    }

    return 0;
}