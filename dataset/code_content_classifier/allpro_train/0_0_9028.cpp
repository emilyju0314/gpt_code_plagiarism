#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 4 * (n / 2 + 1) << endl;
    } else {
        cout << (n / 2 + 1) * (n / 2 + 1) << endl;
    }

    return 0;
}