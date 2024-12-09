#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    for (int k = 1; k <= 31; k++) {
        int x = n - k*p;
        if (x >= k && x % k == 0) {
            cout << k << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}