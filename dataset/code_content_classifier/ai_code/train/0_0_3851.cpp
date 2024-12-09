#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
        for (int i = 5; i <= n; i++) {
            cout << "24 * " << i << " = " << 24*i << endl;
        }
    }

    return 0;
}