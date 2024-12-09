#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;

        if (l1 == l2) {
            cout << "YES" << endl;
        } else if (l1 == l3) {
            cout << "YES" << endl;
        } else if (l2 == l3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}