#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;

        if (x1 * pow(10, p1) < x2 * pow(10, p2)) {
            cout << "<" << endl;
        } else if (x1 * pow(10, p1) > x2 * pow(10, p2)) {
            cout << ">" << endl;
        } else {
            cout << "=" << endl;
        }
    }

    return 0;
}