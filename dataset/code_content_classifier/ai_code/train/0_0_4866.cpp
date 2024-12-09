#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, r;
        cin >> n >> r;

        if(n > r) {
            cout << (r * (r + 1) / 2) << endl;
        } else {
            cout << ((n * (n - 1) / 2) + 1) << endl;
        }
    }

    return 0;
}