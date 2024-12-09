#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 0) {
        cout << -b*b << endl;
        for (int i = 0; i < b; i++) {
            cout << "x";
        }
    } else if (b == 0) {
        cout << a*a << endl;
        for (int i = 0; i < a; i++) {
            cout << "o";
        }
    } else if (a == b) {
        cout << a*a - b*b << endl;
        for (int i = 0; i < a; i++) {
            cout << "o";
            cout << "x";
        }
    } else if (a > b) {
        cout << a*a - b*b << endl;
        int extra = a - b;
        for (int i = 0; i < b; i++) {
            cout << "ox";
        }
        for (int i = 0; i < extra; i++) {
            cout << "o";
        }
    } else {
        cout << a*a - b*b << endl;
        int extra = b - a;
        for (int i = 0; i < a; i++) {
            cout << "xo";
        }
        for (int i = 0; i < extra; i++) {
            cout << "x";
        }
    }

    return 0;
}