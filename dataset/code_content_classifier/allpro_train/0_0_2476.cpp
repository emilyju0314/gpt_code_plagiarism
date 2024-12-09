#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if ((a == 0 && b == 0 && c == 0) || ((a == 0 || e == 0) && b == 0 && d == 0)) {
        cout << "Hermione" << endl;
    } else {
        if ((b == 0 || c == 0 || e == 0) && a == 0 && d != 0) {
            cout << "Hermione" << endl;
        } else {
            cout << "Ron" << endl;
        }
    }

    return 0;
}