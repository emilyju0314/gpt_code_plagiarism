#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;

        if (n % 3 == 0) {
            cout << a << endl;
        } else if (n % 3 == 1) {
            cout << b << endl;
        } else {
            cout << (a ^ b) << endl;
        }
    }

    return 0;
}