#include <iostream>
using namespace std;

int main() {
    long long s, x;
    cin >> s >> x;

    if ((s - x) % 2 != 0 || s < x) {
        cout << 0 << endl;
    } else {
        long long a = (s - x) / 2;
        long long b = s - a;

        if ((a ^ b) == x) {
            if (a != b) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}