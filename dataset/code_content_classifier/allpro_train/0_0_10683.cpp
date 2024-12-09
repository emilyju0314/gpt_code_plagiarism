#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n * (n - 1) / 2 <= k) {
        cout << "no solution" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << i << " " << i << endl; // generating points with same coordinates
        }
    }

    return 0;
}