#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m == 3) {
        if (n < 4) {
            cout << "-1" << endl;
        } else {
            cout << "0 0" << endl;
            cout << "3 0" << endl;
            cout << "0 3" << endl;
            cout << "1 1" << endl;
        }
    } else {
        cout << "-1" << endl;
    }

    return 0;
}