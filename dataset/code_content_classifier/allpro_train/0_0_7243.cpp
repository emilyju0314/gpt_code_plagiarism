#include <iostream>

using namespace std;

int main() {
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    if ((k1 % 2 == 0 && k2 % 2 == 0 && k3 % 2 == 0) || (k1 % 2 == 1 && k2 % 2 == 1 && k3 % 2 == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}