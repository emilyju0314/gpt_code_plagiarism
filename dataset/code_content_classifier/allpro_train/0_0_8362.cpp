#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if(k >= n / 2) {
        cout << n * (n - 1) / 2 << endl;
    } else {
        cout << k * n << endl;
    }

    return 0;
}