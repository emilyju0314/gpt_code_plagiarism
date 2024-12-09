#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 4 == 0 || n % 7 == 0 || n % 11 == 0) {
        cout << "4" << string(n / 4, '7') << endl;
    } else {
        for (int i = 1; i <= n/4; i++) {
            if ((n - 4 * i) % 7 == 0) {
                cout << string(i, '4') << string((n - 4 * i) / 7, '7') << endl;
                return 0;
            }
        }
        cout << "-1" << endl;
    }

    return 0;
}