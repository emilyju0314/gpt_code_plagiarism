#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n || k == 1) {
        cout << "-1" << endl;
    } else {
        cout << n - 1 << endl;
        for (int i = 1; i < n; i++) {
            cout << i << " " << i+1 << endl;
        }
    }

    return 0;
}