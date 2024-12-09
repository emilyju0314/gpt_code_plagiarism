#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m == 0) {
        cout << 1 << endl;
    } else if (m == 1) {
        cout << 1 << endl;
    } else if (m > n / 2) {
        cout << n - m << endl;
    } else {
        cout << m << endl;
    }

    return 0;
}