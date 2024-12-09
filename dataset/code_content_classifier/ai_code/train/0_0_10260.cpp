#include <iostream>
using namespace std;

int main() {
    int a1, a2, a3, b1, b2, b3, n;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;

    // check if all the conditions can be fulfilled
    if ((a1 + a2 + a3 + 4) / 5 + (b1 + b2 + b3 + 9) / 10 <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}